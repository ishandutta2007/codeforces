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

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t; cin >> t; while (t--) {
        int n; cin >> n;
        double C, T; cin >> C >> T;
        vector<ii> a(n);
        int sum = 0;
        FOR (i, 0, n - 1) cin >> a[i].F >> a[i].S, sum += a[i].S;
        sort(all(a)), reverse(all(a));
        vector<double> p9(n + 1);
        p9[0] = 1;
        FOR (i, 1, n) p9[i] = p9[i - 1] / 0.9;


        vector<vector<double>> dp(n + 1, vector<double>(sum + 1 + 1, 1e18));
        dp[0][0] = 0;
        sum = 0;
        FOR (i, 1, n) {
            int w = a[i - 1].S, t = a[i - 1].F;
            sum += w;
            NFOR (k, i, 1) {
                FOR (s, w, sum) {
                    dp[k][s] = min(dp[k][s], dp[k-1][s - w] + t * p9[k]);
                }
            }
        }

        int ans = 0;
        FOR (k, 1, n) {
            double t = T - k*10;
            double s = max(0.0, (C*t - 1)/2/C);
            if (t >= 0 and s <= t) {
                double at = (t-s)*(1+s*C);                
                FOR (s, 0, sum) if (dp[k][s] <= at + 1e-6) {
                    ans = max(ans, s);
                }
            }
        }
        cout << ans << "\n";
    }   
    
    return 0;
}