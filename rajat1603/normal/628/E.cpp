#include "bits/stdc++.h"
using namespace std;
const int N = 3e3 + 3;
int n , m;
char arr[N][N];
int bit[N];
int l[N][N];
int r[N][N];
long long ans = 0;
vector < pair < int , pair < int , int > > > v;
void update(int idx , int val){
    while(idx <= n){
        bit[idx] += val;
        idx += idx & -idx;
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
void solve(){
    sort(v.begin() , v.end());
    for(auto it : v){
        if(it.second.first == -1){
            update(it.second.second , 1);
        }
        else{
            ans += query(it.second.second) - query(it.second.first - 1);
        }
    }
    for(auto it : v){
        if(it.second.first == -1){
            update(it.second.second , -1);
        }
    }
    v.clear();
}
void add(int idx , int val , int vall){
    v.emplace_back(make_pair(-val , make_pair(-1 , idx)));
    v.emplace_back(make_pair(-idx - 1 , make_pair(max(1 , vall) , idx)));
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        scanf("%s" , arr[i] + 1);
    }
    for(int i = 1 ; i <= n ; ++i){
        l[i][0] = 0;
        for(int j = 1 ; j <= m ; ++j){
            l[i][j] = (arr[i][j] == 'z') ? l[i][j - 1] + 1 : 0;
        }
        r[i][m + 1] = 0;
        for(int j = m ; j >= 1 ; --j){
            r[i][j] = (arr[i][j] == 'z') ? r[i][j + 1] + 1 : 0;
        }
    }
    for(int diag = 2 ; diag <= n + m ; ++diag){
        for(int row = max(1 , diag - m) ; row <= min(n , diag - 1) ; ++row){
            int col = diag - row;
            if(arr[row][col] != 'z'){
                solve();
            }
            else{
                add(row , l[row][col] + row , row + 1 - r[row][col]);
            }
        }
        solve();
    }
    printf("%lld" , ans);
}