#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define all(x) (x).begin(), (x).end()

using namespace __gnu_pbds;
using namespace std;

using ull = unsigned long long;
using ll = long long;
template <typename T> using ordered_set = tree<T, null_type, less<>, rb_tree_tag, tree_order_statistics_node_update>;

const int mod = 1e9 + 7;
const int inf = INT_MAX;
const int N = 2e5 + 5;

int n, m;
vector<pair<ll, char>> s, t;

int lps[N];
void constructLps() {
    int len = 0, i = 1;
    lps[0] = 0;

    while (i < m) {
        if (t[i] == t[len]) {
            len += 1;
            lps[i] = len;
            i += 1;
        }
        else if (len != 0) {
            len = lps[len - 1];
        }
        else {
            lps[i] = 0;
            i += 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        pair<int, char> p = {stoi(temp.substr(0, temp.length() - 2)), temp.back()};
        if (!s.empty() and s.back().second == p.second)
            s.back().first += p.first;
        else s.emplace_back(p);
    }

    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;

        pair<int, char> p = {stoi(temp.substr(0, temp.length() - 2)), temp.back()};
        if (!t.empty() and t.back().second == p.second)
            t.back().first += p.first;
        else t.emplace_back(p);
    }

    n = s.size();
    m = t.size();

    if (t.size() == 1) {
        ll c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i].second == t[0].second) {
                c += max(0ll, s[i].first - t[0].first + 1);
            }
        }
        cout << c << "\n";
        return 0;
    }

    constructLps();
    int i = 0, j = 0;
    ll c = 0;

//    for (int i = 0; i < m; i++) cout << lps[i] << " "; cout << "\n";

    while (i < n) {
        if (j == 0 and s[i].second == t[j].second and s[i].first >= t[j].first) {
            i += 1;
            j += 1;
        }
        else if (j == m - 1 and s[i].second == t[j].second and s[i].first >= t[j].first) {
            i += 1;
            j += 1;
            c++;
            if (s[i - 1] == t[j - 1])
                j = lps[j - 1];
            else {
                if (j > 1)
                    j = lps[j - 2];
                else j = 0;
            }

            if (j == 0 and t.front().second == t.back().second and s[i - 1].first >= t.front().first)
                j++;
        }
        else if (s[i] == t[j]) {
            i += 1;
            j += 1;
        }
        else if (s[i] != t[j]) {
            if (j != 0)
                j = lps[j - 1];
            else i += 1;
        }
//        cout << i << " " << j << "\n";
    }

    cout << c << "\n";
    return 0;
}

/*
8 5
1-a 1-b 1-c 1-a 2-b 1-c 1-a 1-b
1-a 1-b 1-c 1-a 1-b
 */