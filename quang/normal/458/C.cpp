#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n;
pair<int, int> a[N];
int sl[N], cur[N];

int Buy(int k) {
    int h = sl[0], need = 0;
    for(int i = 1; i < N; i++) {
        cur[i] = sl[i];
        h += max(cur[i] - k + 1, 0);
    }
    for(int i = 1; i <= n; i++) {
        int u = a[i].second, v = a[i].first;
        if(u == 0) continue;
        if(cur[u] >= k) {
            need += v;
            cur[u]--;
        } else
            if(h < k) {
                h++;
                need += v;
            }
    }
    return need;
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        a[i] = make_pair(v, u);
        sl[u]++;
    }
    sort(a + 1, a + n + 1);
    int l = 0, r = n + 1;
    while(r - l > 1) {
        int m = (l + r) >> 1;
        int x = Buy(m);
        int y = Buy(m + 1);
        if(x > y) l = m;
        else r = m;
    }
    cout << Buy(r);
    return 0;
}