#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN=500005;
const ll Mod=1000000007LL;
char s[MAXN];
int main()
{
    int n,h,w;
    scanf("%d%d%d%s",&n,&h,&w,s+1);
    ll res=0,x[2]={1,h},y[2]={1,w};
    for(int i=1;i<=n && x[0]<=x[1] && y[0]<=y[1];i++)
    {
        if(s[i]=='U')x[0]--,x[1]--;
        if(s[i]=='D')x[0]++,x[1]++;
        if(s[i]=='L')y[0]--,y[1]--;
        if(s[i]=='R')y[0]++,y[1]++;
        if(x[0]<1)res=(res+(y[1]-y[0]+1)*i)%Mod,x[0]++;
        if(x[1]>h)res=(res+(y[1]-y[0]+1)*i)%Mod,x[1]--;
        if(y[0]<1)res=(res+(x[1]-x[0]+1)*i)%Mod,y[0]++;
        if(y[1]>w)res=(res+(x[1]-x[0]+1)*i)%Mod,y[1]--;
    }
    if(x[0]>x[1] || y[0]>y[1])return 0*printf("%I64d",res);
    ll d[2]={0,0};
    vector<ll>v;
    for(int i=1;i<=n && x[0]<=x[1] && y[0]<=y[1];i++)
    {
        if(s[i]=='U')x[0]--,x[1]--,d[0]--;
        if(s[i]=='D')x[0]++,x[1]++,d[0]++;
        if(s[i]=='L')y[0]--,y[1]--,d[1]--;
        if(s[i]=='R')y[0]++,y[1]++,d[1]++;
        if(x[0]<1)res=(res+(y[1]-y[0]+1)*(n+i))%Mod,x[0]++,v.push_back(i);
        if(x[1]>h)res=(res+(y[1]-y[0]+1)*(n+i))%Mod,x[1]--,v.push_back(i);
        if(y[0]<1)res=(res+(x[1]-x[0]+1)*(n+i))%Mod,y[0]++,v.push_back(-i);
        if(y[1]>w)res=(res+(x[1]-x[0]+1)*(n+i))%Mod,y[1]--,v.push_back(-i);
    }
    if(x[0]>x[1] || y[0]>y[1])return 0*printf("%I64d",res);
    if(d[0]==0 && d[1]==0)return 0*printf("-1");
    d[0]=x[1]-x[0]+1,d[1]=y[1]-y[0]+1;
    for(ll _=2;;_++)
        for(int i=0;i<(int)v.size();i++)
        {
            if(v[i]>0)res=(res+d[1]*(_*n+abs(v[i])))%Mod,d[0]--;
            else res=(res+d[0]*(_*n+abs(v[i])))%Mod,d[1]--;
            if(!d[0] || !d[1])return 0*printf("%I64d",res);
        }
}