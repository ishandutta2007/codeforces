#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int N = 1e5 + 10;
int f[N], a[N];
ll dp[2][N];
int L, R;
ll cur;

inline ll cost(int i, int j) {
    while (R < j) cur += f[a[++R]]++;
    while (L > i) cur += f[a[--L]]++;
    while (R > j) cur -= --f[a[R--]];
    while (L < i) cur -= --f[a[L++]];
    return cur;
}

void solve(int now, int l, int r, int st, int en) {
    if (l > r) return;
    int mid = (l + r) >> 1;
    int pos = -1;
    ll &ans = dp[now][mid];
    ans = 1e18;
    FOR (i, st, min(en, mid)) {
        ll here = dp[!now][i - 1] + cost(i, mid);
        if (here < ans) {
            pos = i, ans = here;
        }
    }
    solve(now, l, mid - 1, st, pos);
    solve(now, mid + 1, r, pos, en);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k; cin >> n >> k;
    FOR (i, 1, n) cin >> a[i];

    L = R = 1, cur = 0, f[a[1]] = 1;

    FOR (i, 1, n) dp[0][i] = cost(1, i);
    dp[0][0] = dp[1][0] = 1e18;

    FOR (i, 1, k - 1) {
        solve(i & 1, 1, n, 1, n);
    }
    cout << dp[(k - 1) & 1][n];

    return 0;
}