#include <cstdio>
#include <vector>   
#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <random>
#include <ctime>
#include <iomanip>
#include <deque>
#include <queue> 
#include <cmath>
#include <cstring>
#include <cassert>
#include <bitset>
#include <unordered_set>
typedef long long ll;
typedef long double ld;
  
using namespace std;

const int N = 1 << 19;
int a[N], ans[N];
vector<int> ls(N, -1);
pair<int, int> tr[N * 2];

void add(int v, int d) {
    tr[N + v] = {d, v};
    for (int i = (N + v) / 2; i; i /= 2)
        tr[i] = min(tr[i * 2], tr[i * 2 + 1]);
}

pair<int, int> getmn(int cl, int cr, int v=1, int l=0, int r=N) {
    if (cr <= l || r <= cl)
        return {N, 0};
    if (cl <= l && r <= cr)
        return tr[v];
    return min(getmn(cl, cr, v * 2, l, (l + r) / 2), getmn(cl, cr, v * 2 + 1, (l + r) / 2, r));
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);
#endif
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    vector<vector<int>> e(m, vector<int>(3));
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &e[i][1], &e[i][0]);
        e[i][1]--;
        e[i][2] = i;
    }
    sort(e.begin(), e.end());
    int rr = 0;
    for (auto &pp : e) {
        while (rr < pp[0]) {
            if (ls[a[rr]] > -1)
                add(ls[a[rr]], N);
            add(rr, ls[a[rr]]);
            ls[a[rr]] = rr;
            rr++;
        }
        pair<int, int> t = getmn(pp[1], pp[0]);
        if (t.first < pp[1])
            ans[pp[2]] = a[t.second];
    }
    for (int i = 0; i < m; i++)
        printf("%d\n", ans[i]);
}