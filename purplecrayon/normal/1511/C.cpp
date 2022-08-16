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
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};
const ll INF = 1e18+10;
 
int n, q;
int pos[51];

void solve(){
    cin >> n >> q;
    memset(pos, -1, sizeof(pos));
    for (int i = 0; i < n; i++) {
        int a; cin >> a;
        if (pos[a] == -1) pos[a] = i;
    }
    while (q--) {
        int c; cin >> c;
        cout << pos[c]+1 << ' ';
        for (int i = 1; i <= 50; i++) if (pos[c] > pos[i]) pos[i]++;
        pos[c] = 0;
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}