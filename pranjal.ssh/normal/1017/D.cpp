#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}



int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m, q; cin >> n >> m >> q;
    vi w(n); FOR (i, 0, n - 1) cin >> w[i];

    int N = 1 << n;
    int dp[N][101]; memset(dp, 0, sizeof dp);
    int cost[N]; memset(cost, 0, sizeof cost);
    int f[N]; memset(f, 0, sizeof f);

    FOR (i, 0, N - 1) {
        FOR (j, 0, n - 1) if (!(i & (1 << j))) {
            cost[i] += w[j];
        }
    }

    FOR (i, 0, m - 1) {
        string s; cin >> s; reverse(all(s));
        f[stoi(s, 0, 2)]++;
    }
    
    FOR (i, 0, N-1) {
        FOR (j, 0, N-1) {
            int k = cost[i ^ j];
            if (k <= 100) {
                dp[i][k] += f[j];
            }
        }
    }
    

    FOR (i, 0, q - 1) {
        string s; cin >> s; reverse(all(s));
        int x = stoi(s, 0, 2);
        int k; cin >> k;
        int ans = 0;
        FOR (i, 0, k) ans += dp[x][i];
        cout << ans << "\n";
    }



    return 0;
}