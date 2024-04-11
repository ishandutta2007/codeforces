#include "bits/stdc++.h"
using namespace std;
const int N = 3e5 + 5;
const int MAX = 1e6 + 6;
int n , q;
int l , r;
vector < int > bit[MAX];
vector < int > v[MAX];
int sz[MAX];
int k;
int lst;
int inp;
int ans;
void upd(int x){
    while(x){
        ++sz[x];
        x -= x & - x;
    }
}
void update(int i , int j){
    while(i){
        bit[i][--sz[i]] = j;
        i -= i & -i;
    }
}
int get(int node , int l , int r){
    return lower_bound(bit[node].begin() , bit[node].end() , r + 1) - lower_bound(bit[node].begin() , bit[node].end() , l);
}
int query(int ql , int qr , int idx){
    int ret = 0;
    while(idx < MAX){
        ret += get(idx , ql , qr);
        idx += idx & -idx;
    }
    return ret;
}
int main(){
    scanf("%d %d" , &n , &q);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &l , &r);
        v[l].emplace_back(r);
        upd(r);
    }
    for(int i = 1 ; i < MAX ; ++i){
        bit[i].resize(sz[i]);
    }
    for(int i = MAX - 1 ; i >= 1 ; --i){
        for(int x : v[i]){
            update(x , i);
        }
    }
    while(q--){
        scanf("%d" , &k);
        lst = 1;
        ans = 0;
        while(k--){
            scanf("%d" , &inp);
            ans += query(lst , inp , inp);
            lst = inp + 1;
        }
        printf("%d\n" , ans);
    }
}