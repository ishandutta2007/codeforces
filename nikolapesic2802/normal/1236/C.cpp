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
    cin >> n;
    vector<vector<int> > groups(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            groups[j].pb(i*n+j+1);
        i++;
        if(i<n)
            for(int j=n-1;j>=0;j--)
                groups[j].pb(i*n+n-j);
    }
    for(int i=0;i<n;i++){
        for(auto p:groups[i])
            printf("%i ",p);
        printf("\n");
}
}