#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 2101;

string s[2], t;
vector<int> lps;

bool possible() {
    vector<int> cnt1(26), cnt2(26);

    for (char i : s[0]) cnt1[i - 'a'] += 1;
    for (char i : t) cnt2[i - 'a'] += 1;

    for (int i = 0; i < 26; i++) {
        if (cnt2[i] > 0 and cnt1[i] == 0)
            return false;
    }
    return true;
}

vector<int> compLps() {
    lps.resize(t.length(), 0);

    int i = 1, len = 0;
    lps[0] = 0;

    while (i < t.length()) {
        if (t[i] == t[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0)
                len = lps[len - 1];
            else lps[i] = 0, i++;
        }
    }

    return lps;
}

pair<int, int> kmp (int f) {
    int i = 0, j = 0, besti = -1, bestj = -1, best = 0;

    while (j < s[f].length()) {
        if (t[i] == s[f][j]) {
            i++;
            j++;

            best = max(best, i);

            if (besti == -1)
                besti = j - 1, bestj = j - 1;
            else if (i == best and bestj - besti + 1 <= best)
                besti = j - i, bestj = j - 1;
        }

        if (i == t.length()) {
            break;
        }
        else if (j < s[f].length() and t[i] != s[f][j]) {
            if (i != 0)
                i = lps[i - 1];
            else j++;
        }
    }

    return {besti, bestj};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s[0] >> t;

    s[1] = s[0];
    reverse(all(s[1]));

    if (!possible()) {
        cout << "-1\n";
        return 0;
    }

    vector<pair<int, int>> ans;

    while (!t.empty()) {
        lps = compLps();

        pair<int, int> temp1 = kmp(0), temp2 = kmp(1);
        int len1 = temp1.second - temp1.first + 1, len2 = temp2.second - temp2.first + 1;

        if (len1 >= len2) {
            ans.push_back(temp1);
            t.erase(0, len1);
        }
        else {
            temp2.first = s[0].length() - temp2.first - 1;
            temp2.second = s[0].length() - temp2.second - 1;
            ans.push_back(temp2);
            t.erase(0, len2);
        }
    }

    cout << ans.size() << "\n";
    for (auto p : ans) cout << p.first + 1 << " " << p.second + 1 << "\n";
    return 0;
}