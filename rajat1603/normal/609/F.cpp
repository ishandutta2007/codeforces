#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n , m;
pair < int , int > arr[N];
long long segtree[SN];
int cnt[N];
int a , b;
long long value;
multiset < pair < int , int > > s;
map < int , int > m1;
long long ans[N];
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = arr[l].first + arr[r].second;
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
    }
}
int query(int l , int r , int node , int ql , int qr , int val){
    if(l > qr || r < ql || segtree[node] < val){
        return -1;
    }
    if(l == r){
        value = segtree[node];
        return l;
    }
    int mid = l + r >> 1;
    int ret = query(l , mid , node + node , ql , qr , val);
    if(ret == -1){
        ret = query(mid + 1 , r , node + node + 1 , ql , qr , val);
    }
    return ret;
}
void update(int l , int r , int node , int idx , long long val){
    if(l == r){
        segtree[node] = val;
    }
    else{
        int mid = l + r >> 1;
        if(idx <= mid){
            update(l , mid , node + node , idx , val);
        }
        else{
            update(mid + 1 , r , node + node + 1 , idx , val);
        }
        segtree[node] = max(segtree[node + node] , segtree[node + node + 1]);
    }
}
void dfs(int l , int r , int node){
    if(l == r){
        ans[m1[arr[l].first]] = segtree[node] - arr[l].first;
    }
    else{
        int mid = l + r >> 1;
        dfs(l , mid , node + node);
        dfs(mid + 1 , r , node + node + 1);
    }
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d %d" , &arr[i].first , &arr[i].second);
        m1[arr[i].first] = i;
    }
    sort(arr + 1 , arr + 1 + n);
    build(1 , n , 1);
    while(m--){
        scanf("%d %d" , &a , &b);
        if(a >= arr[1].first){
            int idx = lower_bound(arr + 1 , arr + 1 + n , make_pair(a , INT_MAX)) - arr - 1;
            int idx2 = query(1 , n , 1 , 1 , idx , a);
            if(idx2 == -1){
                s.insert(make_pair(a , b));
            }
            else{
                value += b;
                ++cnt[m1[arr[idx2].first]];
                while(!s.empty()){
                    auto it = s.lower_bound(make_pair(arr[idx2].first , -1));
                    if(it != s.end()){
                        if(it -> first <= value){
                            value += it -> second;
                            ++cnt[m1[arr[idx2].first]];
                            s.erase(it);
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                update(1 , n , 1 , idx2 , value);
            }
        } 
    }
    dfs(1 , n , 1);
    for(int i = 1 ; i <= n ; ++i){
        printf("%d %lld\n" , cnt[i] , ans[i]);
    }
}