#include<bits/stdc++.h>
using namespace std;
#define MAXN 200002
#define fi first
#define se second
#define mp make_pair

typedef pair<int, int> pii;

int n;
int a[MAXN];
pii urut[MAXN];
bool uda[MAXN];
int par[MAXN];
int sz[MAXN];

int f(int x) {
    if (x == par[x]) return x;
    return f(par[x]);
}

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d", &a[i]);
        urut[i] = mp(a[i], i+1);
    }

    sort(urut, urut+n, greater<pii>());
    for (int i=1; i<=n; i++) par[i] = i, sz[i] = 1;

    int bef = 0;
    for (int i=0; i<n; i++) {
        if (uda[urut[i].se - 1]) {
            int parent = f(urut[i].se - 1);
            int now = f(urut[i].se);
            par[now] = parent;
            sz[parent] += sz[now];
        }

        if (uda[urut[i].se + 1]) {
            int parent = f(urut[i].se + 1);
            int now = f(urut[i].se);
            par[now] = parent;
            sz[parent] += sz[now];
        }

        int saiz = sz[f(urut[i].se)];
        if (bef < saiz) {
            for (int j=bef; j<saiz; j++) printf("%d ", urut[i].fi);
            bef = saiz;
        }

        uda[urut[i].se] = 1;
    }

    printf("\n");

    return 0;
}