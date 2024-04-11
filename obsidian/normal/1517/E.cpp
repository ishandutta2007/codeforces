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
const int P = 998244353;

void brute(int N) {
    int a[N+10];
    int cnt = 0;
    for (int i = 0; i < (1<<N); ++i) {
        for (int j = 0; j < N; ++j) {
            if (i & (1 << j)) a[j] = 0;
            else a[j] = 1;
        }
        bool ok = true;
        int p0 = -1, p1 = -1, d0 = -1, d1 = -1;
        for (int j = 0; j < N; ++j) {
            if (a[j] == 0) {
                if (p0 != -1 && d0 != -1 && j - p0 < d0) ok = false;
                if (p0 != -1) d0 = j - p0;
                p0 = j;
            } else {
                if (p1 != -1 && d1 != -1 && j - p1 > d1) ok = false;
                if (p1 != -1) d1 = j - p1;
                p1 = j;
            }
        }
        if (ok) {
                //for(int j = 0; j < N; ++j) printf("%d", a[j]);puts(" OK");
        ++cnt;}
        //else {for(int j = 0; j < N; ++j) printf("%d", a[j]);puts(" WRONG");}
    }
    printf("%d\n", cnt);
}

const int V = 200100;
int n, a[V], b[V];
LL s[V];

int cal(vector<int> L, vector<int> R) {
    if (L.size() + R.size() > n) return 0;
    int m = 0;
    for (int i = L.size() ; i + R.size() < n; ++i) b[m++] = a[i];
    if (m % 2 != 0) return 0;
    LL D = 0;
    for (int i = 0; i < L.size();++i) {
        if (L[i] == 0) D -= a[i];
        else D += a[i];
    }
    for (int i = 0; i < R.size();++i) {
        if (R[i] == 0) D -= a[n - R.size() + i];
        else D += a[n - R.size() + i];
    }
    s[m + 1] = 0;
    for (int i = 0; i < m; ++i) D -= b[i];
    for (int i = m - 1; i > 0; i -= 2) s[i] = s[i + 2] + 2 * b[i];
    for (int i = m; i >= 0; i -= 2) s[i] = s[i + 1];
    int res = 0;
    int p = 1;
    for (int i = m; i >= 0; i -= 2) {
        if (i != m) D += 2 * b[i];
        while (p != m + 1 && s[p + 2] - s[m + 1] + D > 0) p += 2;
        //printf("A %lld %lld %lld %d %d\n", D, s[p], s[m + 1], i, p);
        if (s[p] - s[m + 1] + D > 0) {
            res += max(0, p / 2 - i / 2 + 1);
            res %= P;
        }
    }
    //for (int i = 0; i < L.size(); ++i) printf("%d ", L[i]); printf(" H ");
    //for (int i = 0; i < R.size(); ++i) printf("%d ", R[i]); printf(" T ");
    //printf("%d\n", res);
    return res;
}

vector<int> H[10], T[10];
int hn, tn;
void init() {
    hn = tn = 0;
    hn++;
    H[hn].PB(0);
    hn++;

    H[hn].PB(1);
    H[hn].PB(0);
    H[hn].PB(0);
    hn++;
    H[hn].PB(1);
    H[hn].PB(0);
    H[hn].PB(0);
    H[hn].PB(0);
    hn++;

    tn++;
    T[tn].PB(1);
    tn++;

    T[tn].PB(1);
    T[tn].PB(1);
    T[tn].PB(0);
    tn++;
    T[tn].PB(1);
    T[tn].PB(1);
    T[tn].PB(1);
    T[tn].PB(0);
    tn++;
}

int _;
int main() {
    //for (int i = 1; i <= 10; ++i)brute(i);
    init();
    scanf("%d", &_);
    while (_--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        int ans = 0;
        for (int i = 0; i < hn; ++i) {
            //for (int j = 0; j < H[i].size(); ++j) printf("%d ", H[i][j]); puts("");
            for (int j = 0; j < tn; ++j) {
                ans += cal(H[i], T[j]);
                ans %= P;
            }
        }
        LL sm = 0;
        for (int i = 0; i < n; ++i) sm -= a[i];
        for (int i = 0; i < n; ++i) {
            sm += 2 * a[i];
            if (sm > 0 && i >= 1 && i + 2 < n) {
                ++ans;
                ans %= P;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

/*
3
5
2 1 2 1 1
4
9 2 2 2
1
998244353
*/