#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
int n;
int arr[N];
int segtree[SN];
int lazy[SN];
int q;
int ql , qr , val;
void build(int l , int r , int node){
    lazy[node] = 0;
    if(l == r){
        segtree[node] = arr[l];
    }
    else{
        int mid = l + r >> 1;
        int lc = node + node;
        int rc = lc | 1;
        build(l , mid , lc);
        build(mid + 1 , r , rc);
        segtree[node] = min(segtree[lc] , segtree[rc]);
    }
}
void push(int l , int r , int node){
    segtree[node] += lazy[node];
    if(l != r){
        int lc = node + node;
        int rc = lc | 1;
        lazy[lc] += lazy[node];
        lazy[rc] += lazy[node];
    }
    lazy[node] = 0;
}
void update(int l , int r , int node){
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
    int lc = node + node;
    int rc = lc | 1;
    update(l , mid , lc);
    update(mid + 1 , r , rc);
    segtree[node] = min(segtree[lc] , segtree[rc]);
}
int query(int l , int r , int node){
    push(l , r , node);
    if(l > qr || r < ql){
        return INT_MAX;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    int lc = node + node;
    int rc = lc | 1;
    return min(query(l , mid , lc) , query(mid + 1 , r , rc));
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    build(1 , n , 1);
    cin >> q;
    cin.get();
    while(q--){
        string temp;
        getline(cin , temp);
        stringstream ss(temp);
        int ctr = 0;
        int tmp;
        while(ss >> tmp){
            ++ctr;
            if(ctr == 1){
                ql = tmp + 1;
            }
            else if(ctr == 2){
                qr = tmp + 1;
            }
            else{
                val = tmp;
            }
        }
        if(ctr == 3){
            if(ql <= qr){
                update(1 , n , 1);
            }
            else{
                int t = qr;
                qr = n;
                update(1 , n , 1);
                qr = t;
                ql = 1;
                update(1 , n , 1);
            }
        }
        else{
            int res;
            if(ql <= qr){
                res = query(1 , n , 1);
            }
            else{
                int t = qr;
                qr = n;
                res = query(1 , n , 1);
                qr = t;
                ql = 1;
                res = min(res , query(1 , n , 1));
            }
            cout << res << "\n";
        }
    }
}