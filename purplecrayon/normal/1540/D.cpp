#include <bits/stdc++.h>
using namespace std;

#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 1e5+10, B = 200, CNT = (MAXN/B)+1, MAXL = 18;

int n, a[MAXN];

struct SQRT {
    int t[MAXN]={}, lzy[CNT]={};
    void add(int l, int r, int x){ 
        int c_l = l/B, c_r = r/B;
        if (c_l == c_r) {
            for (int i = l; i <= r; i++) t[i] += x;
        } else {
            for (int i = l, end = (c_l+1)*B-1; i <= end; i++) t[i] += x;
            for (int i = c_l+1; i <= c_r-1; i++) lzy[i] += x;
            for (int i = c_r*B; i <= r; i++) t[i] += x;
        }
        //for (int i = l; i <= r; i++) t[i] += x;
    }
    int qry(int x){ return lzy[x/B]+t[x]; }
};
struct LOG {
    int bit[MAXN]={}, time[MAXN]={}, tt=0;
    void clear() { tt++; }
    int val(int i){ return time[i] == tt ? bit[i] : 0; }
    void add(int i, int x) { //add to suffix
        for (; i < n; i |= i + 1) bit[i] = val(i)+x, time[i] = tt;
    }
    int qry(int i) { //point query
        int ans=0;
        for (++i; i > 0; i &= i - 1) ans += val(i-1);
        return ans;
    }
};

LOG cur;
struct Block {
    int suf[B]={}, l, r; //l and r are bounds of the block
    SQRT nxt;

    void bld(){
        int bel[B]={};
        for (int i = l; i <= r; i++) {
            int loc = a[i];
            for (int j = i+1; j <= r; j++) {
                if (a[j] > loc) bel[j-l]++;
                loc += a[j] <= loc;
            }
        }
        for (int i = l; i <= r; i++) {
            suf[i-l] = a[i]-bel[i-l];
            nxt.add(suf[i-l], n-1, 1);
        }
    }
    void upd(int i, int x) {
        cur.clear();
        for (int j = l; j <= r; j++) {
            if (j < i) cur.add(suf[j-l], 1); //slow part
            else if (j == i) {
                int hi = 0, sm = 0;
                for (int k = 1<<MAXL; k; k >>= 1) {
                    int c = hi+k-1;
                    if (c >= n) continue;

                    int v = cur.val(c);
                    if (sm + v + c < x) {
                        sm += v;
                        hi += k;
                    }
                }

                nxt.add(suf[j-l], n-1, -1);

                suf[j-l] = hi;
                cur.add(suf[j-l], 1);

                nxt.add(suf[j-l], n-1, +1);
                
            } else {
                int c_suf = MAXN;
                for (int v = max(suf[j-l]-1, 0); v <= min(n-1, suf[j-l]+1); v++) {
                    if (v + cur.qry(v) >= a[j]) {
                        c_suf = v;
                        break;
                    }
                }

                for (int k = c_suf; k < suf[j-l]; k++) nxt.add(k, k, +1);
                for (int k = suf[j-l]; k < c_suf; k++) nxt.add(k, k, -1);

                suf[j-l] = c_suf;
                cur.add(suf[j-l], 1);
            }
        }
        a[i] = x;
    }
    int qry(int i){ return nxt.qry(i); }
} blocks[CNT];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i], a[i] = i - a[i];
    for (int i = 0; i*B < n; i++) {
        int l = i*B, r = min(n-1, (i+1)*B-1);
        blocks[i].l = l, blocks[i].r = r;
        blocks[i].bld();
    }

    int q; cin >> q;
    while (q--) {
        int ty; cin >> ty;
        if (ty == 1) {
            int i, x; cin >> i >> x, --i, x = i - x;
            blocks[i/B].upd(i, x);
        } else if (ty == 2) {
            int i; cin >> i, --i;

            int loc = a[i], j = i+1;
            for (; j < n && j%B; j++) {
                loc += a[j] <= loc;
            }
            if (j < n) for (j /= B; j*B < n; j++) {
                loc += blocks[j].qry(loc);
            }
            cout << loc+1 << '\n';
        } else assert(false);
    }
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}