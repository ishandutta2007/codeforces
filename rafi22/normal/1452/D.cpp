#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=0;

int modexp(int x, int n)
{
    if (n == 0) {
        return 1;
    }
    else if (n % 2 == 0) {
        return modexp((x * x) % mod1, n / 2);
    }
    else {
        return (x * modexp((x * x) % mod1, (n - 1) / 2) % mod1);
    }
}
int getFractionModulo(int a, int b)
{
    int d = modexp(b, mod1 - 2);
    int ans = ((a % mod1) * (d % mod1)) % mod1;
    return ans;
}

int pot[200007];
int fib[200007];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,it;
        cin>>n;
        pot[0]=1;
        for(int i=1;i<=200000;i++) pot[i]=pot[i-1]*2%mod1;
        fib[1]=1;
        for(int i=2;i<=200000;i++) fib[i]=(fib[i-1]+fib[i-2])%mod1;
        int l=fib[n],m=pot[n];
        cout<<getFractionModulo(l,m)<<endl;
    }
    return 0;
}