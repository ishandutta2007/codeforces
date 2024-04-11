#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX
#define N 100010

using namespace std;

struct BIT {
    long long T[N];
    void Set(int pos, long long val) {
        while(pos < N) {
            T[pos] += val;
            pos += pos & -pos;
        }
    }
    long long Get(int pos) {
        long long res = 0;
        while(pos) {
            res += T[pos];
            pos -= pos & -pos;
        }
        return res;
    }
    long long Get(int pos1, int pos2) {
        return Get(pos2) - Get(pos1);
    }
} Tree;

int n, q, L, R;
bool rev = 0;

void Update(int p) {
    int dai = R - L;
    if(rev) p = R - p;
    else p += L;
    if(p <= L + dai / 2 ) {
        if(rev) rev = 1 - rev;
        for(int i = L + 1; i <= p; i++)
            Tree.Set(p * 2 - i + 1, Tree.Get(i - 1, i));
        L = p;
    }
    else {
        if(!rev) rev = 1 - rev;
        for(int i = R; i > p; i--)
            Tree.Set(p * 2 - i + 1, Tree.Get(i - 1, i));
        R = p;
    }
}

int main() {
    //fi, fo;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) Tree.Set(i, 1ll);
    L = 0, R = n;
    while(q--) {
        int type, p, l, r;
        scanf("%d", &type);
        if(type == 1) {
            scanf("%d", &p);
            Update(p);
        }
        else {
            scanf("%d %d", &l, &r);
            if(rev) printf("%I64d\n", Tree.Get(R - r, R - l));
            else printf("%I64d\n", Tree.Get(L + l, L + r));
        }
    }
    return 0;
}