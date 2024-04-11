#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 3e5;

ll a[MAXN + 1], b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i;
    ios::sync_with_stdio(false);
    cin >> n;
    ll sa = 0;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
        sa += a[i];
    }
    cin >> m;
    ll sb = 0;
    for(i = 1; i <= m; i++) {
        cin >> b[i];
        sb += b[i];
    }
    if(sa != sb) {
        cout << -1;
        return 0;
    }
    int pa = 1, pb = 1;
    int ans = 0;
    while(pa <= n && pb <= m) {
        ans++;
        sa = a[pa++];
        sb = b[pb++];
        while(sa != sb) {
            if(sa < sb) {
                sa += a[pa++];
            }
            else {
                sb += b[pb++];
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}