#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll i=0; i<t; i++)
#define FOR(i, s, e) for(ll i=s; i<=e; i++)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef short int si;

int main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    pair<ll, ll> low, up;
    low.p1=(low.p2=1e10);
    up.p1=(up.p2=-(1e10));
    rep(i, n){
        ll x, y;
        cin>>x>>y;
        low.p1=min(low.p1, x);
        low.p2=min(low.p2, y);
        up.p1=max(up.p1, x);
        up.p2=max(up.p2, y);
    }
    cout<<max((up.p1-low.p1),(up.p2-low.p2))*max((up.p1-low.p1),(up.p2-low.p2))<<endl;
    return 0;
}