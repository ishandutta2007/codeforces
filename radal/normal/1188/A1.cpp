#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("Ofast")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=1e6+30,mod = 1e9+7,inf=1e18;
bool a[N];
vector <vector<ll> > adj;
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    ll n;
    cin >> n;
    adj.resize(n);
    rep (i,0,n-1){
        ll x,y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    bool f=0;
    rep (i,0,n){
        if (adj[i].size() == 2) f = 1;
    }
    if (!f) cout << "YES";
    else cout << "NO";
    return 0;

}