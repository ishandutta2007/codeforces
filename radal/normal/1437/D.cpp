#include <bits/stdc++.h>
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef pair <ll,ll>  pll;
const ll N = 2e5+20,inf = 1e10,mod=1e9+7;
ll a[N];
vector <pll> asc;
int main(){
    int T;
    cin >> T;
    while(T--){
        asc.clear();
        ll n,h=1;
        cin >> n;
        rep(i,0,n) {
            cin >> a[i];
        }
        if (n == 1){
            cout << 0 << endl; continue;
        }
        asc.pb({0,1});
        rep(i,1,n){
            int l = i;
            int r = i+1;
            while (r < n && a[r-1] < a[r]){
                r++;
            }
            asc.pb({l,r});
            i = r-1;
        }
        ll t = asc[1].Y-asc[1].X;
        ll s = asc.size(),p2=2;
        //debug(s);
        rep(i,2,s){
            ll p=p2;
            h++;
            if (p+t >= s) break;
            p2 += t;
            t=asc[p+t-1].Y-asc[p].X;
        }
        cout << h << endl;
    }
}