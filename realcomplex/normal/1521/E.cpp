#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)1e5 + 10;

int A[N];
const int M = 2005;
int F[M][M];

void solve(){
    int m, k;
    cin >> m >> k;
    int mx = 0;
    for(int i = 1; i <= k ; i ++ ){
        cin >> A[i];
        mx = max(mx, A[i]);
    }
    for(int n = 1; n <= m ; n ++ ){
        if(mx <= n * ((n+1)/2) && m <= n * n - (n/2)*(n/2)){
            vector<pii> ord;
            for(int i = 1; i <= k ;i ++ ){
                ord.push_back(mp(A[i], i));
            }
            sort(ord.begin(), ord.end());
            reverse(ord.begin(), ord.end());
            vector<pii> cells;
            for(int i = 1; i <= n; i += 2){
                for(int j = 2; j <= n; j += 2){
                    cells.push_back(mp(i, j));
                }
            }
            for(int i = 1; i <= n; i += 2){
                for(int j = 1; j <= n; j += 2){
                    cells.push_back(mp(i, j));
                }
            }
            for(int i = 2; i <= n; i += 2){
                for(int j = 1; j <= n; j += 2){
                    cells.push_back(mp(i, j));
                }
            }
            for(int i = 1; i <= n; i ++ ){
                for(int j = 1; j <= n; j ++ ){
                    F[i][j]=0;
                }
            }
            int cur = 0;
            for(auto x : ord){
                for(int j = 0 ; j < x.fi; j ++ ){
                    F[cells[cur].fi][cells[cur].se] = x.se;
                    cur ++ ;
                }
            }
            cout << n << "\n";
            for(int i = 1; i <= n; i ++ ){
                for(int j = 1; j <= n; j ++){
                    cout << F[i][j] << " ";
                }
                cout << "\n";
            }
            return;
        }
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}