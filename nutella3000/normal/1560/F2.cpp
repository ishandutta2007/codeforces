#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) begin(a), end(a)
#define mp make_pair
#define pb emplace_back
#define ld long double
#define ull unsigned long long
mt19937 rnd;
 
const int inf = 1e15 + 3;
const int max_n = 1e5 + 3;

string f(string s, int k) {
    int n = size(s);
    string t;
    bool eq = true;
    set<int> used;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (i == 0 && j == 0) continue;
            if (!used.count(j) && size(used) == k) continue;

            if (eq && j < s[i] - '0') continue;

            if (eq && j == s[i] - '0') {
                bool was = used.count(j);
                used.insert(j);
                
                bool bad = false;
                int num = *used.rbegin();
                for (int q = i + 1; q < n; ++q) {
                    if (num > s[q] - '0') break;
                    if (num < s[q] - '0') bad = true;
                }

                if (size(used) < k || !bad) {
                    t += char('0' + j);
                    break;
                }
                if (!was) used.erase(j);
                continue;
            }
            eq = false;
            used.insert(j);
            t += char('0' + j);
            break;
        }
    }
    return t;
}

void run() {
    string s;
    int k;
    cin >> s >> k;
    cout << f(s, k) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(20);
 
#ifdef ahahaha
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}