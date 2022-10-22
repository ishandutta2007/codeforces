#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
#define PB push_back
#define fi first
#define se second
#define MP make_pair
const int P = 1000000007;
const int V = 100100;
int t[V], c[V], _, n, m, x;
vector<int> s[V];
vector<char> ans[V];
LL sum[V];
int ok[V][3], pre[V][3];
int cal(int i, int mid) {
    int cnt = 0;
    if (i > mid) {
        if (mid > 0) cnt += pre[mid - 1][1];
        if (i < m) cnt += pre[m - 1][1] - pre[i][1];
        if (i > 0) cnt += pre[i - 1][2];
        if (mid > 0) cnt -= pre[mid - 1][2];
    } else if (i == mid) {
        if (i > 0) cnt += pre[i - 1][1];
        cnt += pre[m - 1][1];
        cnt -= pre[i][1];
    } else {
        if (i > 0) cnt += pre[i - 1][1];
        if (mid < m) cnt += pre[m - 1][1] - pre[mid][1];
        if (mid > 0) cnt += pre[mid][0];
        if (i >= 0) cnt -= pre[i][0];
    }
    //printf("Cal1 %d %d %d\n", i, mid, cnt);
    return cnt;
}

bool cmp(int x, int y) {
    return (LL) sum[x] * c[y] < (LL) sum[y] * c[x];
}
int id[V];
int main() {
    scanf("%d", &_);
    while (_--) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) scanf("%d", &t[i]);
        sort(t, t + n);
        for (int i = 0; i < m; ++i) t[i] = t[i + n - m];
        for (int i = 0; i < m; ++i) {
            scanf("%d", &c[i]);
            s[i].clear();
            ans[i].clear();
            sum[i] = 0;
            for (int j = 0; j < c[i]; ++j) {
                scanf("%d", &x);
                s[i].PB(x);
                sum[i] += x;
            }
        }
        for (int i = 0; i < m; ++i) id[i] = i;
        sort(id, id + m, cmp);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < 3; ++j) {
                int k = i + j - 1;
                if (k < 0 || k >= m) {ok[i][j] = 1; continue;}
                ok[i][j] = sum[id[i]] <= (LL) c[id[i]] * t[k];
            }
        }
        for (int j = 0; j < 3; ++j) pre[0][j] = ok[0][j];
        for (int i = 1; i < m; ++i) {
            for (int j = 0; j < 3; ++j) {
                pre[i][j] = pre[i - 1][j] + ok[i][j];
            }
        }
        for (int i = 0; i < m; ++i) {
            int lo = 0, up = m - 1;
            while (lo != up) {
                int mid = (lo + up + 1) / 2;
                int cnt = cal(i, mid);
                if (cnt == m - 1) lo = mid;
                else up = mid - 1;
            }
            int cnt = cal(i, up);
            //printf("Cal %d %d %d %d\n", i, id[i], up, cnt);
            if (cnt < m - 1) for (int j = 0; j < c[id[i]]; ++j) ans[id[i]].PB('0');
            else {
                for (int j = 0; j < c[id[i]]; ++j) {
                    if ((LL) t[up] * (c[id[i]] - 1) >= sum[id[i]] - s[id[i]][j]) ans[id[i]].PB('1');
                    else ans[id[i]].PB('0');
                }
            }
        }
        for (int i = 0; i < m; ++i) for (int j = 0; j < c[i]; ++j) printf("%c", ans[i][j]);
        puts("");
    }
    return 0;
}

/*
3
1 1
30
3
25 16 37
4 2
9 12 12 6
2
4 5
3
111 11 11
4 2
9 12 12 6
3
111 11 11
2
4 5
*/