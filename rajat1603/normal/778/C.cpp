#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
int n;
int a[N] , b[N];
int c[N];
char str[5];
vector < int > v[N];
int ans[N];
int child[N][26];
int tmpchild[N][26];
vector < int > g[N];
int par[N];
int depth[N];
int subtree[N];
void dfs1(int node , int parent){
    depth[node] = depth[parent] + 1;
    subtree[node] = 1;
    for(int edge : v[node]){
        int next = a[edge] ^ b[edge] ^ node;
        if(next != parent){
            child[node][c[edge]] = next;
            par[next] = c[edge];
            g[node].emplace_back(next);
            dfs1(next , node);
            subtree[node] += subtree[next];
        }
    }
}
vector < int > tmp[26];
int when[N][26];
int tc;
void join(int nodebig , int nodesmall , int p){
    ++ans[p];
    for(int next : g[nodesmall]){
        int c = par[next];
        if(child[nodebig][c]){
            join(child[nodebig][c] , next , p);
        }
        else if(when[nodebig][c] == tc){
            join(tmpchild[nodebig][c] , next , p);
        }
        else{
            when[nodebig][c] = tc;
            tmpchild[nodebig][c] = next;
        }
    }
}
void dfs2(int node){
    for(int i = 0 ; i < 26 ; ++i){
        tmp[i].clear();
    }
    for(int next1 : g[node]){
        ++ans[depth[node] + 1];
        for(int next2 : g[next1]){
            tmp[par[next2]].emplace_back(next2);
        }
    }
    ++tc;
    for(int i = 0 ; i < 26 ; ++i){
        if(!tmp[i].empty()){
            for(int j = tmp[i].size() - 1 ; j >= 1 ; --j){
                if(subtree[tmp[i][j]] > subtree[tmp[i][j - 1]]){
                    swap(tmp[i][j] , tmp[i][j - 1]);
                }
            }
            for(int j = 1 ; j < tmp[i].size() ; ++j){
                join(tmp[i][0] , tmp[i][j] , depth[node] + 1);
            }
        }
    }
    for(int next : g[node]){
        dfs2(next);
    }
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i < n ; ++i){
        scanf("%d %d" , a + i , b + i);
        scanf("%s" , str);
        c[i] = str[0] - 'a';
        v[a[i]].emplace_back(i);
        v[b[i]].emplace_back(i);
    }
    dfs1(1 , 0);
    dfs2(1);
    int ans1 = subtree[1];
    int ans2 = 1;
    for(int i = 2 ; i <= n ; ++i){
        if(subtree[1] - ans[i] < ans1){
            ans1 = subtree[1] - ans[i];
            ans2 = i;
        }
    }
    printf("%d\n%d\n" , ans1 , ans2 - 1);
}