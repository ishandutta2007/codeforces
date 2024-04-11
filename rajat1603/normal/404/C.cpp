#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k;
pair < int , int > dist[N];
vector < pair < int , int > > edges;
priority_queue < pair < int , int > > s[N];
int node;
int main(){
    cin >> n >> k;
    for(int i = 1 ; i <= n ; ++i){
        cin >> dist[i].first;
        dist[i].second = i;
    }
    sort(dist + 1 , dist + 1 + n);
    for(int i = 1 ; i <= n ; ++i){
        if(dist[i].first == 0){
            s[0].push(make_pair(0 , dist[i].second));
        }
    }
    for(int i = 2 ; i <= n ; ++i){
        if(s[0].size() != 1 or s[dist[i].first - 1].empty() or -s[dist[i].first - 1].top().first >= k){
            cout << -1;
            return 0;
        }
        node = s[dist[i].first - 1].top().second;
        s[dist[i].first - 1].push(make_pair(s[dist[i].first - 1].top().first - 1 , node));
        s[dist[i].first - 1].pop();
        s[dist[i].first].push(make_pair(-1 , dist[i].second));
        edges.push_back(make_pair(node , dist[i].second));
    }
    cout << edges.size();
    for(auto it : edges){
        cout << "\n" << it.first << " " << it.second;
    }
}