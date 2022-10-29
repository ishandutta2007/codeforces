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


int dp[201][6000];
long long a[200], b[200];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k;
    cin >> n >> k;
    // n = k = 200;

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        // a[i] = 1e18;
        long long x = a[i];
        while (x % 5 == 0) x /= 5, b[i]++;
    }

    for (int i = 0; i <= k; ++i) for (int j = 0; j < n*30; ++j) dp[i][j] = -1e9;
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        int x = __builtin_ctzll(a[i]);
        for (int j = k; j >= 1; --j) {
            for (int p = b[i]; p < n*30; ++p) {
                dp[j][p] = max(dp[j][p], dp[j - 1][p - b[i]] + x);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n*30; ++i) ans = max(ans, min(dp[k][i], i));
    
    cout << ans;

    return 0;
}