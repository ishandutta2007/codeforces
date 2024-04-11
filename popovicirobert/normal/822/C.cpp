#include <bits/stdc++.h>
#define MAXN 200000
#define MOD 666013

using namespace std;

struct Data {
   int l;
   int r;
   int cost;
}a[MAXN + 1], b[MAXN + 1];

bool cmpr(Data A, Data B) {
    return A.r < B.r;
}

bool cmpl(Data A, Data B) {
   return A.l > B.l;
}


multiset <int> ms[MAXN + 1];

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i,n,x,poz;
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for(i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].cost;
        b[i].l = a[i].l;
        b[i].r = a[i].r;
        b[i].cost = a[i].cost;
    }
    sort(a + 1, a + n + 1, cmpr);
    sort(b + 1, b + n + 1, cmpl);
    for(i = 1; i <= n; i++)
        ms[b[i].r - b[i].l + 1].insert(b[i].cost);
    poz = n;
    int ans = (1LL << 31) - 1;
    for(i = 1; i <= n; i++) {
        while(poz > 0 && a[i].r >= b[poz].l) {
            ms[b[poz].r - b[poz].l + 1].erase(ms[b[poz].r - b[poz].l + 1].find(b[poz].cost));
            poz--;
        }
        if(x > a[i].r - a[i].l + 1 && !ms[x - (a[i].r - a[i].l + 1)].empty())
            ans = min(ans, (*ms[x - (a[i].r - a[i].l + 1)].begin()) + a[i].cost);
    }
    if(ans == (1LL << 31) - 1)
        ans = -1;
    cout << ans;
    //cin.close();
   // cout.close();
    return 0;
}