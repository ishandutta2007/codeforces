#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
using ld = long double;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 1e3 + 5;

int n, p;
string s;

string dp[N];
bool done[N];

bool check_suf(int i, char ch, const string &str) {
    if (i - 1 >= 0 and ch == str[i - 1])
        return false;
    if (i - 2 >= 0 and ch == str[i - 2])
        return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> p;
    cin >> s;

    for (int i = 0; i < n; i++) {
        dp[i] = s.substr(0, i + 1);

        for (char ch = s[i] + 1; ch <= 'a' + p - 1; ch++) {
            if (check_suf(i, ch, s)) {
                dp[i].pop_back();
                dp[i] += ch;
                done[i] = true;
                break;
            }
        }

        if (i == 0 or done[i] or !done[i - 1]) continue;
        for (char ch = 'a'; ch <= 'a' + p - 1; ch++) {
            if (check_suf(i, ch, dp[i - 1])) {
                dp[i] = dp[i - 1];
                dp[i] += ch;
                done[i] = true;
                break;
            }
        }
    }

//    for (int i = 0; i < n; i++)
//        cout << dp[i] << "\n";

    if (dp[n - 1] <= s)
        cout << "NO\n";
    else cout << dp[n - 1] << "\n";
    return 0;
}