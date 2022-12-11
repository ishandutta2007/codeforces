#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 505;
char grid[N][N];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++) {
            cin >> grid[i][j];
        }
    }
    int ci;
    for(int j = 1; j <= m; j += 3){
        for(int i = 1; i <= n; i ++ ){
            grid[i][j] = 'X';
        }
        ci = 1;
        if(j + 3 <= m){
            for(int i = 1; i <= n; i ++ ){
                if(grid[i][j + 1] == 'X' || grid[i][j + 2] == 'X'){
                    ci = i;
                }
            }
            grid[ci][j+1] = 'X';
            grid[ci][j+2] = 'X';
        }
        else{
            bool pp = false;
            for(int i = 1; i <= n; i ++ ){
                pp = false;
                if(j + 1 <= m && grid[i][j + 1] == 'X') pp = true;
                if(j + 2 <= m && grid[i][j + 2] == 'X') pp = true;
                if(pp){
                    for(int x = 1; x <= 2; x ++ ){
                        if(j + x <= m){
                            grid[i][j + x] = 'X';
                        }
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n; i ++ ){
        for(int j = 1; j <= m ; j ++) {
            cout << grid[i][j];
        }
        cout << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int it = 1; it <= tc; it ++ )
        solve();
    return 0;
}