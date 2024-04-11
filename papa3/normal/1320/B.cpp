#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
const bool debug = true;
#else
const bool debug = false;
#define cerr if (true) {} else cout
#endif

#define int long long
#define double long double

const int INF = 1000000000000000000LL;
const int mod = 1000000007;

vector<int> drogi[1000010];
pair<int, int> dist[1000010];

int tab[1000010];

void bfs(int pocz) {
    dist[pocz] = {0, 1};
    
    queue<int> kol;
    kol.push(pocz);
    
    int gdzie;
    while (!kol.empty()) {
        gdzie = kol.front();
        kol.pop();
        int d = dist[gdzie].first;
        for (int i : drogi[gdzie]) {
            if (d + 1 < dist[i].first) {
                dist[i].first = d + 1;
                kol.push(i);
            }
            
            if (d + 1 == dist[i].first) {
                dist[i].second++;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    for (int a, b, i = 1; i <= m; i++) {
        cin >> a >> b;
        drogi[b].push_back(a);
    }
    
    for (int i = 0; i <= n; i++) {
        dist[i] = {INF, 0};
    }
    
    int k;
    cin >> k;
    for (int i = 1; i <= k; i++) {
        cin >> tab[i];
    }
    
    bfs(tab[k]);
    int mi = 0, ma = 0;
    int d = 0;
    for (int i = k - 1; i >= 1; i--) {
        if (dist[tab[i]].first == dist[tab[i + 1]].first + 1) {
            if (dist[tab[i]].second > 1) {
                ma++;
            }
        } else {
            mi++;
            ma++;
        }
        
        d++;
    }
    
    cout << mi << " " << ma;
    
    return 0;
}/*

*/