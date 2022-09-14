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

const int N = 1 << 12;
int n, m, q;
int w[N], c[N], sw[N];
vector<pair<int, int>> ql[N];
int ans[500001];
char s[13];

int scan() {
    scanf("%s", &s);
    int ans = 0;
    for (int i = 0; i < n; i++)
        ans = ans * 2 + (s[i] - '0');
    return ans;
}

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 0; i < n; i++)
        scanf("%d", &w[n - 1 - i]);
    for (int i = 0; i < m; i++)
        c[scan()]++;
    int pw = 1 << n;
    for (int i = 0; i < pw; i++)
        for (int j = 0; j < n; j++)
            if (i & (1 << j))
                sw[i] += w[j];
    int t, k;
    for (int i = 0; i < q; i++) {
        t = scan();
        scanf("%d", &k);
        ql[t].push_back({k, i});
    }
    vector<pair<int, int>> a(pw + 1);
    for (int i = 0; i < pw; i++) {
        a[0] = {-1, 0};
        for (int j = 0; j < pw; j++)
            a[j + 1] = {sw[(i ^ j) ^ (pw - 1)], c[j]};
        sort(a.begin(), a.end());
        for (int j = 0; j < pw; j++)
            a[j + 1].second += a[j].second;
        for (auto &p : ql[i]) {
            int pos = lower_bound(a.begin(), a.end(), make_pair(p.first + 1, 0)) - a.begin();
            ans[p.second] = a[pos - 1].second;
        }
    }
    for (int i = 0; i < q; i++)
        printf("%d\n", ans[i]);
}