#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=1000000007;
inline void add(int &x,int y)
{
    (x+=y)>=Mod && (x-=Mod);
}
int fac[MAXN],inv[MAXN];
int fp(int a,int k)
{
    int res=1;
    while(k)
    {
        if(k&1)res=1LL*res*a%Mod;
        a=1LL*a*a%Mod;
        k>>=1;
    }
    return res;
}
char a[MAXN],b[MAXN];
int cnt[35];
int dfs(int now,int dw,int up,int way,int n)
{
    if(dw==0 && up==0)return way;
    if(now==n)return 0;
    int res=0;
    for(int i=(dw ? a[now]-'a' : 0);i<=(up ? b[now]-'a' : 25);i++)if(cnt[i])
    {
        int tway=1LL*way*inv[n-now]%Mod*fac[n-now-1]%Mod*fac[cnt[i]]%Mod*inv[cnt[i]-1]%Mod;
        cnt[i]--,add(res,dfs(now+1,(dw && i==a[now]-'a'),(up && i==b[now]-'a'),tway,n)),cnt[i]++;
    }
    return res;
}
int main()
{
    for(int i=(fac[0]=1);i<MAXN;i++)
        fac[i]=1LL*i*fac[i-1]%Mod;
    inv[MAXN-1]=fp(fac[MAXN-1],Mod-2);
    for(int i=MAXN-2;i>=0;i--)
        inv[i]=1LL*(i+1)*inv[i+1]%Mod;
    scanf("%s%s",a,b);
    int n=strlen(a);
    for(int i=0;i<n;i++)
        cnt[a[i]-'a']++;
    int way=fac[n];
    for(int i=0;i<26;i++)
        way=1LL*way*inv[cnt[i]]%Mod;
    printf("%d\n",dfs(0,1,1,way,n));
    return 0;
}