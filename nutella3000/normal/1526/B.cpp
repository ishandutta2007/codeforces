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
    int x;
    cin >> x;
    int b = (x % 11);
    int a = x / 111;
    if (a >= b) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    
    int t;
    cin >> t;
    while(t--) run();
}