#include<bits/stdc++.h>
using namespace std;
#define L(i, j, k) for(int i = (j), i##E = (k); i <= i##E; i++) 
#define R(i, j, k) for(int i = (j), i##E = (k); i >= i##E; i--) 
#define ll long long 
#define ull unsigned long long 
#define db double
#define mp make_pair
const int inf = 1e9 + 7;
const int N = 8e5 + 7;
int n, m, fn, arr[N], h[N], fa[N], fb[N], cf[N], ans[N];
int wz[N], val[N];
int maxn = 0;
int sz[N];
void add(int *f, int x, int y) { for(; x <= fn; x += (x & -x)) if(f[sz[x]] < f[y] || (f[sz[x]] == f[y] && sz[x] > y)) sz[x] = y; }
int query(int *f, int x) { int ans = 0; for(; x; x -= (x & -x)) if(f[ans] < f[sz[x]] || (f[ans] == f[sz[x]] && ans > sz[x])) ans = sz[x]; return ans; }
vector< pair<int, int> > ve[N];
int main() {
    scanf("%d%d", &n, &m);
    L(i, 1, n) scanf("%d", &h[i]), arr[++fn] = h[i];
    L(i, 1, m) scanf("%d%d", &wz[i], &val[i]), arr[++fn] = val[i];
    sort(arr + 1, arr + fn + 1);
    fn = unique(arr + 1, arr + fn + 1) - arr - 1;
    L(i, 1, n) h[i] = lower_bound(arr + 1, arr + fn + 1, h[i]) - arr;
    L(i, 1, m) val[i] = lower_bound(arr + 1, arr + fn + 1, val[i]) - arr, ve[wz[i]].push_back(mp(i, val[i]));
    L(i, 1, n) {
        fa[i] = fa[query(fa, h[i] - 1)] + 1;
        for(pair<int, int> x : ve[i]) ans[x.first] += fa[query(fa, x.second - 1)] + 1;
        add(fa, h[i], i);
    }
    L(i, 1, fn) sz[i] = 0;
    R(i, n, 1) {
        fb[i] = fb[query(fb, fn - h[i])] + 1;
        for(pair<int, int> x : ve[i]) ans[x.first] += fb[query(fb, fn - x.second)] + 1;
        add(fb, fn - h[i] + 1, i);
    }
    L(i, 1, n) maxn = max(maxn, fa[i]);
    L(i, 1, n) if(fa[i] == maxn) cf[i + 1]++;
    L(i, 1, fn) sz[i] = 0;
    L(i, 1, n) {
        if(fa[i] + fb[i] - 1 == maxn) cf[query(fa, h[i] - 1) + 1]++, cf[i]--;
        add(fa, h[i], i);
    }
    L(i, 1, n) cf[i] += cf[i - 1];
    L(i, 1, m) printf("%d\n", max(cf[wz[i]] ? maxn : maxn - 1, ans[i] - 1));
    return 0;
}