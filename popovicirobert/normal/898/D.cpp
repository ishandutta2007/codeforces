#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long

using namespace std;

const int MAXN = (int) 2e5;

int aib[MAXN + 1], v[MAXN + 1];

inline void update(int pos, int n, int val) {
    for(int i = pos; i <= n; i += lsb(i))
        aib[i] += val;
}

inline int query(int pos) {
    int ans = 0;
    for(int i = pos; i > 0; i -= lsb(i))
        ans += aib[i];
    return ans;
}

int main() {
    //ifstream cin("A.in");
    //ofstream cout("A.out");
    int i, n, m, k;
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    for(i = 1; i <= n; i++) {
        cin >> v[i];
        update(i, n, 1);
    }
    sort(v + 1, v + n + 1);
    int b = 1, e = 1;
    int ans = 0;
    while(b <= n) {
        while(e <= n && v[e] - v[b] < m) {
            e++;
        }
        e--;
        while(e >= b && query(e) - query(b - 1) >= k) {
            if(query(e) - query(e - 1) == 1) {
                ans++;
                update(e, n, -1);
            }
            e--;
        }
        b++;
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}