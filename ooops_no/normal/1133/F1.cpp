#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int N = 2e5 + 10;
vector<int> g[N];
vector<bool> used(N);
vector<pair<int,int>> p;

int main(){
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b); 
        g[b].push_back(a);
    }
    int mx = 0, ma = 0;
    for (int i = 1; i <= n; i++){
        if (g[i].size() > mx){
            mx = g[i].size();
            ma = i;
        }
    }
    queue<int> q;
    q.push(ma);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        used[v] = true;
        for (auto to : g[v]){
            if (!used[to]){
                p.push_back(make_pair(v, to));
                q.push(to);
                used[to] = 1;
            } 
        }
    } 
    for (auto to : p){
        cout << to.first << " " << to.second << endl;
    }
}