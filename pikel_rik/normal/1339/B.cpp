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
        multiset<int> s;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            s.insert(a[i]);
        }

        vi ans(n);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                auto it = s.end();
                it--;
                ans[i] = *(it);
                s.erase(it);
            }
            else {
                auto it = s.begin();
                ans[i] = *(it);
                s.erase(it);
            }
        }

        for (int i = n - 1; i >= 0; i--) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}