#include <bits/stdc++.h>
 
using namespace std;
 
#define forn(i, n) for(int i = 0; i < int(n); i++) 
#define x first
#define y second

const int N = 500 * 1000 + 13;
const int INF = 1e9;

pair<pair<int, int>, int> t[4 * N];

void build(int v, int l, int r){
    if (l == r - 1){
        t[v] = make_pair(make_pair(INF, INF), l);
        return;
    }
    
    int m = (l + r) / 2;
    
    build(v * 2, l, m);
    build(v * 2 + 1, m, r);
    
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

void update(int v, int l, int r, int pos, int prv, int nxt){
    if (l == r - 1){
        t[v].x = make_pair(nxt, prv);
        return;
    }
    
    int m = (l + r) / 2;
    
    if (pos < m)
        update(v * 2, l, m, pos, prv, nxt);
    else
        update(v * 2 + 1, m, r, pos, prv, nxt);
    
    t[v] = min(t[v * 2], t[v * 2 + 1]);
}

pair<pair<int, int>, int> get(int v, int l, int r, int L, int R){
    if (L >= R)
        return make_pair(make_pair(INF, INF), -1);
    
    if (l == L && r == R)
        return t[v];
    
    int m = (l + r) / 2;
    
    return min(get(v * 2, l, m, L, min(m, R)), get(v * 2 + 1, m, r, max(m, L), R));
}

int n, m;
int a[N];
pair<pair<int, int>, int> q[N];
int pos[N];
int ans[N];

bool comp(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b){
    return a.x.y < b.x.y;
}

int main() {
    memset(pos, -1, sizeof(pos));
    scanf("%d", &n);
    forn(i, n) scanf("%d", &a[i]);
    scanf("%d", &m);
    forn(i, m){
        scanf("%d%d", &q[i].x.x, &q[i].x.y);
        --q[i].x.x, --q[i].x.y;
        q[i].y = i;
    }
    sort(q, q + m, comp);
    
    build(1, 0, n);
    int lst = -1;
    forn(i, m){
        int l = q[i].x.x;
        int r = q[i].x.y;
        
        for (int j = lst + 1; j <= r; ++j){
            if (pos[a[j]] != -1)
                update(1, 0, n, pos[a[j]], -INF, j);
            update(1, 0, n, j, pos[a[j]], -INF);
            pos[a[j]] = j;
        }
        
        auto it = get(1, 0, n, l, r + 1);
        
        if (it.y == -1 || it.x.x != -INF || it.x.y >= l){
            ans[q[i].y] = 0;
        }
        else{
            ans[q[i].y] = a[it.y];
        }
        
        lst = r;
    }
    
    forn(i, m)
        printf("%d\n", ans[i]);
    
    return 0;
}