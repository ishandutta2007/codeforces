#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
const int MAXN=100005;
const int MAXL=2000005;
const int CNT=2;
char s[MAXL],t[MAXN];
ll p[CNT],q[CNT];
bool isPrime(ll x)
{
    for(ll i=2;i*i<=x;i++)
        if(x%i==0)return 0;
    return 1;
}
void build()
{
    srand(time(NULL));
    ll la=128;
    for(int i=0;i<=CNT;i++)
    {
        p[i]=la+rand()%64;
        while(!isPrime(p[i]))p[i]++;
        la=p[i]+1;
    }
    random_shuffle(p,p+CNT+1);
    la=1000000000;
    for(int i=0;i<CNT;i++)
    {
        q[i]=la+rand()%32768;
        while(!isPrime(q[i]))q[i]++;
        la=q[i]+1;
    }
    random_shuffle(q,q+CNT);
}
map<ll,int>mp;
int usd[MAXN];
vector<int>res;
void ok()
{
    printf("YES\n");
    for(int i=0;i<(int)res.size();i++)
        printf("%d ",res[i]);
    exit(0);
}
ll getHash(char s[],int len)
{
    ll has[2]={0,0};
    for(int i=0;i<len;i++)
        for(int j=0;j<2;j++)
            has[j]=(has[j]*p[j]+s[i])%q[j];
    return has[0]*q[0]+has[1];
}
ll h[CNT][MAXL],pw[CNT][MAXL];
void prepare(int len)
{
    for(int i=0;i<2;i++)
        for(int j=(pw[i][0]=1);j<len;j++)
            pw[i][j]=p[i]*pw[i][j-1]%q[i];
    ll has[2]={0,0};
    for(int i=0;i<len;i++)
        for(int j=0;j<2;j++)
            h[j][i]=has[j]=(has[j]*p[j]+s[i])%q[j];
}
ll getHash(int l,int r)
{
    ll has[2];
    for(int i=0;i<2;i++)
        has[i]=(h[i][r]-(l>0 ? h[i][l-1] : 0)*pw[i][r-l+1]%q[i]+q[i])%q[i];
    return has[0]*q[0]+has[1];
}
int main()
{
    build();
    int n,k,g;
    scanf("%d%d%s%d",&n,&k,s,&g);
    for(int i=0,len=n*k;i<len;i++)
        s[i+len]=s[i];
    prepare(2*n*k);
    for(int i=1;i<=g;i++)
    {
        scanf("%s",t);
        mp[getHash(t,k)]=i;
    }
    for(int i=0;i<k;i++)
    {
        res.clear();
        for(int j=0;j<n;j++)
        {
            ll t=getHash(j*k+i,(j+1)*k+i-1);
            if(mp.find(t)==mp.end() || usd[mp[t]])break;
            usd[mp[t]]=1;
            res.push_back(mp[t]);
            if(j==n-1)ok();
        }
        for(int j=0;j<(int)res.size();j++)
            usd[res[j]]=0;
    }
    return 0*printf("NO");
}