#include "bits/stdc++.h"
using namespace std;
const int N = 1e6 + 6;
const int SQN = 1e3 + 3;
int n;
int arr[N];
int pre[N];
int q;
int l , r;
vector < pair < int , int > > v[N];
int ans[N];
int bit[N];
map < int , int > mp;
void update(int idx , int val){
    while(idx){
        bit[idx] ^= val;
        idx -= idx & -idx;
    }
}
int query(int idx){
    int res = 0;
    while(idx <= n){
        res ^= bit[idx];
        idx += idx & -idx;
    }
    return res;
}
int main(){
    scanf("%d" , &n);
    pre[0] = 0;
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr + i);
        pre[i] = pre[i - 1] ^ arr[i];
    }
    scanf("%d" , &q);
    for(int i = 1 ; i <= q ; ++i){
        scanf("%d %d" , &l , &r);
        v[r].emplace_back(make_pair(l , i));
    }
    mp.clear();
    for(int i = 1 ; i <= n ; ++i){
        if(mp.find(arr[i]) != mp.end()){
            update(mp[arr[i]] , arr[i]);
        }
        update(i , arr[i]);
        for(auto it : v[i]){
            ans[it.second] = pre[i] ^ pre[it.first - 1] ^ query(it.first);
        }
        mp[arr[i]] = i;
    }
    for(int i = 1 ; i <= q ; ++i){
        printf("%d\n" , ans[i]);
    }
}