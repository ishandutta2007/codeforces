#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll Mod=1000000007;
ll fp(ll a,ll k)
{
    ll res=1;
    while(k>0)
    {
        if(k&1)res=res*a%Mod;
        a=a*a%Mod;
        k>>=1;
    }
    return res;
}
char s[105];
int main()
{
    scanf("%s",s);
    int n=strlen(s);
    ll ans=0;
    for(int i=0;i<n;i++)
    {
        ans=(ans*2+(s[n-1-i]=='1' ? fp(2,2*i) : 0))%Mod;
    }
    printf("%I64d\n",ans);
    return 0;
}