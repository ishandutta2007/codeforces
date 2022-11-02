#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define fi first
#define se second
#define size(a) (int) a.size()
#define chkmin(a, b) a = min(a, b)
#define chkmax(a, b) a = max(a, b)
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb emplace_back

const int inf = 2e9 + 2;

void run() {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> a[i];
    sort(all(a));
    for (int i = 0; i < n; ++i)
        cout << a[i] << " " << a[2 * n - 1 - i] << " ";
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) run();
}