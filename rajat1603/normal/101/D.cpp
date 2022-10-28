#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n;
int a , b , c;
vector < pair < int , int > > v[N];
int cnt[N];
int sum[N];
long long ans;
int val;
void dfs(int node , int parent){
    cnt[node] = 1;
    for(auto it : v[node]){
        if(it.first != parent){
            sum[it.first] += it.second;
            dfs(it.first , node);
            cnt[node] += cnt[it.first];
            sum[node] += sum[it.first];
        }
    }
}
void dfs2(int node , int parent){
    ans += val;
    sort(v[node].begin() , v[node].end() , [](pair < int , int > a , pair < int , int > b){
        return 1LL * sum[a.first] * cnt[b.first] < 1LL * sum[b.first] * cnt[a.first];
    });
    for(auto it : v[node]){
        if(it.first != parent){
            val += it.second;
            dfs2(it.first , node);
            val += it.second;
        }
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d %d" , &a , &b , &c);
        v[a].emplace_back(make_pair(b , c));
        v[b].emplace_back(make_pair(a , c));
    }
    dfs(1 , 0);
    dfs2(1 , 0);
    printf("%.9lf\n" , 1.0 * ans / (n - 1.0));
}