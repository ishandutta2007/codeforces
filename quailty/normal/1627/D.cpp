#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
const int Mod=998244353;
inline int fp(int a,int k)
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
int a[MAXN],cnt[MAXN];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),cnt[a[i]]++;
    for(int i=1;i<MAXN;i++)
        for(int j=2*i;j<MAXN;j+=i)
            cnt[i]+=cnt[j];
    for(int i=1;i<MAXN;i++)
        cnt[i]=fp(2,cnt[i])-1;
    for(int i=MAXN-1;i>=1;i--)
        for(int j=2*i;j<MAXN;j+=i)
            cnt[i]=(cnt[i]-cnt[j]+Mod)%Mod;
    int res=0;
    for(int i=1;i<MAXN;i++)
        res+=(cnt[i]>0);
    return 0*printf("%d\n",res-n);
}