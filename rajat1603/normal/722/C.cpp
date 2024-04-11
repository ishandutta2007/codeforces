#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const long long inf = 1e15;
const long long secret = -inf - inf - 1;
int n;
long long arr1[N];
int arr2[N];
struct data{
    long long pre;
    long long suf;
    long long sum;
    long long ans;
    data(long long _pre = 0 , long long _suf = 0 , long long _sum = 0 , long long _ans = 0){
        pre = max(pre , -inf);
        pre = _pre;
        suf = _suf;
        suf = max(suf , -inf);
        sum = _sum;
        sum = max(sum , -inf);
        ans = _ans;
        ans = max(ans , -inf);
    }
};
data combine(data a , data b){
    return data(max(a.pre , a.sum + b.pre) , max(b.suf , b.sum + a.suf) , a.sum + b.sum , max(max(a.ans , b.ans) , a.suf + b.pre));
}
struct tree{
    data segtree[SN];
    long long lazy[SN];
    void build(int l , int r , int node){
        lazy[node] = secret;
        if(l == r){
            segtree[node] = data(arr1[l] , arr1[r] , arr1[l] , arr1[r]);
        }
        else{
            int mid = l + r >> 1;
            build(l , mid , node + node);
            build(mid + 1 , r , node + node + 1);
            segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
        }
    }
    void push(int l , int r , int node){
        if(lazy[node] != secret){
            segtree[node] = data(max(lazy[node] , lazy[node] * (r - l + 1LL)) , max(lazy[node] , lazy[node] * (r - l + 1LL)) , lazy[node] * (r - l + 1LL) , max(lazy[node] , lazy[node] * (r - l + 1LL)));
            if(l != r){
                lazy[node + node] = lazy[node];
                lazy[node + node + 1] = lazy[node];
            }
            lazy[node] = secret;
        }
    }
    void update(int l , int r , int node , int ql , int qr , long long val){
        push(l , r , node);
        if(l > qr || r < ql){
            return;
        }
        if(l >= ql && r <= qr){
            lazy[node] = val;
            push(l , r , node);
            return;
        }
        int mid = l + r >> 1;
        update(l , mid , node + node , ql , qr , val);
        update(mid + 1 , r , node + node + 1 , ql , qr , val);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
    data query(int l , int r , int node , int ql , int qr){
        if(l > qr || r < ql){
            return data(-inf , -inf , 0LL , -inf);
        }
        if(l >= ql && r <= qr){
            return segtree[node];
        }
        int mid = l + r >> 1;
        return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
    }
};
tree rdtree;
int main(){
    scanf("%d" , &n);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%lld" , arr1 + i);
    }
    for(int i = 1 ; i <= n ; ++i){
        scanf("%d" , arr2 + i);
    }
    rdtree.build(1 , n , 1);
    for(int i = 1 ; i <= n ; ++i){
        rdtree.update(1 , n , 1 , arr2[i] , arr2[i] , -inf);
        printf("%lld\n" , max(0LL , rdtree.query(1 , n , 1 , 1 , n).ans));
    }
}