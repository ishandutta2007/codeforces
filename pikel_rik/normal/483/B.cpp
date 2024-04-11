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

    ll n1, n2, x, y;
    cin >> n1 >> n2 >> x >> y;

    ll lo = n1 + n2, hi = 1e15, mid;

    while (lo < hi) {
        mid = lo + (hi - lo) / 2;
        if (n1 <= mid - mid / x and n2 <= mid - mid / y and n1 + n2 <= mid - mid / (x * y))
            hi = mid;
        else lo = mid + 1;
    }

    cout << lo << "\n";
    return 0;
}