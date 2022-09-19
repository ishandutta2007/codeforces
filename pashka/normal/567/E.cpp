#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

vector<vector<pair<int, int> > > g[2];
vector<long long> d[2];


long long dist;
vector<int> z;

vector<int> p(0);
vector<int> pp;

void dfs(int v) {
//    printf("!!%d\n", v);
    if (z[v]) return;
    z[v] = 1;
    for (size_t j = 0; j < g[0][v].size(); ++j) {
        int to = g[0][v][j].first;
        int len = g[0][v][j].second;
//        printf("%d %d %lld %lld %lld\n", to, len, d[0][v], d[1][to], dist);
        if (d[0][v] + d[1][to] + len == dist) {
            dfs(to);
        }
    }
    p.push_back(v);
}


int main() {
    int n, m, s, t;
    scanf("%d %d %d %d", &n, &m, &s, &t);
    s--;
    t--;

    g[0] = vector<vector<pair<int, int> > >(n);
    g[1] = vector<vector<pair<int, int> > >(n);

    vector<int> xx;
    vector<int> yy;
    vector<int> ll;

    for (int i = 0; i < m; i++) {
        int x, y, l;
        scanf("%d %d %d", &x, &y, &l);
        x--;
        y--;
        xx.push_back(x);
        yy.push_back(y);
        ll.push_back(l);
        g[0][x].push_back(make_pair(y, l));
        g[1][y].push_back(make_pair(x, l));
    }

    d[0] = vector<long long>(n, 1000000000000000LL);
    d[1] = vector<long long>(n, 1000000000000000LL);
    for (int i = 0; i < 2; i++)
    {
        int start = i == 0 ? s : t;
        d[i][start] = 0;
        set<pair<long long, int> > q;
        q.insert(make_pair(d[i][start], start));
        while (!q.empty()) {
            int v = q.begin()->second;
            q.erase(q.begin());
            for (size_t j = 0; j < g[i][v].size(); ++j) {
                int to = g[i][v][j].first;
                int len = g[i][v][j].second;
                if (d[i][v] + len < d[i][to]) {
                    q.erase(make_pair(d[i][to], to));
                    d[i][to] = d[i][v] + len;
                    q.insert(make_pair(d[i][to], to));
                }
            }
        }
    }

    dist = d[0][t];

//    for (int i = 0; i < n; i++) {
//        printf("%lld %lld\n", d[0][i], d[1][i]);
//    }

    z = vector<int>(n, 0);
    dfs(s);

    pp = vector<int>(n, -1);
    for (int i = 0; i < p.size(); i++) {
        pp[p[i]] = i;
    }

    set<pair<int, int> > good;

    int min = p.size() - 1;
    for (int i = p.size() - 1; i >= 0; i--) {
        int v = p[i];
        int mm = min;
        int c = 0;
        for (size_t j = 0; j < g[0][v].size(); ++j) {
            int to = g[0][v][j].first;
            int len = g[0][v][j].second;
            if (d[0][v] + d[1][to] + len == dist) {
                int y = pp[to];
                if (y < min) min = y;
                if (y == i - 1) c++;
            }
        }
        if (mm == i && min == i - 1 && c == 1) {
            good.insert(make_pair(p[i], p[i - 1]));
        }
    }

    for (int i = 0; i < m; i++) {
        int x = xx[i];
        int y = yy[i];
        int l = ll[i];
        if (d[0][x] + d[1][y] + l == dist && good.find(make_pair(x, y)) != good.end()) {
            printf("YES\n");
        } else {
            long long dd = dist - 1 - d[0][x] - d[1][y];
            if (dd > 0) {
                printf("CAN %d\n", l - dd);
            } else {
                printf("NO\n");
            }
        }
    }

    return 0;
}