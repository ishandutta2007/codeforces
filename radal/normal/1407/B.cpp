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
const int N=1e5+10;
ll GCD (ll a,ll b){
    if (b > a) swap (a,b);
    if (!b) return a;
    return GCD(b,a%b);
}
int main(){
    ll T;
    cin >> T;
    while (T--){
        ll n,ma=0;
        int j;
        cin >> n;
        list <ll> a;
        vector <ll> c,b;
        rep (i,0,n){
            ll x;
            cin >> x;
            a.pb(x);
            if (x > ma){
                ma = x;
                j = i;
            }
        }
        c.pb(ma);
        b.pb(ma);
        list <ll>::iterator it;
        it = a.begin();
        advance(it,j);
        a.erase(it);
        while (a.size()){
            list <ll>::iterator it2;
            ll C=0;
            for (it=a.begin(); it != a.end(); ++it){
                ll G = GCD(c.back(),*it);
                if (G > C){
                    C = G;
                    it2 = it;
                }
            }
            c.pb(C);
            b.pb(*it2);
            a.erase(it2);
        }
        rep (i,0,n){
            cout << b[i] << " ";
        }
        cout << endl;
    }
    return 0;
}