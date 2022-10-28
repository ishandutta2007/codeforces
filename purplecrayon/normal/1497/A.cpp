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
const int MAXN = 5e3+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 1e9+7, MAXK = 17, INF = 1e9+10, MAXA = 30, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

int cnt[110];
void solve(){
    int n; cin >> n;
    vector<int> a(n); for (auto& it : a) cin >> it;
    memset(cnt, 0, sizeof(cnt));
    for (auto& it : a) cnt[it]++;

    for (int c=0; cnt[c]; cnt[c]--, c++) {
        cout << c << ' ';
    }
    for (int c = 0; c < 110; c++) while (cnt[c]--) cout << c << ' ';
    cout << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    cin >> t_c;
    while (t_c--) solve();
}