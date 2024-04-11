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
const long long int N=3e3+30;
pair<ll,bool> p[N];
pair<ll,ll> h[N];
int main(){
	ios_base::sync_with_stdio(false); cout.tie(0); cin.tie();
    ll n,m;
    cin >> n >> m;
    rep(i,0,2*n){
        cin >> p[i].X;
        p[i].Y = 0;
    }
    rep (i,0,m){
        ll x,y;
        cin >> x >> y;
        if (p[x-1].X > p[y-1].X) swap(x,y);
        h[i].X = x-1;
        h[i].Y = y-1;
       // debug(h[i].X);debug(h[i].Y);
    }
    ll t;
    cin >> t;
    if (t == 1){
        ll y;
        rep (j,0,n){
            ll x=-1;
            ll ind=-1;
            rep(i,0,m){
                if (!p[h[i].Y].Y){
                    if (p[h[i].Y].X > x){
                        x = p[h[i].Y].X;
                        ind = h[i].Y+1;
                    }
                }
            }
            if (ind != -1){
                p[ind-1].Y = 1;
                cout << ind << endl;
            }
            else{
                rep (i,0,2*n){
                   // debug(i); debug(p[i].X); debug(x);
                    if (!p[i].Y && p[i].X > x){

                        ind = i+1;
                        x = p[i].X;
                    }
                }
                p[ind-1].Y = 1;
                cout << ind << endl;
            }
            cin >> y;
            p[y-1].Y = 1;
        }
    }
    else{
        rep(j,0,n){
            ll y,x=-1,ind=-1;
            cin >> y;
            y--;
           // p[y].Y = 1;
            rep(i,0,m){
              //  debug(ind);
                if (!p[h[i].X].Y && !p[h[i].Y].Y && h[i].X == y){
                    ind = h[i].Y+1;
                }
                if (!p[h[i].Y].Y && !p[h[i].X].Y &&h[i].Y == y){
                    ind = h[i].X+1;
                }
            }
            p[y].Y = 1;
            if (ind != -1){
                cout << ind << endl;
                p[ind-1].Y = 1;
                continue;
            }
            rep (i,0,m){
                if (!p[h[i].Y].Y && p[h[i].Y].X >x){
                    x = p[h[i].Y].X;
                    ind = h[i].Y+1;
                }
            }
            if (ind != -1){
                cout << ind << endl;
                p[ind-1].Y = 1;
            }
            else{
                rep (i,0,2*n){
                    if (!p[i].Y  && p[i].X > x){
                        ind  = i+1;
                        x = p[i].X;
                    }
                }
                cout << ind << endl;
                p[ind-1].Y = 1;
            }

        }
    }
}