#include<bits/stdc++.h>
#define L(i, j, k) for(int i = j, i##E = k; i <= i##E; i++) 
#define R(i, j, k) for(int i = j, i##E = k; i >= i##E; i--)
#define ll long long
#define ull unsigned long long 
#define db double
#define pii pair<int, int>
#define mkp make_pair
using namespace std;
const int N = 4e5 + 7;
const int M = 8e6 + 7;
int n;
struct SegmentTree {
    int ch[M][2], fis[M], las[M], tot;
    void upd(int id) {
        if(fis[ch[id][0]]) fis[id] = fis[ch[id][0]];
        else fis[id] = fis[ch[id][1]];
        if(las[ch[id][1]]) las[id] = las[ch[id][1]];
        else las[id] = las[ch[id][0]];
    }
    void ins(int &id, int L, int R, int wz) {
        if(!id) id = ++tot;
        if(L == R) return fis[id] = las[id] = L, void();
        int mid = (L + R) / 2;
        if(wz <= mid) ins(ch[id][0], L, mid, wz);
        else ins(ch[id][1], mid + 1, R, wz);
        upd(id);
    }
    int merge(int x, int y) {
        if(!x || !y) return x | y;
        int nwnode = ++tot;
        ch[nwnode][0] = merge(ch[x][0], ch[y][0]);
        ch[nwnode][1] = merge(ch[x][1], ch[y][1]);
        upd(nwnode);
        return nwnode;
    }
    int query(int id, int L, int R, int wz) {
        if(L == R) return las[id];
        int mid = (L + R) / 2;
        if(wz <= mid) return query(ch[id][0], L, mid, wz);
        else {
            int res = query(ch[id][1], mid + 1, R, wz);
            if(res) return res;
            else return las[ch[id][0]];
        } 
    }
} seg;
struct SAM {
    int head[N], ch[N][26], fa[N], len[N], jp[20][N], las = 1, tot = 1;
    void copy(int x, int y) {
        L(i, 0, 25) ch[y][i] = ch[x][i];
        fa[y] = fa[x], len[y] = len[x];
    }
    void ins(int x, int id) {
        int p = las, now = las = ++tot;
        len[now] = len[p] + 1, seg.ins(head[now], 1, n, id);
        for(; p && !ch[p][x]; p = fa[p]) ch[p][x] = now;
        if(!p) fa[now] = 1;
        else {
            int pto = ch[p][x];
            if(len[pto] == len[p] + 1) fa[now] = pto;
            else {
                int sp = ++tot;
                copy(pto, sp), len[sp] = len[p] + 1;
                fa[pto] = fa[now] = sp;
                for(; p && ch[p][x] == pto; p = fa[p]) ch[p][x] = sp;
            }
        }
    }
    int c[N], q[N];
    void work() {
        L(i, 1, tot) c[len[i]]++;
        L(i, 1, tot) c[i] += c[i - 1];
        L(i, 1, tot) q[c[len[i]]--] = i;
        R(i, tot, 1) head[fa[q[i]]] = seg.merge(head[fa[q[i]]], head[q[i]]);
        L(i, 1, tot) jp[0][i] = fa[i];
        L(i, 1, 18) L(j, 1, tot) jp[i][j] = jp[i - 1][jp[i - 1][j]];
    }
} sam;
int ans[N];
int get(int x) {
    int fis = seg.fis[sam.head[x]], now = x;
    R(i, 18, 0) if(sam.jp[i][now] && sam.len[sam.jp[i][now]] + fis - seg.query(sam.head[sam.jp[i][now]], 1, n, fis - 1) > sam.len[x]) 
        now = sam.jp[i][now];
    return sam.jp[0][now];
}
int dfs(int x) {
    if(x <= 1) return 0;
    if(ans[x]) return ans[x];
    int res = get(x);
    return ans[x] = 1 + dfs(res);
}
char s[N];
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    L(i, 1, n) sam.ins(s[i] - 'a', i);
    sam.work();
    int Ans = 0;
    L(i, 1, sam.tot) Ans = max(Ans, dfs(i));
    printf("%d\n", Ans);
	return 0;
}