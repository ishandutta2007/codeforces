#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 300010

using namespace std;

int n, m;
int next[N], res[N];

int Getnext(int x) {
    return res[x]? (next[x] = Getnext(next[x])): x;
}

void Set(int l, int r, int val) {
    if(l > r) return;
    if(!res[l]) res[l] = val;
    while(1) {
        l = Getnext(l);
        if(l > r) return;
        res[l] = val;
    }
}

int main() {
    //fi, fo;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) next[i] = i + 1;
    while(m--) {
        int l, r, x;
        scanf("%d %d %d", &l, &r, &x);
        Set(l, x - 1, x);
        Set(x + 1, r, x);
    }
    for(int i = 1; i <= n; i++) printf("%d ", res[i]);
    return 0;
}