#include <bits/stdc++.h>
using namespace std;

long long inf = 1001001001001001001;

bool chmin(long long &x,long long y) {
    if(x > y) {
        x = y;
        return true;
    }
    return false;
}

int main() {
    int N,M;
    cin >> N >> M;
    vector<vector<pair<int,int>>>road(N);
    vector<vector<pair<int,int>>>road2(N);
    for(int i = 0; i < M; i++) {
        int U,V,W;
        cin >> U >> V >> W;
        U--;
        V--;
        road[U].push_back({V,W});
        road2[V].push_back({U,W});
    }
    vector<long long>dist(N,inf);
    dist[0] = 0;
    priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>que;
    que.push({0,0});
    while(!que.empty()) {
        pair<long long,int> x = que.top();
        que.pop();
        if(dist[x.second] != x.first) {
            continue;
        }
        for(auto i:road[x.second]) {
            if(chmin(dist[i.first],x.first+i.second)) {
                que.push({dist[i.first],i.first});
            }
        }
    }
    for(int i = 0; i < N; i++) {
        que.push({dist[i],i});
    }
    while(!que.empty()) {
        pair<long long,int> x = que.top();
        que.pop();
        if(dist[x.second] != x.first) {
            continue;
        }
        for(auto i:road2[x.second]) {
            if(chmin(dist[i.first],x.first+i.second)) {
                que.push({dist[i.first],i.first});
            }
        }
    }
    for(int i = 1; i < N; i++) {
        cout << ((dist[i] == inf)?-1:dist[i]) << ((i+1 == N)?"\n":" ");
    }
}