#include <bits/stdc++.h>
#define fi freopen("inp.txt", "r", stdin)
#define fo freopen("out.txt", "w", stdout)
#define MAX 1000000010
#define N 1000010

using namespace std;

typedef pair<int, int> pi;
int n, d;
int b[N], sl[N], sl1[N];
pi a[N];

struct Tree {
    int tree[N];
    void Set(int x) {
        while (x <= n) {
            tree[x]++;
            x += (x & -x);
        }
    }
    int Get(int x) {
        int kq = 0;
        while(x){
            kq += tree[x];
            x -= (x & -x);
        }
        return kq;
    }
}t;

bool cmp(pi x, pi y) {
    return x.second < y.second;
}

void TURN() {
    sort(a + 1, a + n + 1);
    a[n + 1] = make_pair(MAX, n + 1);
    int cur = 1;
    for(int i = 2; i <= n + 1; i++)
        if(a[cur].first != a[i].first) {
            d++;
            for(int j = cur; j < i; j++) a[j].first = d;
            cur = i;
        }
    sort(a + 1, a + n + 1, cmp);
    for(int i = 1; i <= n; i++) b[i] = a[i].first;
}

int main() {
    //fi, fo;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &a[i].first);
        a[i].second = i;
    }
    TURN();
    long long res = 0;
    for(int i = 1; i <= n; i++) sl[b[i]] ++;
    for(int i = 1; i <= n; i++) {
        int cnt = sl[b[i]] - sl1[b[i]];
        res += t.Get(n) - t.Get(cnt);
        t.Set(++sl1[b[i]]);
    }
    printf("%I64d", res);
    return 0;
}