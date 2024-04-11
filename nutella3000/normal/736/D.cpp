#include <bits/stdc++.h>
using namespace std;
    
//#define _GLIBCXX_DEBUG
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back
#define ld long double
   
mt19937 rnd;
int rand(int a) { return (rnd() % a + a) % a; }
 
const int inf = 1e9 + 2;
const int max_n = 2e3 + 3;

bool gauss(vector<bitset<2 * max_n>> &A) {
    int n = size(A), id = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = id; j < n; ++j) {
            if (A[j][i]) {
                swap(A[j], A[id]);
                break;
            }
        }
        if (!A[id][i]) continue;
        for (int j = 0; j < n; ++j) {
            if (j == id || !A[j][i]) continue;
            A[j] ^= A[id];
        }
        ++id;
    }
    return true;
}

void run() {
    int n, m;
    cin >> n >> m;

    vector<bitset<2 * max_n>> A(n);
    vector<pii> ed(m);
    for (int i = 0; i < m; ++i) {
        cin >> ed[i].fi >> ed[i].se;
        --ed[i].fi, --ed[i].se;
        A[ed[i].fi][ed[i].se] = 1;
    }
    for (int i = 0; i < n; ++i)
        A[i][i + n] = 1;
    gauss(A);

    for (int i = 0; i < m; ++i) {
        cout << (A[ed[i].se][ed[i].fi + n] ? "NO" : "YES") << endl;
    }
}
 
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(6);
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    clock_t time = clock();
    int t = 1;
    //cin >> t;
    while(t--) run();

}