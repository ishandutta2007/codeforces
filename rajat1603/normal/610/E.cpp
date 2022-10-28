#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
const int K = 10;
int n , m , k;
int arr[N];
char c;
int segtree[SN][K][K];
int start[SN];
int finish[SN];
int lazy[SN];
int type , l , r;
int mat[K][K];
int que = 0;
char tmp[K + 1];
int ans;
void build(int l , int r , int node){
    lazy[node] = -1;
    if(l == r){
        start[node] = arr[l];
        finish[node] = arr[r];
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        for(int i = 0 ; i < k ; ++i){
            for(int j = 0 ; j < k ; ++j){
                segtree[node][i][j] = segtree[node + node][i][j] + segtree[node + node + 1][i][j];
            }
        }
        start[node] = start[node + node];
        finish[node] = finish[node + node + 1];
        ++segtree[node][finish[node + node]][start[node + node + 1]];
    }
}
void push(int l , int r , int node){
    if(lazy[node] != -1){
        for(int i = 0 ; i < k ; ++i){
            for(int j = 0 ; j < k ; ++j){
                segtree[node][i][j] = 0;
            }
        }
        segtree[node][lazy[node]][lazy[node]] = r - l;
        start[node] = lazy[node];
        finish[node] = lazy[node];
        if(l != r){
            lazy[node + node] = lazy[node];
            lazy[node + node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
}
void update(int l , int r , int node , int ql , int qr , int val){
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
    for(int i = 0 ; i < k ; ++i){
        for(int j = 0 ; j < k ; ++j){
            segtree[node][i][j] = segtree[node + node][i][j] + segtree[node + node + 1][i][j];
        }
    }
    start[node] = start[node + node];
    finish[node] = finish[node + node + 1];
    ++segtree[node][finish[node + node]][start[node + node + 1]];
}
int main(){
    scanf("%d %d %d" , &n , &m , &k);
    for(int i = 1 ; i <= n ; ++i){
        c = '#';
        while(!isalpha(c)){
            c = getchar();
        }
        arr[i] = c - 'a';
    }
    build(1 , n , 1);
    while(m--){
        scanf("%d" , &type);
        if(type & 1){
            scanf("%d %d" , &l , &r);
            c = '$';
            while(!isalpha(c)){
                c = getchar();
            }
            update(1 , n , 1 , l , r , int(c - 'a'));
        }
        else{
            ++que;
            scanf("%s" , tmp);
            for(int i = 0 ; i < k ; ++i){
                for(int j = 0 ; j < i ; ++j){
                    mat[tmp[j] - 'a'][tmp[i] - 'a'] = que;
                }
            }
            ans = 1;
            for(int i = 0 ; i < k ; ++i){
                for(int j = 0 ; j < k ; ++j){
                    if(mat[i][j] != que){
                        ans += segtree[1][i][j];
                    }
                }
            }
            printf("%d\n" , ans);
        }
    }
}