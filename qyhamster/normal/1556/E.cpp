#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
long long a[maxn];
long long mx[maxn][20], mn[maxn][20];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, Q;
    cin >> n >> Q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a[i] += a[i-1] - x;
    }
    for(int i = 1; i <= n; i++) {
        mx[i][0] = mn[i][0] = a[i];
    }
    for(int j = 1; j < 20; j++) {
        for(int i = 1; i <= n; i++) {
            if(i + (1<<j) - 1 <= n) {
                mx[i][j] = max(mx[i][j-1], mx[i+(1<<(j-1))][j-1]);
                mn[i][j] = min(mn[i][j-1], mn[i+(1<<(j-1))][j-1]);
            }
        }
    }
    while(Q--) {
        int l, r;
        cin >> l >> r;
        int d = 0;
        while(r-l+1 >= (1<<d)) d++;
        d--;
        if(a[l-1] != a[r] || mx[l][d] > a[r] || mx[r-(1<<d)+1][d] > a[r]) {
            cout << -1 << endl;
            continue;
        }
        cout << a[l-1] - min(mn[l][d], mn[r-(1<<d)+1][d])<< endl;
    }
    return 0;
}