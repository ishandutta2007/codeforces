#include "bits/stdc++.h"
using namespace std;
const int N = 1e4 + 4;
int n , q;
int arr[N];
int pos[N];
int bit[N];
int l[N] , r[N] , x[N];
vector < int > v[N];
bool ans[N];
void update(int idx){
    while(idx <= n){
        ++bit[idx];
        idx += idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx){
        res += bit[idx];
        idx -= idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        pos[arr[i]] = i;
    }
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d %d" , l + i , r + i , x + i);
        v[x[i]].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        update(pos[i]);
        for(int idx : v[pos[i]]){
            if(query(r[idx]) - query(l[idx] - 1) == x[idx] - l[idx] + 1){
                ans[idx] = 1;
            }
        }
    }
    for(int i = 1 ; i <= q ; ++i){
        puts(ans[i] ? "Yes" : "No");
    }
}