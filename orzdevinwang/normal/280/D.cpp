#include<bits/stdc++.h>

#define N 100010
#define ls (id << 1)
#define rs (id << 1 | 1)

using namespace std;
int n, m, a[N];
struct node {
    int al, sal, bl, sbl, ar, sar, br, sbr, am, lam, ram, bm, lbm, rbm, sum;
    bool flag;
} s[N << 2];
void filp(int x) {
    s[x].flag ^= 1, s[x].sum = -s[x].sum;
    swap(s[x].al, s[x].bl), swap(s[x].sal, s[x].sbl), s[x].al = -s[x].al, s[x].bl = -s[x].bl;
    swap(s[x].ar, s[x].br), swap(s[x].sar, s[x].sbr), s[x].ar = -s[x].ar, s[x].br = -s[x].br;
    swap(s[x].am, s[x].bm), swap(s[x].lam, s[x].lbm), swap(s[x].ram, s[x].rbm), s[x].am = -s[x].am, s[x].bm = -s[x].bm;
}
node operator + (node aa, node bb) {
    node res;
    res.flag = 0;
    
    res.sum = aa.sum + bb.sum;

    if(aa.al > aa.sum + bb.al) res.al = aa.al, res.sal = aa.sal;
    else res.al = aa.sum + bb.al, res.sal = bb.sal;
    if(aa.bl < aa.sum + bb.bl) res.bl = aa.bl, res.sbl = aa.sbl;
    else res.bl = aa.sum + bb.bl, res.sbl = bb.sbl;
    
    if(bb.ar > bb.sum + aa.ar) res.ar = bb.ar, res.sar = bb.sar;
    else res.ar = bb.sum + aa.ar, res.sar = aa.sar;
    if(bb.br < bb.sum + aa.br) res.br = bb.br, res.sbr = bb.sbr;
    else res.br = bb.sum + aa.br, res.sbr = aa.sbr;
    
    if(aa.ar + bb.al > aa.am && aa.ar + bb.al > bb.am) res.am = aa.ar + bb.al, res.lam = aa.sar, res.ram = bb.sal;
    else if(aa.am > bb.am) res.am = aa.am, res.lam = aa.lam, res.ram = aa.ram;
    else res.am = bb.am, res.lam = bb.lam, res.ram = bb.ram;
    if(aa.br + bb.bl < aa.bm && aa.br + bb.bl < bb.bm) res.bm = aa.br + bb.bl, res.lbm = aa.sbr, res.rbm = bb.sbl;
    else if(aa.bm < bb.bm) res.bm = aa.bm, res.lbm = aa.lbm, res.rbm = aa.rbm;
    else res.bm = bb.bm, res.lbm = bb.lbm, res.rbm = bb.rbm;
    
    return res;
}
void pushdown(int id) {
    if(s[id].flag) filp(ls), filp(rs), s[id].flag = 0;
}
void build(int L, int R, int id) {
    if(L == R) {
        s[id].sum = a[L];
        s[id].al = s[id].ar = s[id].am = a[L], s[id].lam = s[id].ram = s[id].sal = s[id].sar = L;
        s[id].bl = s[id].br = s[id].bm = a[L], s[id].lbm = s[id].rbm = s[id].sbl = s[id].sbr = L;
        return;
    }
    int mid = (L + R) / 2;
    build(L, mid, ls), build(mid + 1, R, rs);
    s[id] = s[ls] + s[rs];
}
// void bld(int L, int R, int id) {
//     if(L != R) pushdown(id), bld(L, (L + R) / 2, ls), bld((L + R + 2) / 2, R, rs), s[id] = s[ls] + s[rs];
// }
void qf(int id, int L, int R, int l, int r) {
    if(l <= L && R <= r) {
        filp(id);
        return;
    }
    int mid = (L+R) / 2;
    pushdown(id);
    if(l <= mid) qf(ls, L, mid, l, r);
    if(r > mid) qf(rs, mid + 1, R, l, r);
    s[id] = s[ls] + s[rs];
}
node query(int id, int L, int R, int l, int r) {
    if(l == L && R == r) return s[id];
    int mid = (L + R) / 2;
    pushdown(id);
    if(r <= mid) return query(ls, L, mid, l, r);
    else if(l >  mid) return query(rs, mid + 1, R, l, r);
    else return query(ls, L, mid, l, mid) + query(rs, mid + 1, R, mid+1, r);
}
void xg(int id, int L, int R, int wz) {
    if(L == R) {
        s[id].sum = a[L];
        s[id].al = s[id].ar = s[id].am = a[L], s[id].lam = s[id].ram = s[id].sal = s[id].sar = L;
        s[id].bl = s[id].br = s[id].bm = a[L], s[id].lbm = s[id].rbm = s[id].sbl = s[id].sbr = L;
        return;
    }
    int mid = (L+R) / 2;
    pushdown(id);
    if(wz <= mid) xg(ls, L, mid, wz);
    if(wz > mid) xg(rs, mid + 1, R, wz);
    s[id] = s[ls] + s[rs];
}
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    scanf("%d", &m);
    build(1, n, 1);
    while(m--) {
        int opt, l, r, k, nm[23][2], Ans = 0;
        scanf("%d%d%d", &opt, &l, &r);
        if(opt == 1) {
            scanf("%d", &k);
            for(int i = 1; i <= k; i++) {
                node res = query(1, 1, n, l, r);
                nm[i][0] = res.lam, nm[i][1] = res.ram, Ans += res.am;
                if(res.am <= 0) {
                	k = i - 1, Ans -= res.am;
                	break;
				}
                qf(1, 1, n, nm[i][0], nm[i][1]);
				// bld(1, n, 1);
				// cout << nm[i][0] << " " << nm[i][1] << endl;
			}
            for(int i = 1; i <= k; i++) qf(1, 1, n, nm[i][0], nm[i][1]);
            printf("%d\n", Ans);
        }
        else a[l] = r, xg(1, 1, n, l);
    }
    return 0;
}

// 20
// -5 -1 -9 -6 4 -5 6 1 5 -3 6 -3 10 1 4 -10 -10 -9 10 -6
// 20
// 1 1 14 3