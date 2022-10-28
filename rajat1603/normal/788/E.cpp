#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n;
pair < int , int > inp[N];
int maxval;
int arr[N];
int q;
int t , x;
int presum[N];
int sufsum[N];
int bit[N];
struct data{
    int ans;
    int lft;
    int rgt;
    int pre;
    int suf;
    int cnt;
    data(){
        ans = 0;
        lft = 0;
        rgt = 0;
        pre = 0;
        suf = 0;
        cnt = 0;
    }
    data(int i){
        ans = 0;
        lft = 0;
        rgt = 0;
        pre = presum[i];
        suf = sufsum[i];
        cnt = 1;
    }
    inline void combine(const data &left , const data &right){
        ans = (1LL * left.lft * right.suf + 1LL * right.rgt * left.pre + left.ans + 0LL + right.ans) % mod;
        lft = (left.lft + 1LL * left.pre * right.cnt + right.lft) % mod;
        rgt = (left.rgt + 1LL * left.cnt * right.suf + right.rgt) % mod;
        pre = left.pre + right.pre;
        pre -= (pre >= mod) * mod;
        suf = left.suf + right.suf;
        suf -= (suf >= mod) * mod;
        cnt = left.cnt + right.cnt; 
    }
};
void compress(){
    sort(inp + 1 , inp + 1 + n);
    maxval = 0;
    inp[0].first = inp[1].first - 1;
    for(int i = 1 ; i <= n ; ++i){
        maxval += inp[i - 1].first != inp[i].first;
        arr[inp[i].second] = maxval;
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
void update(int idx){
    while(idx <= n){
        ++bit[idx];
        idx += idx & -idx;
    }
}
void precalc(){
    memset(bit , 0 , sizeof(bit));
    for(int i = 1 ; i <= n ; ++i){
        presum[i] = query(arr[i]);
        update(arr[i]);
    }
    memset(bit , 0 , sizeof(bit));
    for(int i = n ; i >= 1 ; --i){
        sufsum[i] = query(arr[i]);
        update(arr[i]);
    }
}
vector < int > v[N];
vector < data > segtree[N];
int lookup[N];
int answer;
void build(int idx , int l , int r , int node){
    if(l == r){
        segtree[idx][node] = data(v[idx][l - 1]);
    }
    else{
        int mid = l + r >> 1;
        build(idx , l , mid , node + node);
        build(idx , mid + 1 , r , node + node + 1);
        segtree[idx][node].combine(segtree[idx][node + node] , segtree[idx][node + node + 1]);
    }
}
void build(int idx){
    int n = v[idx].size();
    segtree[idx].resize(n * 4);
    build(idx , 1 , n , 1);
    answer += segtree[idx][1].ans;
    answer -= (answer >= mod) * mod;
}
void build(){
    for(int i = 1 ; i <= n ; ++i){
        v[arr[i]].emplace_back(i);
        lookup[i] = v[arr[i]].size();
    }
    for(int i = 1 ; i <= maxval ; ++i){
        build(i);
    }
}
void update(int val , int l , int r , int node , int idx){
    if(l == r){
        if(t == 1){
            segtree[val][node] = data();
        }
        else{
            segtree[val][node] = data(x);
        }
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(val , l , mid , node + node , idx);
        }
        else{
            update(val , mid + 1 , r , node + node + 1 , idx);
        }
        segtree[val][node].combine(segtree[val][node + node] , segtree[val][node + node + 1]);
    }
}
void update(int t , int x){
    int val = arr[x];
    int idx = lookup[x];
    answer -= segtree[val][1].ans;
    answer += (answer < 0) * mod;
    update(val , 1 , v[val].size() , 1 , idx);
    answer += segtree[val][1].ans;
    answer -= (answer >= mod) * mod;
}
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , &inp[i].first);
        inp[i].second = i;
    }
    compress();
    precalc();
    build();
    scanf("%d" , &q);
    while(q--){
        scanf("%d %d" , &t , &x);
        update(t , x);
        printf("%d\n" , answer);
    }
}