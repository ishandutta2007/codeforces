#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 1;
int subtree[N];
vector < int > v[N];
int weight[N];
int from[N];
int to[N];
int n , q;
long long sum = 0;
void dfs(int node , int parent){
    subtree[node] = 1;
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            subtree[node] += subtree[next];
        }
    }
}
int main(){
    cin >> n;
    for(int i = 1 ; i < n ; ++i){
        cin >> from[i] >> to[i] >> weight[i];
        v[from[i]].emplace_back(to[i]);
        v[to[i]].emplace_back(from[i]);
    }
    dfs(1 , -1);
    for(int i = 1 ; i < n ; ++i){
        sum += 1LL * min(subtree[from[i]] , subtree[to[i]]) * (n - min(subtree[from[i]] , subtree[to[i]])) * weight[i];
    }
    cin >> q;
    while(q--){
        int i;
        cin >> i;
        sum -= 1LL * min(subtree[from[i]] , subtree[to[i]]) * (n - min(subtree[from[i]] , subtree[to[i]])) * weight[i];
        cin >> weight[i];
        sum += 1LL * min(subtree[from[i]] , subtree[to[i]]) * (n - min(subtree[from[i]] , subtree[to[i]])) * weight[i];
        double ans = sum;
        ans /= n;
        ans /= n - 1;
        ans *= 6;
        printf("%.6lf\n" , ans);
    }
}