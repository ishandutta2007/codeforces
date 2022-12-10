//sobskdrbhvk
//remember...
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()

const int maxl = 18,
      maxn = 1 << 18;
LL seg[maxn << 2];
int n, q, lg;
bool rev[maxl + 10],
     swp[maxl + 10];

void modify(int idx, int val, int h = lg, int id = 1) {
    if (swp[h])
        id ^= 1;
    if (h == 0) {
        seg[id] = val;
        return;
    }
    int siz = 1 << h;
    int mid = siz >> 1;
    if (rev[h])
        idx = siz - idx - 1;
    int dir = (idx >= mid);
    idx %= mid;
    modify(idx, val, h - 1, id << 1 | dir);
    seg[id] = seg[id << 1 | 0] + seg[id << 1 | 1];
}

LL sum(int st, int en, int h = lg, int id = 1) {
    if (swp[h])
        id ^= 1;
    int siz = (1 << h);
    if (st <= 0 and siz <= en)
        return seg[id];
    int mid = siz >> 1;
    if (rev[h]) {
        en--;
        st = siz - st - 1;
        en = siz - en - 1;
        swap(st, en);
        en++;
    }
    if (st >= mid)
        return sum(st - mid, en - mid, h - 1, id << 1 | 1);
    if (en <= mid)
        return sum(st, en, h - 1, id << 1 | 0);
    return sum(st, mid, h - 1, id << 1 | 0)
        + sum(0, en - mid, h - 1, id << 1 | 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    cin >> lg >> q;
    n = 1 << lg;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        modify(i, x);
    }
    while (q--) {
        int ty, fi, se;
        cin >> ty >> fi;
        if (ty == 1 or ty == 4)
            cin >> se;
        if (ty == 1)
            modify(fi - 1, se);
        else if (ty == 2)
            rev[fi] ^= 1;
        else if (ty == 3)
            swp[fi] ^= 1;
        else
            cout << sum(fi - 1, se) << '\n';
    }
	return 0;
}