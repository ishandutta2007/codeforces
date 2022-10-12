#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 2000;

int n, m, k;

vector < pair<pair<int, int>, int> > chain[N];
LL ans[N];
bool garland[N+1][N];

struct Ask {
    int a, b, c, d;
    
    Ask(int _a, int _b, int _c, int _d) {
        a = _a, b = _b, c = _c, d = _d;
    }
};
vector <Ask> ask;

struct BIT {
    LL sum[N][N];
    
    void update(int x, int y, int val) {
        for (int i=x+1; i<=n; i+=i&-i)
            for (int j=y+1; j<=m; j+=j&-j)
                sum[i-1][j-1] += val;
    }
    
    LL query (int x, int y) {
        LL ret = 0;
        for (int i=x+1; i; i-=i&-i)
            for (int j=y+1; j; j-=j&-j)
                ret += sum[i-1][j-1];
                
        return ret;
    }
} bit;

int main() {
    scanf ("%d %d %d", &n, &m, &k);
    
    for (int i=0; i<k; i++) {
        int len;
        scanf ("%d", &len);
        
        int x, y, z;
        while (len--) {
            scanf ("%d %d %d", &x, &y, &z);
            chain[i].push_back(make_pair(make_pair(--x, --y), z));
        }
    }
    
    for (int i=0; i<k; i++) garland[0][i] = 1;
    
    int q;
    scanf ("%d", &q);
    char s[10];
    int cur = 0;
    while (q--) {
        scanf ("%s", s);
        if (s[0] == 'A') {
            int a, b, c, d;
            scanf ("%d %d %d %d", &a, &b, &c, &d);
            ask.push_back(Ask(--a, --b, --c, --d));
            
            for (int i=0; i<k; i++) garland[cur+1][i] = garland[cur][i];
            cur++;
        } else {
            int x;
            scanf ("%d", &x);
            garland[cur][--x] ^= 1;
        }
    }
    
    for (int i=0; i<k; i++) {
        for (int j=0; j<chain[i].size(); j++) bit.update(chain[i][j].first.first, chain[i][j].first.second, chain[i][j].second);
        
        for (int j=0; j<ask.size(); j++) {
            if (garland[j][i])
            ans[j] += bit.query(ask[j].c, ask[j].d) - bit.query(ask[j].c, ask[j].b-1) - bit.query(ask[j].a-1, ask[j].d) + bit.query(ask[j].a-1, ask[j].b-1);
        }
        
        for (int j=0; j<chain[i].size(); j++) bit.update(chain[i][j].first.first, chain[i][j].first.second, -chain[i][j].second);
    }
    
    for (int i=0; i<ask.size(); i++) printf ("%I64d\n", ans[i]);
    return 0;
}