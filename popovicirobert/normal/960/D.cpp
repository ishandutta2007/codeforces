#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
// 217
// 44

using namespace std;

//ifstream fin("A.in");
//ofstream fout("A.out");

ll shift[100], lazy[100];

void dfs(int cur_lvl, ll nod, int lvl, ll &pos) {
    shift[cur_lvl] += lazy[cur_lvl];
    shift[cur_lvl] %= (1LL << cur_lvl);
    lazy[cur_lvl + 1] += 2LL * lazy[cur_lvl];
    lazy[cur_lvl + 1] %= (1LL << (cur_lvl + 1));
    lazy[cur_lvl] = 0;
    if(cur_lvl == lvl) {
        printf("%I64d " ,nod);
        pos = (nod - (1LL << lvl) + 1 + shift[lvl]) % (1LL << lvl);
        if(pos == 0)
            pos = (1LL << lvl);
        pos += (1LL << lvl) - 1;
    }
    else {
        dfs(cur_lvl + 1, nod, lvl, pos);
        ll val = (pos - (1LL << cur_lvl) + 1 - shift[cur_lvl] + (1LL << (cur_lvl + 1))) % (1LL << cur_lvl);
        if(val == 0)
            val = (1LL << cur_lvl);
        printf("%I64d ", val + (1LL << cur_lvl) - 1);
    }
    pos /= 2;
}

int main() {
    int t, q, i;
    //ios::sync_with_stdio(false);
    scanf("%d" ,&q);
    while(q > 0) {
        q--;
        ll x, k = 0;
        scanf("%d%I64d" ,&t,&x);
        if(t < 3) {
            scanf("%I64d" ,&k);
        }
        int lvl = 0;
        for(i = 0; i < 62; i++) {
            if(x & (1LL << i))
                lvl = i;
        }
        k += (1LL << lvl) * (llabs(k) / (1LL << lvl) + 1);
        k %= (1LL << lvl);
        if(t == 1) {
            shift[lvl] += k;
            shift[lvl] %= (1LL << lvl);
        }
        else if(t == 2) {
            lazy[lvl] += k;
            lazy[lvl] %= (1LL << lvl);
        }
        else {
            ll pos;
            dfs(0, x, lvl, pos);
            printf("\n");
        }
    }
    //fin.close();
    //fout.close();
    return 0;
}