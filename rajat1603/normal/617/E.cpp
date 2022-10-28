#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int MAX = 1 << 20;
const int SQN = 430;
int n , m , k;
int arr[N];
struct query{
    int l;
    int r;
    int idx;
    bool operator < (const query &b) const {
        if(int(l / SQN) == int(b.l / SQN)){
            return r < b.r;
        }
        return l < b.l;
    }
};
query Q[N];
long long ans[N];
int curl = 1;
int curr = 0;
long long counter = 0;
vector < int > v[2][MAX];
int pre[N];
int suf[N];
int cur = 0;
int get(int l , int r , int k , int val){
    return lower_bound(v[k][val].begin() , v[k][val].end() , r + 1) - lower_bound(v[k][val].begin() , v[k][val].end() , l);
}
void add(int idx , int type){
    if(type == 1){
        counter += get(curl , idx , 1 , k ^ suf[idx + 1]);
    }
    else{
        counter += get(idx , curr , 0 , k ^ pre[idx - 1]);
    }
}
void erase(int idx , int type){
    if(type == 1){
        counter -= get(curl , idx , 1 , k ^ suf[idx + 1]);
    }
    else{
        counter -= get(idx , curr , 0 , k ^ pre[idx - 1]);
    }
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        cur ^= arr[i];
        pre[i] = cur;
        v[0][cur].emplace_back(i);
    }
    for(int i = 1 ; i <= n ; ++i){
        v[1][cur].emplace_back(i);
        suf[i] = cur;
        cur ^= arr[i];
    }
    for(int i = 1 ; i <= m ; ++i){
        scanf("%d %d" , &Q[i].l , &Q[i].r);
        Q[i].idx = i;
    }
    sort(Q + 1 , Q + 1 + m);
    for(int i = 1 ; i <= m ; ++i){
        while(curr < Q[i].r){
            add(++curr , 1);
        }
        while(curl > Q[i].l){
            add(--curl , 0);
        }
        while(curr > Q[i].r){
            erase(curr-- , 1);
        }
        while(curl < Q[i].l){
            erase(curl++ , 0);
        }
        ans[Q[i].idx] = counter;
    }
    for(int i = 1 ; i <= m ; ++i){
        printf("%lld\n" , ans[i]);
    }
}