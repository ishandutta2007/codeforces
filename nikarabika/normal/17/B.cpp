#include <bits/stdc++.h>

using namespace std;

#define PB push_back
#define MP make_pair
#define L first
#define R second

typedef long long int LL;
typedef pair<LL, LL> pie;

const int maxn = 1e3 + 85 - 75;
bool mark[maxn];
LL d[maxn];
LL n, m;
LL q[maxn];
vector<pie> v[maxn];
set<pie> s;
LL Max;
vector<int> root;

LL Dijkstra(int source){
    memset(d, 127, sizeof d);
    LL hana = 0;
    LL an = 0;
    s.insert(MP(0, source));
    d[source] = 0;
    while(s.size()){
        int x = s.begin() -> R;
        s.erase(s.begin());
        mark[x] = true;
        hana++;
        an += d[x];
        for(auto adj : v[x]){
            int y = adj.L, w = adj.R;
            if(w < d[y]){
                if(mark[y]){
                    an -= d[y];
                    hana--;
                    mark[y] = false;
                }
                s.erase(MP(d[y], y));
                d[y] = w;
                s.insert(MP(d[y], y));
            }
        }
    }
    if(hana == n)
        return an;
    return 2e9;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> q[i];
        if(q[i] > Max){
            Max = q[i];
            root.clear();
        }
        if(q[i] == Max)
            root.PB(i);
    }
    cin >> m;
    for(int i = 0; i < m; i++){
        int fi, se, th;
        cin >> fi >> se >> th;
        v[fi].PB(MP(se, th));
    }
    if(root.size() > 1){
        cout << -1 << endl;
        return 0;
    }
    LL Hana = Dijkstra(root[0]);
    if(Hana == 2e9)
        cout << -1 << endl;
    else
        cout << Hana << endl;
    return 0;
}