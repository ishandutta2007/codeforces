#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)


int solve(vector<ii> &a) {
    int n = sz(a);
    int ans = 0;
    vi L(41, -1);
    vi f(41, 0);
    int j = -1;
    FOR (i, 0, n - 1) {
        if (j == i - 1) {
            j = i;
            L[a[i].S] = a[i].F;
            f[a[i].S] = 1;
        }
        while (j + 1 < n) {
            int x = a[j+1].F, y = a[j+1].S;
            bool good = 1;
            FOR (it, 1, 40) if (L[it] != -1) {
                if((L[it] - x) % __gcd(y, it)) {
                    good = false;
                    break;
                }
            }
            if (good) {
                ++j;
                L[y] = x;
                ++f[y];
            }
            else break;
        }
        ans = max(ans, j - i + 1);
        f[a[i].S]--;
        if (f[a[i].S] == 0) L[a[i].S] = -1;
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m; cin >> n >> m;
    vector<vector<tuple<int,int,int>>> pos(m + 1);
    FOR (i, 0, n - 1) {
        int k; cin >> k;
        FOR (j, 0, k - 1) {
            int x; cin >> x;
            pos[x].emplace_back(i, j, k);
        }
    }

    FOR (i, 1, m) {
        int ans = 0;
        FOR (j, 0, sz(pos[i]) - 1) {
            int k = j; while (k + 1 < sz(pos[i]) and get<0>(pos[i][k+1]) == get<0>(pos[i][k])+1) ++k;
            vector<ii> yo;
            FOR (it, j, k) yo.emplace_back(get<1>(pos[i][it]), get<2>(pos[i][it]));
            ans = max(ans, solve(yo));
            j = k;
        }
        cout << ans << "\n";
    }

    return 0;
}