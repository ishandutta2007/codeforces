#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define ll long long int 
#define rep(i,l,r) for(int i=l; i<r; i++)
#define repr(i,r,l) for(int i=r; i>=l; --i)
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << ": " << x << endl;
#define X first
#define Y second
#define mp make_pair
using namespace std; 
const long long int N=3e5+30,inf = 1e18;
ll a[N];
pair <ll,ll> seg[N];
vector <ll> ind[N];
int main(){
	ios_base::sync_with_stdio(false);	cout.tie(0); cin.tie(0);
    ll T;
    cin >> T;
    while (T--){
        ll n;
        cin >> n;
        rep (i,0,N){
            ind[i].clear();
            seg[i].X = inf;
        }
        rep (i,1,n+1){
            cin >> a[i];
            ind[a[i]].pb(i);
        }
        rep(i,1,n+1){
            if (ind[i].empty()) continue;
            seg[i].X = max(ind[i].front(),n-ind[i].back()+1);
            ll sz = ind[i].size();
            rep (j,1,sz){
                seg[i].X = max(seg[i].X,ind[i][j]-ind[i][j-1]);
            }
            seg[i].Y = ind[i].back();
        }
       // debug(seg[2].Y);
        sort(seg+1,seg+n+1);
        ll p = -1,p1=1;
        rep (i,1,n+1){
            while (p1 <= n && seg[p1].X == i){
         //       if (i == 5) debug(a[seg[2].Y]);
                if (p == -1 || p > a[seg[p1].Y]) p = a[seg[p1].Y];
                p1++;
            }
           // debug(i);
            cout << p << ' ';
        }
        cout << endl;
    }
    return 0;
}