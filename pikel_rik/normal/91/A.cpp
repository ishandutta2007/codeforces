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
const int N = 1e5 + 5;

string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s1 >> s2;

    vector<int> cnt1(26), cnt2(26);
    for (char c : s1) {
        cnt1[c - 'a'] += 1;
    }
    for (char c : s2) {
        cnt2[c - 'a'] += 1;
    }

    for (int i = 0; i < 26; i++) {
        if (cnt2[i] > 0 and cnt1[i] == 0) {
            cout << "-1\n";
            return 0;
        }
    }

    vector<vector<int>> pos(26);

    for (int i = 0; i < s1.length(); i++)
        pos[s1[i] - 'a'].push_back(i);

    int ptr = -1, c = 1;
    for (char ch : s2) {
        auto it = upper_bound(all(pos[ch - 'a']), ptr);

        if (it == pos[ch - 'a'].end()) {
            ptr = -1;
            c += 1;
            it = upper_bound(all(pos[ch - 'a']), ptr);
        }
        ptr = *it;
    }

    cout << c << "\n";
    return 0;
}