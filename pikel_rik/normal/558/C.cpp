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

int n, a[N];

bool isPower(int x) {
    for (int i = 0; i < 30; i++) {
        if (x == (1 << i))
            return true;
    }
    return false;
}

int convert(int a, int b) {
    int c = 0;
    while (a > b)
        a /= 2, c++;

    if (a == b)
        return c;

    while (b % a != 0 and a > 1) {
        a /= 2, c++;
        if (b % a == 0 and isPower(b / a))
            break;
    }

    if (b % a != 0 or !isPower(b / a))
        return -1;

    while (a != b)
        a *= 2, c++;
    return c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int m = *min_element(a, a + n);

    while (m % 2 == 0) m /= 2;

    vector<int> vals;
    while (m) {
        if (m % 2 != 0)
            vals.push_back(m);
        m /= 2;
    }

    int best = INT_MAX;

    for (int x : vals) {
        for (int i = x; i <= 1e6; i *= 2) {
            int score = 0, temp;
            for (int j = 0; j < n; j++) {
                temp = convert(a[j], i);
                if (temp == -1) {
                    score = -1;
                    break;
                }
                score += temp;
            }
            if (score != -1)
                best = min(best, score);
        }
    }

    cout << best << "\n";
    return 0;
}