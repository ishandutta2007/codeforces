#include "bits/stdc++.h"
using namespace std;
 
template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;
 
#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 2e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
 
void solve(){
    int n; cin >> n;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            if (i&1) cout << (1ll<<(i+j)) << ' ';
            else cout << 0 << ' ';
        cout << '\n';
    }
    cout.flush();
    int q; cin >> q;
    while (q--){
        ll k; cin >> k;

        int i=0, j=0;
        while (i != n-1 || j != n-1){
            cout << i+1 << ' ' << j+1 << '\n';

            int ni1=i+1, nj1=j, ni2=i, nj2=j+1;
            if (bool(k&(1ll<<(ni1+nj1))) == (ni1&1)) i=ni1, j=nj1;
            else i=ni2, j=nj2;
        }
        cout << n << ' ' << n << endl;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}