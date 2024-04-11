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
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}

const int N = 2e4 + 10;
int a[N], P[N], pos[101];
int dp[55][N];



int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, k, p; cin >> n >> k >> p;
    FOR (i, 1, n) {
        cin >> a[i];
        a[i] %= p;
        P[i] = (P[i-1] + a[i]) % p;
    }

    FOR (i, 1, n) dp[1][i] = P[i];

    FOR (i, 2, k) {
        memset(pos, -1, sizeof pos);
        FOR (j, 1, n) {
            FOR (it, 0, p - 1) if (pos[it] != -1) {
                int val = P[j] - it;
                if (val < 0) val += p;
                dp[i][j] = max(dp[i][j], dp[i-1][pos[it]] + val);
            }
            pos[P[j]] = j;
        }
    }
    cout << dp[k][n] << "\n";


    return 0;
}