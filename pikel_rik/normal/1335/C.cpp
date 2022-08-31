#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pi;

const int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vi count(n + 1);
        for (int i : a) {
            count[i] += 1;
        }

        int distinct = 0, m = INT_MIN;
        for (int i = 1; i <= n; i++) {
            if (count[i] > 0)
                distinct += 1;
            m = max(m, count[i]);
        }

        if (m < distinct)
            cout << m << "\n";
        else if (m > distinct)
            cout << distinct << "\n";
        else
            cout << distinct - 1 << "\n";
    }
    return 0;
}