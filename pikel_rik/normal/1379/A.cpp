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

string req = "abacaba";

int check1(const string& s) {
    int c = 0;
    for (int i = 0; i + 7 <= s.length(); i++) {
        bool ok = true;
        for (int j = 0; j < 7; j++) {
            if (s[i + j] == req[j])
                continue;
            ok = false;
        }
        c += ok;
    }
    return c;
}

int check2(const string& s) {
    int c = 0;
    for (int i = 0; i + 7 <= s.length(); i++) {
        bool ok = true;
        for (int j = 0; j < 7; j++) {
            if (s[i + j] == req[j] or s[i + j] == '?')
                continue;
            ok = false;
        }
        c += ok;
    }
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int c1 = check1(s), c2 = check2(s);
        if (c1 > 1 or c1 + c2 == 0) {
            cout << "No\n";
            continue;
        }

        if (c1 == 1) {
            for (int i = 0; i < n; i++) {
                if (s[i] == '?')
                    s[i] = 'd';
            }
            cout << "Yes\n" << s << "\n";
            continue;
        }

        for (int i = 0; i + 7 <= n; i++) {
            string temp = s;
            bool ok = true;
            for (int j = 0; j < 7; j++) {
                if (s[i + j] == req[j] or s[i + j] == '?')
                    continue;
                ok = false;
            }

            if (ok) {
                for (int j = 0; j < 7; j++) {
                    temp[i + j] = req[j];
                }
                if (check1(temp) == 1) {
                    s = temp;
                    break;
                }
            }
        }

        if (check1(s) != 1) {
            cout << "No\n";
            continue;
        }

        for (int i = 0; i < n; i++) {
            if (s[i] == '?')
                s[i] = 'd';
        }
        cout << "Yes\n" << s << "\n";
    }
    return 0;
}