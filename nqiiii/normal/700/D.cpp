#include <bits/stdc++.h>
using namespace std;
typedef long long Long;
const int maxN = 100000, sqrtN = 300;
int n;
int a[maxN + 10], cnt[maxN + 10], occ[maxN + 10];
int big[maxN + 10], bigCnt, q, tmp[maxN + 10];
int nowL, nowR;
Long ans[maxN + 10];

struct Query {
    int l, r, id;
    bool operator < (const Query &t) const {
        return l / sqrtN == t.l / sqrtN ? r < t.r : l < t.l;
    }
}ask[maxN + 10];

void Ins(int p) {
    --occ[cnt[a[p]]];
    ++occ[++cnt[a[p]]];
}

void Del(int p) {
    --occ[cnt[a[p]]];
    ++occ[--cnt[a[p]]];
}

priority_queue<int, vector<int>, greater<int> > heap;

Long Query() {
    Long ans = 0;
    int lst = 0;
    for (int i = 1; i <= sqrtN; ++i) tmp[i] = occ[i];
    for (int i = 1; i <= sqrtN; ++i)
        if (tmp[i]) {
            if (lst) {
                ans += lst + i;
                if (lst + i <= sqrtN) ++tmp[lst + i];
                else heap.push(lst + i);
                lst = 0; --tmp[i];
            }
            if (tmp[i] % 2) {
                lst = i; --tmp[i];
            }
            ans += 1ll * tmp[i] * i;
            if (i * 2 <= sqrtN) tmp[i * 2] += tmp[i] / 2;
            else for (int j = 1; j <= tmp[i] / 2; ++j)
                heap.push(i * 2);
        }
    if (lst) heap.push(lst);
    for (int i = 1; i <= bigCnt; ++i)
        if (cnt[big[i]] > sqrtN) heap.push(cnt[big[i]]);
    while (heap.size() > 1) {
        int x = heap.top(); heap.pop();
        int y = heap.top(); heap.pop();
        ans += x + y; heap.push(x + y);
    }
    heap.pop(); return ans;
}

int main() {
    scanf("%d", &n); occ[0] = n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]); Ins(i);
    }
    for (int i = 1; i <= maxN; ++i)
        if (cnt[i] > sqrtN) {
            big[++bigCnt] = i;
        }
    scanf("%d", &q);
    for (int i = 1; i <= q; ++i) {
        scanf("%d%d", &ask[i].l, &ask[i].r);
        ask[i].id = i;
    }
    sort(ask + 1, ask + q + 1);
    nowL = 1; nowR = n;
    for (int i = 1; i <= q; ++i) {
        while (nowL > ask[i].l) Ins(--nowL);
        while (nowR < ask[i].r) Ins(++nowR);
        while (nowL < ask[i].l) Del(nowL++);
        while (nowR > ask[i].r) Del(nowR--);
        ans[ask[i].id] = Query();
    }
   for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
}