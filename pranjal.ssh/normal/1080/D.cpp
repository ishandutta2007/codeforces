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
        ll n, k; cin >> n >> k;
        if (2*n <= 62 and k > ((1LL<<(2*n))-1)/3) {
            cout << "NO\n";
            continue;
        }
        if (k == 3 and n <= 2) {
            cout << "NO\n";
            continue;
        }

        ll sum = 0;
        FOR (i, 0, 30) {
            sum += (1LL << (2*i));
            if (sum > k) {
                sum -= (1LL << (2*i));
                if (sum + (2LL<<i) - 1 <= k) cout << "YES " << n - i - 1 << "\n";
                else cout << "YES " << n - i << "\n";
                break;
            }
        }
    }   
    
    return 0;
}