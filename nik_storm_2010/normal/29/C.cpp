#include<cstring>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<deque>
#include<stack>
#include<bitset>
#include<algorithm>
#include<functional>
#include<numeric>
#include<utility>
#include<sstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<memory.h>

using namespace std;
const int N = 2e5;

int a[N], b[N];
vector <int> next[N], base;
bool used[N];

int get(int x) {
    int l = -1, r = base.size() - 1;
    while (r - l > 1) {
        int m = (l + r) / 2;
        if (base[m] >= x) r = m; else l = m;
    }
    return r;
}

void build(int x) {
    used[x] = true;
    printf("%d ", base[x]);
    for (int i = 0; i < next[x].size(); i++) if (!used[next[x][i]]) build(next[x][i]);
}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d %d", &a[i], &b[i]), base.push_back(a[i]), base.push_back(b[i]);
    sort(base.begin(), base.end());
    for (int i = 1; i <= n; i++) {
        a[i] = get(a[i]), b[i] = get(b[i]);
        next[a[i]].push_back(b[i]);
        next[b[i]].push_back(a[i]);
    }
    int nom;
    for (int i = 0; i < N; i++) if (next[i].size() == 1) { nom = i; break; }
    build(nom);
    return 0;
}