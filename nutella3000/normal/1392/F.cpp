#include <bits/stdc++.h>
 
using namespace std;

#define aidar asadulin
#define int long long
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define fi first
#define se second
#define all(_v) _v.begin(), _v.end()
#define sz(a) (int) (a.size())
#define chkmax(a, b) a = max(a, b)
#define chkmin(a, b) a = min(a, b)
typedef long double ld;
 
const int inf = 1e15;
const int max_n = 1e8;


signed main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        sum += a[i];
    }

    for(int x = 0;x <= n;x++) {
        int r = (n - 1) * (n - 2) / 2 + x;
        if (sum >= r && (sum - r) % n == 0) {
            int q = (sum - r) / n;

            for(int i = 0;i < n;i++) {
                int num = q + i;
                if (i > x) num--;
                cout << num << " ";
            }

            cout << endl;
            break;
        } 
    }
}