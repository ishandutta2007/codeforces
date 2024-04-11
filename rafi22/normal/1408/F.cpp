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

const bool multi=0;
vector<pair<int,int>>res;
void Merge(int l,int r,int l1,int r1)
{
    if(l>r||l1>r1) return;
    for(;l<=r;l++,l1++) res.pb({l,l1});
}
void Assign(int l,int r)
{
    if(l==r) return;
    Assign(l,(l+r)/2);
    Assign((l+r)/2+1,r);
    Merge(l,(l+r)/2,(l+r)/2+1,r);
}

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
        int n,pot=1;
        cin>>n;
        while(pot<=n) pot*=2;
        pot/=2;
        Assign(1,pot);
        Assign(n-pot+1,n);
        cout<<sz(res)<<endl;
        for(auto x:res) cout<<x.st<<" "<<x.nd<<endl;
    }

    return 0;
}