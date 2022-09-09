#include <cstdio>
#include <iostream>
#include <ctime>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define puba push_back
#define mapa make_pair
#define ff first
#define ss second
#define all(_x) _x.begin(), _x.end()
#define szof(_x) (int) _x.size()

using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;

int random() {
    return (rand() << 15) + rand();
}
vector <pair <int, LL> > graph[MAXN], railway, roads[MAXN];
int min_railway[MAXN], num_min_railway[MAXN], first_railway[MAXN];
bool used[MAXN];
long long minl[MAXN];
int n, m, k;

int main() {    
    cin >> n >> m >> k;
    for (int i = 0; i < MAXN; ++i) {
        min_railway[i] = 1e9 + 5;
    }
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        --u;
        --v;
        graph[u].puba(mapa(v, x));
        graph[v].puba(mapa(u, x));
        roads[u].puba(mapa(v, x));
        roads[v].puba(mapa(u, x));
    }
    for (int i = 0; i < k; ++i) {
        int u, x;
        cin >> u >> x;
        --u;
        graph[u].puba(mapa(0, x));
        graph[0].puba(mapa(u, x));
        railway.puba(mapa(u, x));
        if (min_railway[u] > x) {
            min_railway[u] = x;
            first_railway[u] = i;
            num_min_railway[u] = 1;
        } else if (min_railway[u] == x) {
            num_min_railway[u]++;            
        }        
    }
    priority_queue <pair <LL, int> > s;
    s.push(mapa(0, 0));
    while (s.size() > 0) {
        pair <LL, int> p = s.top();
        s.pop();
        while (s.size() > 0 && used[p.ss]) {
            p = s.top();
            s.pop();
        }
        if (used[p.ss]) {
            break;
        }
        p.ff *= -1;
        //cout << p.ff << " v" << endl;
        used[p.ss] = true;
        minl[p.ss] = p.ff;
        for (int i = 0; i < (int) graph[p.ss].size(); ++i) {
            if (!used[graph[p.ss][i].ff]) {
                s.push(mapa(-(graph[p.ss][i].ss + p.ff), graph[p.ss][i].ff));
            }
        }
    }
    /*
    for (int i = 0; i < n; ++i) {
        cout << min_railway[i] << " " << num_min_railway[i] << endl;
    }*/
    int ans = 0;
    for (int i = 0; i < szof(railway); ++i) {
        //cout << i << " i" << endl;
        if (minl[railway[i].ff] < railway[i].ss || min_railway[railway[i].ff] < railway[i].ss || (num_min_railway[railway[i].ff] > 1 && first_railway[railway[i].ff] != i)) {
            ++ans;
        } else {
            assert(minl[railway[i].ff] == railway[i].ss);
            bool flag = false;
            for (int j = 0; j < szof(roads[railway[i].ff]); ++j) {
                if (minl[roads[railway[i].ff][j].ff] + roads[railway[i].ff][j].ss == railway[i].ss) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                ++ans;
            }
        }
    }
    cout << ans;
    return 0;
}