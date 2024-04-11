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
        int k, n;
        cin >> n >> k;

        vi a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        set<int> s;
        for (int i : a) s.insert(i);

        if (s.size() > k) {
            cout << "-1\n";
            continue;
        }

        cout << n * k << "\n";


        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k - s.size(); j++)
                cout << *(s.begin()) << " ";
            for (auto const &x : s)
                cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}