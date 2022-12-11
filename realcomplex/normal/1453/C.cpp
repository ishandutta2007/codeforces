#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 2005;
char dig[N][N];
int da[N][N];

void solve(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> dig[i][j];
            da[i][j] = dig[i][j] - '0';
        }
    }
    int mx, mn;
    int sol = 0;
    for(int d = 0; d < 10 ; d ++ ){
        sol = 0;
        for(int i = 1; i <= n; i ++ ){
            mx = 0, mn = n+1;
            for(int j = 1; j <= n; j ++ ){
                if(da[i][j] == d){
                    mx = max(mx,j);
                    mn = min(mn,j);
                }
            }
            sol = max(sol, max(i-1,n-i)*(mx-mn));
            mx = 0, mn = n + 1;
            for(int j = 1; j <= n; j ++ ){
                if(da[j][i] == d){
                    mx = max(mx, j);
                    mn = min(mn, j);
                }
            }
            sol = max(sol, max(i-1,n-i)*(mx-mn));
        }
        mx = 0, mn = n + 1;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(da[i][j] == d){
                    mx = max(mx,j);
                    mn = min(mn,j);
                }
            }
        }
        int hh;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(da[i][j] == d){
                    hh = max(mx-j,j-mn);
                    sol = max(sol, hh*max(i-1,n-i));
                }
            }
        }
        mx = 0;
        mn = n + 1;
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(da[i][j] == d){
                    mx = max(mx, i);
                    mn = min(mn, i);
                }
            }
        }
        for(int i = 1; i <= n; i ++ ){
            for(int j = 1; j <= n; j ++ ){
                if(da[i][j] == d){
                    hh = max(mx-i,i-mn);
                    sol = max(sol, hh*max(j-1,n-j));
                }
            }
        }
        cout << sol << " ";
    }
    cout << "\n";
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}