#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 2e9 + 5;
const int N = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(all(a));
    int best = -1, best_val = INT_MIN;

    vector<ll> prefix(n + 1);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + a[i-1];
    }

    for (int i = 0; i < n; i++) { //1 5 3 => 4 5 4 =>
        ll lo = 1, hi = i + 1, mid;

        while (lo < hi) {
            mid = lo + (hi - lo + 1) / 2;
            if (mid * a[i] - (prefix[i + 1] - prefix[i - mid + 1]) > k) //ith element to i - mid + 1 th element
                hi = mid - 1;
            else lo = mid;
        }

        if (lo > best_val) {
            best_val = lo;
            best = a[i];
        }
    }

    cout << best_val << " " << best << "\n";
    return 0;
}