#include <bits/stdc++.h>
using namespace std;
const int maxn = 200000;
int n, a[maxn + 10], id[maxn + 10];
int c[maxn + 10], ans[maxn + 10];
 
void modify(int p) {
    for (; p <= n; p += p & -p) ++c[p];
}
int query(int p) {
    int ans = 0;
    for (; p; p -= p & -p) ans += c[p];
    return ans;
}
 
bool cmp(int x, int y) {
    return a[x] < a[y];
}
 
void calc(int p) {
    for (int i = 1; i < n && i * (p - 1) + 2 <= n; ++i) {
        int l = i * (p - 1) + 2, r = min(i * p + 1, n);
        ans[i] += query(r) - query(l - 1);
    }
}
 
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); id[i] = i;
    }
    sort(id + 1, id + n + 1, cmp);
    for (int i = 1, lst; i <= n; i = lst) {
        for (lst = i; lst <= n && a[id[lst]] == a[id[i]]; ++lst);
        for (int j = i; j < lst; ++j) calc(id[j]);
        for (int j = i; j < lst; ++j)
            modify(id[j]);
    }
    for (int i = 1; i < n; ++i) printf("%d ", ans[i]);
}