#include <bits/stdc++.h>
#define MAXN 100000
#define zeros(x) (x & (-x))

using namespace std;

struct Data {
    int x1;
    int y1;
    int x2;
    int y2;
}v[MAXN + 1];

int fr[MAXN + 1];

int aib[MAXN + 1];

inline void update(int p, int val) {
    for(int i = p; i <= MAXN; i += zeros(i))
        aib[i] += val;
}

inline int query(int p) {
    int ans = 0;
    for(int i = p; i > 0; i -= zeros(i))
        ans += aib[i];
    return ans;
}

int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int n, m, i, d, cntl, cntr, cntb, cntt;
    ios::sync_with_stdio(false);
    cin >> d;
    cin >> n >> m;
    for(i = 1; i <= d; i++) {
        cin >> v[i].x1 >> v[i].y1 >> v[i].x2 >> v[i].y2;
        if(v[i].x1 > v[i].x2)
            swap(v[i].x1, v[i].x2);
        if(v[i].y1 > v[i].y2)
            swap(v[i].y1, v[i].y2);
    }
    cin >> cntl >> cntr >> cntt >> cntb;
    for(i = 1; i <= d; i++)
        update(v[i].x1, 1);
    for(i = 1; i <= d; i++) {
        update(v[i].x1, -1);
        if(query(v[i].x2 - 1) == cntl)
           fr[i]++;
        update(v[i].x1, 1);
    }
    memset(aib, 0, sizeof(aib));
    for(i = 1; i <= d; i++)
        update(v[i].x2, 1);
    for(i = 1; i <= d; i++) {
        update(v[i].x2, -1);
        if(query(MAXN) - query(v[i].x1) == cntr)
           fr[i]++;
        update(v[i].x2, 1);
    }
    memset(aib, 0, sizeof(aib));
    for(i = 1; i <= d; i++)
        update(v[i].y1, 1);
    for(i = 1; i <= d; i++) {
        update(v[i].y1, -1);
        if(query(v[i].y2 - 1) == cntt)
           fr[i]++;
        update(v[i].y1, 1);
    }
    memset(aib, 0, sizeof(aib));
    for(i = 1; i <= d; i++)
        update(v[i].y2, 1);
    for(i = 1; i <= d; i++) {
        update(v[i].y2, -1);
        if(query(MAXN) - query(v[i].y1) == cntb)
           fr[i]++;
        update(v[i].y2, 1);
    }
    for(i = 1; i <= d; i++) {
        if(fr[i] == 4) {
            cout << i;
            return 0;
        }
    }
    cout << -1;
    //cin.close();
    //cout.close();
    return 0;
}