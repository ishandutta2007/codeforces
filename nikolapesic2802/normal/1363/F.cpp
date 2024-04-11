#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
//#pragma GCC target("avx2")

#define deb(x) cout << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define len(x) (int) x.size()
#define lsb(x) (x) & -(x)
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2

#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound

using namespace std;
// using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ld, ld> pld;
typedef pair <ll, ll> pll;

//template <class T1, class T2 = less <T1>> using pb_heap = __gnu_pbds::priority_queue <T1, T2, binary_heap_tag>;
//template <class T1, class T2 = null_type, class T3 = less <T1>> using pb_map = tree <T1, T2, T3, rb_tree_tag, tree_order_statistics_node_update>;
//template <class T1, class T2 = null_type, class T3 = hash <T1>> using pb_umap = gp_hash_table <T1, T2, T3>;
template <class T1, class T2, class T3 = hash <T1>> using umap = unordered_map <T1, T2, T3>;
template <class T> using uset = unordered_set <T>;
template <class T> using vec = vector <T>;

const ll infll = numeric_limits <ll>::max() >> 1;
const int inf = numeric_limits <int>::max() >> 1;
const int N = 2005;
const int L = 26;
int n, tc;
int dp[N][N];

int cnt[N][L];
int cns[N][L];

string t;
string s;

void input() {
    cin >> n;
    cin >> s;
    cin >> t;
    s = '#' + s;
    t = '#' + t;
    for(int i = 0; i < L; ++i) {
        cnt[n + 1][i] = 0;
        cns[n + 1][i] = 0;
    }
    for(int i = n; i >= 1; --i) {
        for(int j = 0; j < L; ++j) {
            cnt[i][j] = cnt[i + 1][j];
        }
        cnt[i][t[i] - 'a']++;
    }
    for(int i = n; i >= 1; --i) {
        for(int j = 0; j < L; ++j) {
            cns[i][j] = cns[i + 1][j];
        }
        cns[i][s[i] - 'a']++;
    }
}

string sorted(string str) {
    sort(all(str));
    return str;
}

int calc(int i, int j) {
    if(i == -1 && j == -1) {
        return 0;
    }
    if(dp[i][j] != -1) {
        return dp[i][j];
    }
    if(t[i] == s[j]) {
        return dp[i][j] = calc(i - 1, j - 1);
    }
    int res = inf;
    int c = cns[j + 1][t[i] - 'a'] - cnt[i + 1][t[i] - 'a'];
    if(c >= 1) {
        res = min(res, calc(i - 1, j));
    }
    if(j) {
        res = min(res, calc(i, j - 1) + 1);
    }
    return dp[i][j] = res;
}

void solve() {
    if(sorted(s) != sorted(t)) {
        cout << "-1\n";
        return;
    }
    memset(dp, -1, sizeof dp);
    cout << calc(n, n) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> tc;
    while(tc--) {
        input();
        solve();
    }
}