#include<bits/stdc++.h>
using namespace std;
 
#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld double
#define vi vector<int>
#define vvi vector<vector<int>>
bool chmin(int& a, int b){ if(a > b){ a = b; return 1; } return 0; }
bool chmax(int& a, int b){ if(a < b){ a = b; return 1; } return 0; }

mt19937 Rand(time(0));
int rnd(int a) { return Rand() % a; }
int rnd(int a, int b) { return Rand() % (b - a + 1) + a; }
ld rnd_01d() { return (ld)Rand() / (1ll<<32); }
ld rnd_d(ld r) { return rnd_01d() * r; }

const int inf = 1e18 + 7, mod = 998244353;


void run() {
    int n, m; cin >> n >> m;
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            d.pb(max(i, n-1-i)+max(j, m-1-j));
        }
    }
    sort(all(d));
    for (int i = 0; i < n*m; ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}

signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);
    cout.precision(20);
    //auto time = clock();
    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
    //cout << ((double) clock() - time) / CLOCKS_PER_SEC << endl;
}