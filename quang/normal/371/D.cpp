#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 10000000000000000ll
#define N 200010

using namespace std;

int n, m;
int next[N];
long long a[N], b[N];

int getnext(int x) {
    return (b[x] == a[x])? (next[x] = getnext(next[x])) : x;
}

void Loang(long long x, int p) {
    while(x) {
        if(x + b[p] >= a[p]) {
            x -= (a[p] - b[p]);
            b[p] = a[p];
        }
        else {
            b[p] += x;
            x = 0;
        }
        p = getnext(p);
    }
}

int main() {
   // fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%I64d", a + i), next[i] = i + 1;
    a[n + 1] = MAX;
    scanf("%d", &m);
    while(m--) {
        int type, p;
        long long x;
        scanf("%d %d", &type, &p);
        if(type == 1) {
            scanf("%I64d", &x);
            Loang(x, p);
        }
        else printf("%I64d \n", b[p]);
    }
    return 0;
}