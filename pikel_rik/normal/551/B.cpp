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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> cnta(26), cntb(26), cntc(26);
    for (char ch : a) cnta[ch - 'a'] += 1;

    for (char ch : b) cntb[ch - 'a'] += 1;
    for (char ch : c) cntc[ch - 'a'] += 1;

    int m = INT_MAX;
    for (int j = 0; j < 26; j++) {
        if (cntb[j] > 0)
            m = min(m, cnta[j] / cntb[j]);
    }

    int best = m, bestb = m, bestc = 0;
    for (int k = 0; k <= m; k++) {
        vector<int> temp = cnta;
        for (int i = 0; i < 26; i++) {
            if (cntb[i] > 0)
                temp[i] -= k * cntb[i];
        }

        int l = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (cntc[i] > 0)
                l = min(l, temp[i] / cntc[i]);
        }

        if (l + k > best) {
            best = l + k;
            bestb = k;
            bestc = l;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (cntb[i] > 0)
            cnta[i] -= bestb * cntb[i];
        if (cntc[i] > 0)
            cnta[i] -= bestc * cntc[i];
    }

    for (int i = 0; i < bestb; i++) cout << b;
    for (int i = 0; i < bestc; i++) cout << c;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < cnta[i]; j++)
            cout << (char)('a' + i);
    }
    cout << "\n";
    return 0;
}