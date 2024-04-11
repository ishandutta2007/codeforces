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
const int N = 1e5 + 3;
int n;
vector<pii> gr[N];

void run() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        gr[i].clear();

    for (int i = 0; i < n-1; ++i) {
        int v1, v2; cin >> v1 >> v2; --v1, --v2;
        gr[v1].pb(v2, i), gr[v2].pb(v1, i);
    }
    for (int i = 0; i < n; ++i)
        if (size(gr[i]) > 2) { cout << -1 << '\n'; return; }
    for (int st = 0; st < n; ++st) {
        if (size(gr[st]) != 1) continue;
        
        int v = st, pr = -1, prnum=1;
        vector<int> res(n-1);

        while (pr == -1 || size(gr[v]) > 1) {
            for (auto to : gr[v]) {
                if (to.fi == pr) continue;
                res[to.se] = 2 + (prnum = 1-prnum);
                pr = v, v = to.fi;
                break;
            }
        }
        for (auto i : res)
            cout << i << " ";
        cout << endl;
        return;
    }
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