#include <bits/stdc++.h>

#define int long long
#define double long double
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define sz(x) (int)(x).size()
using namespace std;
double PI=3.14159265359;
int inf=1000000000000000007;
int mod=1000000007;
int mod1=998244353;

const bool multi=1;
int pot(int x,int p) {int res=1;for(;p;p>>=1) {if(p&1) res=res*x%mod; x=x*x%mod;} return res;}
int silnia[1007];
int dwumian(int n, int k){ return (silnia[n]*pot(silnia[k]*silnia[n-k]%mod,mod-2))%mod;}


int cnt[1007];
int a[1007];

signed main()
{
    silnia[0]=1;
    for(int i=1;i<=1000;i++) silnia[i]=silnia[i-1]*i%mod;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tt;
    if(multi)
        cin>>tt;
    else tt=1;
    while(tt--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+n+1,greater<int>());
        int l=k,r=k;
        while(l>1&&a[l-1]==a[l]) l--;
        while(r<n&&a[r+1]==a[r]) r++;
        cout<<dwumian(r-l+1,k-l+1)<<endl;
    }

    return 0;
}