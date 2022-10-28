#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int MX = 77778;
int parent[N];
int sizes[N];
int n , m;
int a , b;
int dp[MX];
vector < pair < int , int > > v[N + N];
int find(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = find(parent[node]);
}
bool lucky(int num){
    while(num){
        if((num % 10) != 4 && (num % 10) != 7){
            return 0;
        }
        num /= 10;
    }
    return 1;
}
vector < pair < int , int > > arr;
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        parent[i] = i;
        sizes[i] = 1;
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &a , &b);
        if(find(a) != find(b)){
            sizes[find(a)] += sizes[find(b)];
            parent[find(b)] = find(a);
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        if(find(i) == i){
            v[sizes[i]].emplace_back(make_pair(0 , 1));
        }
    }
    for(int i = 1 ; i < MX ; ++i){
        if(!v[i].empty()){
            sort(v[i].begin() , v[i].end());
            vector < pair < int , int > > tmp;
            tmp.clear();
            for(auto it : v[i]){
                if(!tmp.empty() && tmp.back().first == it.first){
                    tmp.back().second += it.second;
                }
                else{
                    tmp.emplace_back(it);
                }
            }
            for(auto it : tmp){
                if(it.second > 2){
                    int cnt = it.second - 1 >> 1;
                    v[i + i].emplace_back(make_pair(it.first * 2 + 1 , cnt));
                    it.second -= cnt * 2;
                }
                while(it.second--){
                    arr.emplace_back(make_pair(i , it.first));
                }
            }
        }
    }
    dp[0] = 0;
    for(int i = 1 ; i < MX ; ++i){
        dp[i] = N;
    }
    for(auto it : arr){
        for(int i = MX - 1 ; i >= it.first ; --i){
            dp[i] = min(dp[i] , dp[i - it.first] + it.second + 1);
        }
    }
    int ans = N;
    for(int i = 1 ; i < MX ; ++i){
        if(lucky(i)){
            ans = min(ans , dp[i]);
        }
    }
    ans %= N;
    printf("%d\n" , ans - 1);
}