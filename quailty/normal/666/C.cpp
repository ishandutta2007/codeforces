#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<ctime>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=100005;
const int Mod=1000000007;
char s[MAXN];
#define ft first
#define sd second
pair<pair<int,int>,int>p[MAXN];
int fac[MAXN],inv[MAXN],tmp[MAXN],res[MAXN];
int fp(int a,int k)
{
    if(k<0)a=fp(a,Mod-2),k=-k;
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
int C(int n,int k)
{
    if(k>n)return 0;
    return 1LL*fac[n]*inv[k]%Mod*inv[n-k]%Mod;
}
void build()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    for(int i=0;i<MAXN;i++)
        inv[i]=fp(fac[i],Mod-2);
}
int main()
{
    build();
    int m;
    scanf("%d%s",&m,s);
    int n=strlen(s),q=0;
    while(m--)
    {
        int t;
        scanf("%d",&t);
        if(t==1)
        {
            scanf("%s",s);
            n=strlen(s);
        }
        else
        {
            p[q].ft.ft=n;
            scanf("%d",&p[q].ft.sd);
            p[q].sd=q;
            q++;
        }
    }
    sort(p,p+q);
    int inv26=fp(26,-1);
    for(int i=(n=0);i<q;i++)
    {
        if(n!=p[i].ft.ft)
        {
            n=p[i].ft.ft;
            int now25=fp(25,-n),now26=1;
            for(int j=1;j<MAXN;j++)
            {
                now25=25LL*now25%Mod;
                now26=1LL*inv26*now26%Mod;
                tmp[j]=(tmp[j-1]+1LL*C(j-1,n-1)*now25%Mod*now26%Mod)%Mod;
            }
        }
        res[p[i].sd]=1LL*fp(26,p[i].ft.sd)*tmp[p[i].ft.sd]%Mod;
    }
    for(int i=0;i<q;i++)
        printf("%d\n",res[i]);
    return 0;
}