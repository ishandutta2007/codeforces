#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
int n , q;
int x , y , k;
string str;
class tree{
    int segtree[SN];
    int lazy[SN];
    void push(int l , int r , int node){
        if(lazy[node] == -1){
            return;
        }
        segtree[node] = lazy[node] * (r - l + 1);
        if(l != r){
            lazy[node + node] = lazy[node];
            lazy[node + node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
    void update(int l , int r , int node , int ql , int qr , bool val){
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
        segtree[node] = segtree[node + node] + segtree[node + node + 1];
    }
    int query(int l , int r , int node , int ql , int qr){
        push(l , r , node);
        if(l > qr || r < ql){
            return 0;
        }
        if(l >= ql && r <= qr){
            return segtree[node];
        }
        int mid = l + r >> 1;
        return query(l , mid , node + node , ql , qr) + query(mid + 1 , r , node + node + 1 , ql , qr);
    }
public:
    tree(){
        memset(segtree , 0 , sizeof(int) * SN);
        memset(lazy , -1 , sizeof(int) * SN);
    }
    void update(int l , int r , bool val){
        update(1 , n , 1 , l , r , val);
    }
    int query(int l , int r){
        return query(1 , n , 1 , l , r);
    }
};
tree segtree[26];
int main(){
    cin >> n >> q;
    cin >> str;
    str = " " + str;
    for(int i = 1 ; i <= n ; ++i){
        segtree[str[i] - 'a'].update(i , i , 1);
    }
    while(q--){
        cin >> x >> y >> k;
        if(!k){
            int cur = x;
            for(int i = 25 ; i >= 0 ; --i){
                int cnt = segtree[i].query(x , y);
                segtree[i].update(x , y , 0);
                if(cnt > 0){
                    segtree[i].update(cur , cur + cnt - 1 , 1);
                }
                cur += cnt;
            }
        }
        else{
            int cur = x;
            for(int i = 0 ; i < 26 ; ++i){
                int cnt = segtree[i].query(x , y);
                segtree[i].update(x , y , 0);
                if(cnt > 0){
                    segtree[i].update(cur , cur + cnt - 1 , 1);
                }
                cur += cnt;
            }
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j < 26 ; ++j){
            if(segtree[j].query(i , i)){
                cout << char(j + 'a');
                break;
            }
        }
    }
}