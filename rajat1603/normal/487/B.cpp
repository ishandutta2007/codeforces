#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 1;
const int LN = 17;
int n , s , l;
int arr[N];
int rmq[LN][N];
int rmx[LN][N];
int logtable[N];
bool dif(int x , int y){
    int k = logtable[y - x + 1];
    int mn = min(rmq[k][x] , rmq[k][y - (1 << k) + 1]);
    int mx = max(rmx[k][x] , rmx[k][y - (1 << k) + 1]);
    return ((mx - mn) <= s);
}
int segtree[N << 2];
void update(int l , int r , int node , int idx , int val){
    if(l == r){
        segtree[node] = val;
    }
    else{
        int mid = (l + r) >> 1;
        int lc = node + node;
        int rc = lc | 1;
        if(idx <= mid){
            update(l , mid , lc , idx , val);
        }
        else{
            update(mid + 1 , r , rc , idx , val);
        }
        segtree[node] = min(segtree[lc] , segtree[rc]);
    }
}
int query(int l , int r , int node , int ql , int qr){
    if(ql > r || qr < l){
        return n + 1;
    }
    if(l >= ql && r <= qr){
        return segtree[node];
    }
    int mid = (l + r) >> 1;
    int lc = node + node;
    int rc = lc | 1;
    return min(query(l , mid , lc , ql , qr) , query(mid + 1 , r , rc , ql , qr));
}
int main(){
    cin >> n >> s >> l;
    if(l > n){
        cout << -1;
        return 0;
    }
    logtable[0] = -1;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
        rmq[0][i] = arr[i];
        rmx[0][i] = arr[i];
        logtable[i] = logtable[i >> 1] + 1;
        update(1 , n + 1 , 1 , i , n + 1);
    }
    for(int i = 1 ; i < LN ; ++i){
        int y = 1 << (i - 1);
        int x = y + y;
        for(int j = 1 ; j + x - 1 <= n ; ++j){
            rmq[i][j] = min(rmq[i - 1][j] , rmq[i - 1][j + y]);
            rmx[i][j] = max(rmx[i - 1][j] , rmx[i - 1][j + y]);
        }
    }
    for(int i = n ; i > n - l ; --i){
        if(dif(i , n)){
            update(1 , n + 1 , 1 , i , n + 1);
        }
        else{
            cout << -1;
            return 0;
        }
    }
    update(1 , n + 1 , 1 , n - l + 1 , 1);
    update(1 , n + 1 , 1 , n + 1 , 0);
    for(int i = n - l  ; i >= 1 ; --i){
        if(dif(i , i + l - 1)){
            int start = i + l - 1;
            int finish ;
            if(dif(i , n)){
                finish = n;
            }
            else{
                int l = start;
                int r = n;
                while(l <= r){
                    int mid = (l + r) >> 1;
                    if(dif(i , mid)){
                        l = mid + 1;
                    }
                    else{
                        r = mid - 1;
                    }
                }
                finish = r;
            }
            int temp = min(n + 1 , query(1 , n + 1 , 1 , start + 1 , finish + 1) + 1);
            update(1 , n + 1 , 1 , i , temp);
        }
        else{
            update(1 , n + 1 , 1 , i , n + 1);
        }
    }
    int ans = query(1 , n + 1 , 1 , 1 , 1);
    if(ans == n + 1){
        ans = -1;
    }
    cout << ans;
}