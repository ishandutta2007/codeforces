#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int SN = 1 << 19;
const int inf = 1e8 + 8;
int n , q;
char str[N];
int a , b;
struct data{
    int val[5][5];  
};
data get(char c){
    data res;
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            res.val[i][j] = inf;
        }
        res.val[i][i] = 0;
    }
    if(c == '2'){
        res.val[0][1] = 0;
        res.val[0][0] = 1;
    }
    else if(c == '0'){
        res.val[1][2] = 0;
        res.val[1][1] = 1;
    }
    else if(c == '1'){
        res.val[2][3] = 0;
        res.val[2][2] = 1;
    }
    else if(c == '6'){
        res.val[3][3] = 1;
        res.val[4][4] = 1;
    }
    else if(c == '7'){
        res.val[3][4] = 0;
        res.val[3][3] = 1;
    }
    return res;
}
data combine(data l , data r){
    data res;
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            res.val[i][j] = inf;
        }
    }
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            for(int k = 0 ; k < 5 ; ++k){
                res.val[i][j] = min(res.val[i][j] , l.val[i][k] + r.val[k][j]);
            }
        }
    }
    return res;
}
data segtree[SN];
void build(int l , int r , int node){
    if(l == r){
        segtree[node] = get(str[l]);
    }
    else{
        int mid = l + r >> 1;
        build(l , mid , node + node);
        build(mid + 1 , r , node + node + 1);
        segtree[node] = combine(segtree[node + node] , segtree[node + node + 1]);
    }
    /*cout << l << " " << r << endl;
    for(int i = 0 ; i < 5 ; ++i){
        for(int j = 0 ; j < 5 ; ++j){
            cout << segtree[node].val[i][j] << " ";
        }
        cout << endl;
    }*/
}
data query(int l , int r , int node , int ql , int qr){
    if(l > qr || r < ql){
        return get('9');
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = l + r >> 1;
    return combine(query(l , mid , node + node , ql , qr) , query(mid + 1 , r , node + node + 1 , ql , qr));
}
int main(){
    scanf("%d %d" , &n , &q);
    scanf("%s" , str + 1);
    build(1 , n , 1);
    while(q--){
        scanf("%d %d" , &a , &b);
        int ans = query(1 , n , 1 , a , b).val[0][4];
        if(ans >= inf){
            ans = -1;
        }
        printf("%d\n" , ans);
    }
}