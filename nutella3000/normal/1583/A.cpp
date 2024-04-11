#include<bits/stdc++.h>
using namespace std;

#define pb emplace_back
#define pii pair<int, int>
#define fi first
#define se second
#define int long long
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define size(a) (int)a.size()
#define all(a) begin(a), end(a)
#define mp make_pair
#define ld long double


const int inf = 1e9 + 7;

bool pr(int n) {
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

void run() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        sum += a[i];
    }
    if (!pr(sum)) {
        cout << n << endl;
        for (int i = 0; i < n; ++i)
            cout << i + 1 << " ";
        cout << endl;
    } else {
        int id = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] % 2 == 1) id = i;

        cout << n - 1 << endl;
        for (int i = 0; i < n; ++i) {
            if (i != id) cout << i + 1 << " ";
        }
        cout << endl;
    }
}


signed main() {
    cin.tie(0), cout.tie(0), ios_base::sync_with_stdio(0);

    int t = 1;
    cin >> t;
    while (t--) {
        run();
    }
}