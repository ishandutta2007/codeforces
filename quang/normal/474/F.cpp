#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)

using namespace std;

const int N = 100010;

int n;
int a[N], c[N * 4];
pair <int, int> b[N];

void Khoitao(int node, int l, int r) {
    if(l == r) {
        c[node] = a[l];
        return;
    }
    int m = (l + r) / 2;
    Khoitao(node * 2, l, m);
    Khoitao(node * 2 + 1, m + 1, r);
    c[node] = __gcd(c[node * 2], c[node * 2 + 1]);
}

int Get(int node, int l, int r, int x, int y) {
    if(x > r || l > y) return 0;
    if(x <= l && r <= y) return c[node];
    int m = (l + r) / 2;
    int p1 = Get(node * 2, l ,m, x, y) ;
    int p2 = Get(node * 2 + 1, m + 1, r, x , y);
    return __gcd(p1, p2);
}

int main() {
    ios_base::sync_with_stdio(0);
    //fi, fo;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = make_pair(a[i], i);
    }
    sort(b + 1, b + n + 1);
    Khoitao(1, 1, n);
    int t;
    cin >> t;
    while(t--) {
        int l, r;
        cin >> l >> r;
        int x = Get(1, 1, n, l, r);
        int dau = lower_bound(b + 1, b + n + 1, make_pair(x, l)) - b;
        int cuoi = lower_bound(b + 1, b + n + 1, make_pair(x, r + 1)) - b;
        cout << (r - l + 1) - (cuoi - dau) << endl;
    }
    return 0;
}