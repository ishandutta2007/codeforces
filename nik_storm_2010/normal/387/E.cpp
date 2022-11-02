#include<cstdio>
#include<set>

using namespace std;
const int lim = 1000000 + 10;

int tree[lim], pa[lim], pb[lim];

void modify(int x, int z) {
    for (int i = x; i < lim; i = (i | (i + 1))) tree[i] += z;
}

int sum(int x) {
    int res = 0;
    for (int i = x; i >= 0; i = (i & (i + 1)) - 1) res += tree[i];
    return res;
}

int main() {
    int n, k, x;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++) { scanf("%d", &x); pa[x] = i; }
    for (int i = 1; i <= k; i++) { scanf("%d", &x); pb[x] = i; }
    for (int i = 1; i <= n; i++) modify(i, +1);
    long long ans = 0;
    set <int> base;
    base.insert(0);
    base.insert(n + 1);
    for (int i = 1; i <= n; i++) if (pb[i] == 0) {
        int x = pa[i];
        set <int>::iterator l = base.upper_bound(x);
        set <int>::iterator r = l;
        l--;
        ans += sum(*r - 1) - sum(*l);
        modify(x, -1);
    }
    else {
        int x = pa[i];
        base.insert(x);
    }
    printf("%I64d\n", ans);
    return 0;
}