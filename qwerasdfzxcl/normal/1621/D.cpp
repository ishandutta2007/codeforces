#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
struct Vertex{
    int x, y;
    ll d;
    Vertex(){}
    Vertex(int _x, int _y, ll _d):x(_x), y(_y), d(_d){}
    bool operator< (const Vertex &V) const{
        return d>V.d;
    }
};
ll dist[1010][1010];
int a[1010][1010], dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

pair<int, int> convert(pair<int, int> p, int n){
    p.first = (p.first + n*2) % (n*2);
    p.second = (p.second + n*2) % (n*2);
    return p;
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=0;i<n*2;i++){
        for (int j=0;j<n*2;j++){
            scanf("%d", a[i]+j);
            dist[i][j] = 1e18;
        }
    }

    vector<pair<int, int>> S, E;
    S.emplace_back(0, -1);
    S.emplace_back(0, n);
    S.emplace_back(n-1, -1);
    S.emplace_back(n-1, n);

    S.emplace_back(-1, 0);
    S.emplace_back(n, 0);
    S.emplace_back(-1, n-1);
    S.emplace_back(n, n-1);

    for (auto &p:S) E.emplace_back(p.first+n, p.second+n);

    priority_queue<Vertex> pq;
    for (auto &p:S){
        auto q = convert(p, n);
        pq.emplace(q.first, q.second, 0);
        dist[q.first][q.second] = a[q.first][q.second];
    }

    while(!pq.empty()){
        auto s = pq.top(); pq.pop();
        if (dist[s.x][s.y]<s.d) continue;
        for (int k=0;k<4;k++){
            int x = s.x+dx[k], y = s.y+dy[k];
            auto q = convert(make_pair(x, y), n);

            if (dist[q.first][q.second] > s.d + a[q.first][q.second]){
                dist[q.first][q.second] = s.d + a[q.first][q.second];
                pq.emplace(q.first, q.second, dist[q.first][q.second]);
            }
        }
    }

    ll ans = 1e18;
    for (auto &p:E){
        auto q = convert(p, n);
        ans = min(ans, dist[q.first][q.second]);
    }

    for (int i=n;i<n*2;i++){
        for (int j=n;j<n*2;j++) ans += a[i][j];
    }
    printf("%lld\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}