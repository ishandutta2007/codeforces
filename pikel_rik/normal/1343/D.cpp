#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<vi> vvi;

const int mod = 1e9 + 7;
const int inf = 1e9 + 5;

int main(){
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vi count(2*k + 1);
        for (int i = 0; i < n/2; i++) {
            count[a[i] + a[n - i - 1]] += 1;
        }

        vi prefix(2*k + 2);
        for (int i = 0; i < n/2; i++) {
            int left = min(a[i], a[n-i-1]) + 1;
            int right = max(a[i], a[n-i-1]) + k;

            prefix[left] += 1;
            prefix[right + 1] -= 1;
        }

        for (int i = 3; i <= 2*k; i++) {
            prefix[i] += prefix[i-1];
        }

        int m = inf;
        for (int i = 2; i <= 2*k; i++)
            m = min(m, (prefix[i] - count[i]) + 2 * (n/2 - prefix[i]));

        cout << m << "\n";
    }

    return 0;
}