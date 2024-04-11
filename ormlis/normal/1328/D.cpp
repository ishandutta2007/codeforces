#include <bits/stdc++.h>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; (i) < n; ++(i))
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;

using namespace std;
const ll INF = 2e18;
const int INFi = 2e9;
const int maxN = 1000001;
const int P = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

void solve() {
    int n; cin >> n;
    bool flag = false;
    int find = 0;
    vector<int> a(n);
    range(i, n) {
        cin >> a[i];
    }
    int prev = a.back();
    set<int> t;
    range(i, n) {
        if (a[i] == prev) {
            flag = true;
            find = i;
        }
        prev = a[i];
        t.insert(a[i]);
    }
    if (t.size() == 1) {
        cout << "1\n";
        range(i, n) cout << "1 ";
        cout << "\n";
    } else if (t.size() == 2 || flag || n % 2 == 0) {
        cout << "2\n";
        if (n % 2) {
            range(i, find) {
                if (i & 1) cout << '1';
                else cout << '2';
                cout << ' ';
            }
            for(int i = find; i < n; ++i) {
                if (i & 1) cout << '2';
                else cout << '1';
                cout << ' ';
            }
        } else {
            range(i, n) {
                if (i & 1) cout << '1';
                else cout << '2';
                cout << ' ';
            }
        }
        cout << "\n";
    } else {
        cout << "3\n";
        range(i, n - 1) {
            if (i & 1) cout << '1';
            else cout << '2';
            cout << ' ';
        }
        cout << "3\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int tests;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}