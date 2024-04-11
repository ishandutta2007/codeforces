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

int n, a[N], b[N];
string s;

bool isVowel(char c) {
    return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> s;
    n = s.length();

    for (int i = 0; i < n; i++) {
        if (isupper(s[i]))
            s[i] = tolower(s[i]);
        if (isVowel(s[i]))
            a[i + 1] = -1;
        else a[i + 1] = 2;
    }

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    if (a[n] == -n) {
        cout << "No solution\n";
        return 0;
    }

    b[n] = a[n];
    for (int i = n - 1; i >= 1; i--)
        b[i] = max(b[i + 1], a[i]);

    int best = 1;
    for (int i = 0; i <= n; i++) {
        int lo = i + 1, hi = n;

        while (lo < hi) {
            int mid = lo + (hi - lo + 1) / 2;
            if (b[mid] >= a[i])
                lo = mid;
            else hi = mid - 1;
        }

        best = max(best, lo - i);
    }

    int ans = 0;
    for (int i = best; i <= n; i++) {
        if (a[i] - a[i - best] >= 0)
            ans++;
    }

    cout << best << " " << ans << "\n";
    return 0;
}