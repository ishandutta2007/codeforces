#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1010000000
#define N 100010

using namespace std;

int n, m, w;
int a[N], times[N];

bool Check(int x) {
    memset(times, 0, sizeof(times));
    int cnt = 0, cur = 0;
    for(int i = 1; i <= n; i++) {
        cur -= (i > w)? times[i - w] : 0;
        if(cur + a[i] < x) {
            times[i] = x - cur - a[i];
            cnt += times[i];
            cur += times[i];
        }
        if(cnt > m) return 0;
    }
    return cnt <= m;
}

int Solve() {
    int l = 0, r = MAX;
    while(r - l > 1) {
        int mi = (r + l ) >> 1;
        if(Check(mi))
            l = mi;
        else r = mi;
    }
    return l;
}

int main() {
   // fi, fo;
    scanf("%d%d%d", &n, &m, &w);
    for(int i = 1; i <= n; i++)
        scanf("%d", a + i);
    printf("%d", Solve());
    return 0;
}