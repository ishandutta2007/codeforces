#include <bits/stdc++.h>
using namespace std;

const int N = 1002;

int n, m, q;
int A[N][N];
pair<int, int> rgt[N][N], lft[N][N], up[N][N], down[N][N];

inline void swapp (pair<int, int> p, pair<int, int> q, pair<int, int> lft[N][N], pair<int, int> rgt[N][N]) {
    pair<int, int> L1 = lft[p.first][p.second];
    pair<int, int> L2 = lft[q.first][q.second];
    
    rgt[L1.first][L1.second] = q;
    rgt[L2.first][L2.second] = p;
    lft[p.first][p.second] = L2;
    lft[q.first][q.second] = L1;
}

inline void swapp (pair<int, int> p, pair<int, int> q, int dir) {
    if (dir == 0) swapp(p, q, lft, rgt);
    else swapp(p, q, up, down);
}


inline int inp() {
    char c = '0';
    int ret = 0;
    do {
        ret = (ret << 3) + (ret << 1) + c - 48;
        c = getchar();
    } while (c >= '0' && c <= '9');
    return ret;
}

int main() {
    n = inp(), m = inp(), q = inp();
    
    for (int i=1; i<=n; i++) 
        for (int j=1; j<=m; j++) 
            A[i][j] = inp();
    
    for (int i=0; i<=n+1; i++) for (int j=0; j<=m+1; j++) {    
        rgt[i][j] = make_pair(i, j+1);
        lft[i][j] = make_pair(i, j-1);
        up [i][j] = make_pair(i-1, j);
        down[i][j] = make_pair(i+1, j);
    }
    
    int a, b, c, d, h, w;
    while (q--) {
        a = inp(), b = inp(), c = inp(), d = inp(), h = inp(), w = inp();
        
        pair<int, int> pa = make_pair(a, 0);
        for (int i=0; i<b; i++) pa = rgt[pa.first][pa.second];
        
        pair<int, int> pc = make_pair(c, 0);
        for (int i=0; i<d; i++) pc = rgt[pc.first][pc.second];
        
        pair<int, int> qa = pa, qc = pc;
        
        for (int i=0; i<h; i++) {            
            swapp(pa, pc, 0);
            pa = down[pa.first][pa.second];
            pc = down[pc.first][pc.second];
        }
        
        for (int i=0; i<w; i++) {
            swapp(qa, qc, 1);
            qa = rgt[qa.first][qa.second];
            qc = rgt[qc.first][qc.second];
        }
        
        for (int i=0; i<h; i++) {
            swapp(qa, qc, 0);
            qa = down[qa.first][qa.second];
            qc = down[qc.first][qc.second];
        }
        
        for (int i=0; i<w; i++) {
            swapp(pa, pc, 1);
            pa = rgt[pa.first][pa.second];
            pc = rgt[pc.first][pc.second];
        }
        
    }
    
    for (int i=1; i<=n; i++) {
        pair<int, int> cur = make_pair(i, 0);
        for (int j=0; j<m; j++) {
            cur = rgt[cur.first][cur.second];
            printf ("%d ", A[cur.first][cur.second]);
        }                
        printf ("\n");
    }
    return 0;
}