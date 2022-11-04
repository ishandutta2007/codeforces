#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
const ll bas=1000000000;

inline void divide(vector<ll>&a,ll b)
{
    if(b==1)return;
    for(int i=(int)a.size()-1;i>=0;i--)
    {
        if(i)a[i-1]+=a[i]%b*bas;
        a[i]/=b;
    }
    for(int i=0;i<(int)a.size()-1;i++)
    {
        a[i+1]+=a[i]/bas;
        a[i]%=bas;
    }
    while(!a.empty() && a.back()==0)a.pop_back();
}
inline ll mod(vector<ll>&a,ll b)
{
    if(b==1)return 0;
    ll res=0;
    for(int i=(int)a.size()-1;i>=0;i--)
        res=(res*bas+a[i])%b;
    return res;
}

const int MAXN=300005;
const int Mod=1000000007;

inline int add(int x,int y)
{
    if((x+=y)>=Mod)x-=Mod;
    return (x<0 ? x+Mod : x);
}

int a[MAXN],b[MAXN],dp[2][MAXN];
char str[10005];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++)
        scanf("%d",&a[i]);
    a[n]=1;
    for(int i=1;i<=n;i++)
        scanf("%d",&b[i]);
    scanf("%s",str);
    int len=strlen(str);
    ll tmp=0,pw=1;
    vector<ll>m;
    for(int i=len-1,j=-1;i>=0;i--,j=(j+1)%9)
    {
        if(j==8)m.push_back(tmp),tmp=0,pw=1;
        tmp+=(str[i]-'0')*pw,pw*=10;
    }
    if(tmp)m.push_back(tmp);
    int now=0,la=1,mx=0;
    dp[now][0]=1;
    for(int i=1;i<=n;i++)
    {
        swap(now,la);
        for(int j=mx+1;j<=mx+b[i];j++)
            dp[la][j]=0;
        mx+=b[i];
        for(int j=1;j<=mx;j++)
            dp[la][j]=add(dp[la][j],dp[la][j-1]);
        for(int j=0;j<=mx;j++)
            dp[now][j]=add(dp[la][j],-(j-b[i]>0 ? dp[la][j-b[i]-1] : 0));
        int cnt=0;
        for(int j=mod(m,a[i]);j<=mx;j+=a[i])
            dp[now][cnt++]=dp[now][j];
        for(int j=cnt;j<=mx;j++)
            dp[now][j]=0;
        divide(m,a[i]);
        mx=cnt-1;
    }
    if(m.size()>1)printf("0");
    else
    {
        ll tmp=mod(m,bas);
        printf("%d",(tmp<=mx ? dp[now][tmp] : 0));
    }
    return 0;
}