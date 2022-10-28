#include "bits/stdc++.h"
using namespace std;
const int N = 5e5 + 5;
int n , q;
int inp;
char str[N] = {NULL};
int vi , hi;
vector < pair < int , int > > levels[N];
vector < int > v[N];
int start[N];
int finish[N];
int timer = 0;
void dfs(int node , int depth){
    start[node] = ++timer;
    int temp = levels[depth][levels[depth].size() - 1].second;
    levels[depth].emplace_back(make_pair(timer , temp ^ (1 << (str[node] - 'a'))));
    for(int next : v[node]){
        dfs(next , depth + 1);
    }
    finish[node] = timer;
}
int main(){
    scanf("%d %d" , &n , &q);
    levels[1].emplace_back(make_pair(0 , 0));
    for(int i = 2 ; i <= n ; ++i){
        scanf("%d" , &inp);
        v[inp].emplace_back(i);
        levels[i].emplace_back(make_pair(0 , 0));
    }
    scanf("%s" , str + 1);
    dfs(1 , 1);
    while(q--){
        scanf("%d %d" , &vi , &hi);
        auto it = lower_bound(levels[hi].begin() , levels[hi].end() , make_pair(finish[vi] + 1 , -1));
        --it;
        auto it2 = lower_bound(levels[hi].begin() , levels[hi].end() , make_pair(start[vi] , -1));
        --it2;
        int sz = it - it2;
        int x = it -> second ^ it2 -> second;
        if(sz & 1){
            if((x & -x) == x){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
        else{
            if(!x){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
    }
}