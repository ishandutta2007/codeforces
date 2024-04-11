#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair

#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;
vector<pii> T[N];
vector<pii> R[N];

ll dist[N];
bool vis[N];
int main(){
    fastIO;
    int n, m;
    cin >> n >> m;
    ll u, v, w;
    for(int iq = 1; iq <= m ; iq ++ ){
        cin >> u >> v >> w;
        T[u].push_back(mp(v, w));
        R[v].push_back(mp(u, w));
    }
    for(int i = 1; i <= n; i ++ ){
        dist[i] = (ll)1e18;
    }
    dist[1] = 0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    pq.push(mp(0ll, 1));
    ll dis;
    int node;
    while(!pq.empty()){
        node = pq.top().se;
        dis = pq.top().fi;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;
        for(auto x : T[node]){
            if(dist[x.fi] > dis + x.se){
                dist[x.fi] = dis + x.se;
                pq.push(mp(dist[x.fi], x.fi));
            }
        }
    }
    for(int i = 1; i <= n; i ++ ){
        vis[i]=false;
        if(dist[i] < (ll)1e18){
            pq.push(mp(dist[i], i));
        }
    }
    while(!pq.empty()){
        node = pq.top().se;
        dis = pq.top().fi;
        pq.pop();
        if(vis[node]) continue;
        vis[node]=true;
        for(auto x : R[node]){
            if(dist[x.fi] > dis + x.se){
                dist[x.fi] = dis + x.se;
                pq.push(mp(dist[x.fi], x.fi));
            }
        }
    }
    for(int i = 2; i <= n; i ++ ){
        if(dist[i] < (ll)1e18){
            cout << dist[i] << " ";
        }
        else{
            cout << -1 << " ";
        }
    }
    return 0;
}