#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long LL;

int n, m;
LL pile[100002];

bool bisa (LL x) {
    int idx = n;
    LL now = pile[idx-1];
    for (int i=0; i<m; i++) {
        LL tmp = x - idx;
        while (tmp > 0) {
            LL ambil = min(now, tmp);
            tmp -= ambil;
            now -= ambil;

            while (now == 0) {
                idx--;
                if (idx == 0) return 1;
                now = pile[idx-1];
            }
        }
    }

    return 0;
}

int main() {
    scanf("%d %d", &n, &m);

    LL l, r = l = 0;
    for (int i=0; i<n; i++) scanf("%I64d", &pile[i]), r += pile[i];
    while (n > 0 && pile[n-1] == 0) n--;
    r += n;

    while (l < r) {
        LL mid = l + r >> 1;
        if (bisa(mid)) r = mid;
        else l = mid + 1;
    }

    printf("%I64d\n", l);

    return 0;
}