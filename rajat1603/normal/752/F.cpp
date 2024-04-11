#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , k;
int a , b;
int arr[N];
int sub[N];
int guess;
vector < int > v[N];
bool mark[N];
void dfs(int node , int parent){
    for(int next : v[node]){
        if(next != parent){
            dfs(next , node);
            sub[node] += sub[next];
        }
    }
}
int find(int node , int parent){
    for(int next : v[node]){
        if(next != parent){
            if(sub[next] > k){
                return find(next , node);
            }
        }
    }
    return node;
}
vector < int > g[N];
int cnt;
vector < int > cur;
void dfs2(int node , int parent){
    if(mark[node]){
        cur.emplace_back(node);
    }
    for(int next : v[node]){
        if(next != parent){
            dfs2(next , node);
        }
    }
}
int main(){
    scanf("%d %d" , &n , &k);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , &a , &b);
        v[a].emplace_back(b);
        v[b].emplace_back(a);
    }
    for(int i = 1 ; i <= k + k ; ++i){
        scanf("%d" , arr + i);
        ++sub[arr[i]];
        mark[arr[i]] = 1;
    }
    dfs(1 , 0);
    guess = find(1 , 0);
    cnt = 0;
    for(int next : v[guess]){
        cur.clear();
        dfs2(next , guess);
        if(!cur.empty()){
            ++cnt;
            g[cnt] = cur;
        }
    }
    if(mark[guess]){
        ++cnt;
        g[cnt].emplace_back(guess);
    }
    priority_queue < pair < int , int > > pq;
    for(int i = 1 ; i <= cnt ; ++i){
        pq.push(make_pair(int(g[i].size()) , i));
    }
    printf("%d\n" , 1);
    printf("%d\n" , guess);
    while(!pq.empty()){
        auto it1 = pq.top();
        pq.pop();
        auto it2 = pq.top();
        pq.pop();
        --it1.first;
        --it2.first;
        printf("%d %d %d\n" , g[it1.second].back() , g[it2.second].back() , guess);
        g[it1.second].pop_back();
        g[it2.second].pop_back();
        if(it1.first){
            pq.push(it1);
        }
        if(it2.first){
            pq.push(it2);
        }
    }
}