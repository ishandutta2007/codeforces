#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (ll i=l; i<r; i++)
#define repr(i,r,l) for (ll i=r; i>=l; i--)
using namespace std;
const long long int N=1e3+30;
vector <vector<ll> > adj;
bool visited[N];
void dfs(ll v){
  //  cout << v << ' ' ; 
    visited[v] = 1;
    for (ll u : adj[v]){
        if (!visited[u]){
            dfs(u);
        }
    }
}
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
    ll n,ind=-1;
    cin >> n;
    adj.resize(n+50);
    pair <ll,ll> p[n+50];
    while (n--){
        ll a,b;
        ll t;
        cin >> t >> a >> b;
        if (t == 1){
            ind++;
            p[ind].X = a;
            p[ind].Y = b;
            rep (i,0,ind){
           //     debug(p[i].X); debug(p[i].Y);
                if ((p[ind].X > p[i].X && p[ind].X < p[i].Y) || (p[ind].Y > p[i].X && p[ind].Y < p[i].Y)){
                    adj[ind].pb(i);
             //       debug(ind);
               //     debug(i);
                }
                if ((p[ind].X < p[i].X && p[i].X < p[ind].Y) || (p[ind].Y > p[i].Y && p[ind].X < p[i].Y)){
                    adj[i].pb(ind);
                    //debug(i);debug(ind);
                }
            }
        }
        else{
            rep (i,0,N) visited[i] = 0;
            dfs(a-1);
            if (visited[b-1]) cout << "YES" << endl; else cout << "NO" << endl;
           // rep (i,0,ind){
            //    for (int u: adj[i]){
          //          cout << u << ' ';
             //   }
            //    cout << endl;
           // }
        }
    }
    return 0;
}