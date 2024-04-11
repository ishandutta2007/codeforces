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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int sum1 = 0, sum2 = 0;
        for (int i = n - 1; i >= n/2; i--)
            sum1 += (1 << i);
        for (int i = 1; i < n/2; i++)
            sum2 += (1 << i);
        sum2 += (1 << n);

        cout << abs(sum1 - sum2) << "\n";
    }
    return 0;
}