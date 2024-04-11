#include <bits/stdc++.h>
using namespace std ;
const int N = 501 ;
int n , m , q ;
bool arr[N][N] ;
int ans[N];
int x , y ;
int main() {
    cin >> n >> m >> q ;
    for(int i = 1 ; i <= n ; ++i) {
        for(int j = 1 ; j <= m ; ++j) {
            cin >> arr[i][j] ;
        }
    }
    for(int i = 1 ; i <= n ; ++i) {
        for(int cur = 0 , j = 1 ; j <= m ; ++j) {
            cur = arr[i][j] ? cur + 1 : 0 ;
            ans[i] = max( ans[i] , cur ) ;
        }
    }
    for(int Q = 1 , final_ans = 0; Q <= q ; ++Q , final_ans = 0) {
        cin >> x >> y ;
        arr[x][y] ^= 1 ;
        ans[x] = 0 ;
        for(int cur = 0 , j = 1 ; j <= m ; ++j) {
            cur = arr[x][j] ? cur + 1 : 0 ;
            ans[x] = max( ans[x] , cur ) ;
        }
        for(int i = 1 ; i <= n ; ++i) {
            final_ans = max( final_ans , ans[i] ) ;
        }
        cout << final_ans << "\n" ;
    }
}