#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
const int SN = 1 << 18;
const int mod[2] = {int(1e9 + 7) , int(1e9 + 9)};
const int base = 11;
int mult(int a , int b , bool k){
    long long res = a;
    res *= b;
    if(res >= mod[k]){
        return res % mod[k];
    }
    return res;
}
int add(int a , int b , bool k){
    int res = a + b;
    if(res >= mod[k]){
        return res - mod[k];
    }
    return res;
}
struct data{
    int val[2];
    int siz;
    int lazy;
    data(){
        val[0] = val[1] = 0;
        siz = 0;
        lazy = -1;
    }
};
int pw[N][2];
data combine(data l , data r){
    data res;
    res.siz = l.siz + r.siz;
    for(int k = 0 ; k < 2 ; ++k){
        res.val[k] = add(mult(l.val[k] , pw[r.siz][k] , k) , r.val[k] , k);
    }
    return res;
}
int n , m , k;
char arr[N];
int val[N][10][2];
data segtree[SN];
int type , l , r , x;
void init(){
    for(int k = 0 ; k < 2 ; ++k){
        pw[0][k] = 1;
        for(int i = 1 ; i <= n ; ++i){
            pw[i][k] = mult(pw[i - 1][k] , base , k);
        }
        for(int i = 0 ; i < 10 ; ++i){
            val[0][i][k] = 0;
            for(int j = 1 ; j <= n ; ++j){
                val[j][i][k] = add(mult(val[j - 1][i][k] , base , k) , i , k);
            }
        }
    }
}
void build(int l , int r , int node){
    if(l == r){
        segtree[node].siz = 1;
        segtree[node].val[0] = arr[l] - '0';
        segtree[node].val[1] = arr[r] - '0';
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
}
void push(int l , int r , int node){
    if(segtree[node].lazy != -1){
        for(int k = 0 ; k < 2 ; ++k){
            segtree[node].val[k] = val[segtree[node].siz][segtree[node].lazy][k];
        }
        if(l != r){
            segtree[node + node].lazy = segtree[node].lazy;
            segtree[node + node + 1].lazy = segtree[node].lazy;
        }
        segtree[node].lazy = -1;
    }
}
void update(int l , int r , int node , int ql , int qr , int val){
    push(l , r , node);
    if(l > qr || r < ql){
        return;
    }
    if(l >= ql && r <= qr){
        segtree[node].lazy = val;
        push(l , r , node);
        return;
    }
    int mid = l + r >> 1;
    update(l , mid , node + node , ql , qr , val);
    update(mid + 1 , r , node + node + 1 , ql , qr , val);
    segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
}
data query(int l , int r , int node , int ql , int qr){
    push(l , r , node);
    if(l > qr || r < ql || ql > qr){
        return data();
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    scanf("%s" , arr + 1);
    init();
    build(1 , n , 1);
    m += k;
    while(m--){
        scanf("%d %d %d %d" , &type , &l , &r , &x);
        if(type & 1){
            update(1 , n , 1 , l , r , x);
        }
        else{
            data tmp1 = query(1 , n , 1 , l + x , r);
            data tmp2 = query(1 , n , 1 , l , r - x);
            if(tmp1.val[0] == tmp2.val[0] && tmp1.val[1] == tmp2.val[1]){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
    }
}