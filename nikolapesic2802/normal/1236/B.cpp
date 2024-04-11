#include <bits/stdc++.h>

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(x) x.begin(),x.end()
using namespace std;

const int mod=1e9+7;
int add(int a,int b)
{
a+=b;
if(a>=mod)
a-=mod;
return a;
}
int mul(int a,int b)
{
return (ll)a*b%mod;
}
int powmod(int x,int k)
{
    int ans=1;
    for(;k;k>>=1,x=mul(x,x))
    if(k&1)
    ans=mul(ans,x);
    return ans;
}
int main()
{
    int n,m;
    cin >> n >> m;
    int tr=powmod(2,m);
    tr--;
    int sol=powmod(tr,n);
    printf("%i\n",sol);

}