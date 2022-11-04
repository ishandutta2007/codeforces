#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

const int MAXN = (int) 1e5;

ll a[MAXN + 1], b[MAXN + 1];

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(i = 1; i <= n; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int pa = n, pb = n;
    ll ans = 0;
    int step = 0;
    while(pa > 0 || pb > 0) {
        step++;
        if(step & 1) {
            if(pa == 0 || a[pa] < b[pb]) {
                pb--;
            }
            else {
                ans += a[pa--];
            }
        }
        else {
            if(pb == 0 || b[pb] < a[pa]) {
                pa--;
            }
            else {
                ans -= b[pb--];
            }
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}