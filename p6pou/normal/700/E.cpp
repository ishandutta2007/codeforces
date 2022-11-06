#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 200000 + 5;
const int MAX_SEG = 8000000 + 5;

int N, ans;
char s[MAX_N];
namespace SEG {
    struct Node {
        int ls, rs;
    } node[MAX_SEG];
    int root[MAX_N << 1], total;

    void modify(int &i, int l, int r, int mp) {
        i = i ? i : ++ total;
        if (l == r) return;
        int mid = l + r >> 1;
        mp <= mid ?
        modify(node[i].ls, l, mid, mp) :
        modify(node[i].rs, mid + 1, r, mp);
    }
    int merge(int i, int j, int l, int r) {
        if (!i || !j) return i + j;
        int k = ++ total, mid = l + r >> 1;
        node[k].ls = merge(node[i].ls, node[j].ls, l, mid);
        node[k].rs = merge(node[i].rs, node[j].rs, mid + 1, r);
        return k;
    }
    int query(int i, int l, int r, int ql, int qr) {
        if (!i) return 0;
        if (ql <= l && r <= qr) return 1;
        int mid = l + r >> 1;
        if (ql <= mid && query(node[i].ls, l, mid, ql, qr)) return 1;
        if (mid < qr && query(node[i].rs, mid + 1, r, ql, qr)) return 1;
        return 0;
    }
}
namespace SAM {
    struct Node {
        int len, fail, end, go[26];
    } node[MAX_N << 1];
    int root, total, last;

    void init() {
        root = total = last = 1;
    }
    void extend(int c, int len) {
        int np = ++ total, p = last;
        node[np].len = len;
        node[np].end = len;
        node[p].go[c] = np;
        last = np;
        for (p = node[p].fail; p && !node[p].go[c]; p = node[p].fail) {
            node[p].go[c] = np;
        }
        if (!p) {
            node[np].fail = root;
        } else {
            int q = node[p].go[c];
            if (node[q].len == node[p].len + 1) {
                node[np].fail = q;
            } else {
                int nq = ++ total;
                node[nq].len = node[p].len + 1;
                node[nq].end = node[q].end;
                for (int i = 0; i < 26; i ++) {
                    node[nq].go[i] = node[q].go[i];
                }
                node[nq].fail = node[q].fail;
                node[q].fail = node[np].fail = nq;
                for (; p && node[p].go[c] == q; p = node[p].fail) {
                    node[p].go[c] = nq;
                }
            }
        }
    }
    void solve() {
        static int cnt[MAX_N], ver[MAX_N << 1], f[MAX_N << 1], g[MAX_N << 1];
        for (int i = 1; i <= total; i ++) cnt[node[i].len] ++;
        for (int i = 1; i <= N; i ++) cnt[i] += cnt[i - 1];
        for (int i = total; i >= 1; i --) ver[cnt[node[i].len] --] = i;
        for (int p = 1; p <= total; p ++) {
            if (node[p].end == node[p].len) {
                SEG::modify(SEG::root[p], 0, N, node[p].len);
            }
        }
        for (int i = total; i > 1; i --) {
            int p = ver[i], q = node[p].fail;
            SEG::root[q] = SEG::merge(SEG::root[q], SEG::root[p], 0, N);
        }
        f[root] = 0, g[root] = root;
        for (int i = 2; i <= total; i ++) {
            int p = ver[i], q = g[node[p].fail];
            f[p] = f[q], g[p] = q;
            int pl = node[p].len, pe = node[p].end, ql = node[q].len;
            if (SEG::query(SEG::root[q], 0, N, pe - pl + ql, pe - 1)) {
                f[p] = f[q] + 1, g[p] = p;
            }
            // printf("p=%d,q=%d, pl=%d,pe=%d,ql=%d, f=%d\n", p, q, pl, pe, ql, f[p]);
            ans = max(ans, f[p]);
        }
    }
}

int main() {
    scanf("%d", &N);
    scanf("%s", s + 1);
    N = strlen(s + 1);
    SAM::init();
    for (int i = 1; i <= N; i ++) {
        SAM::extend(s[i] - 'a', i);
    }
    SAM::solve();
    printf("%d\n", ans);
    return 0;
}