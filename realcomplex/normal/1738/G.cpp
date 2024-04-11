#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 1010;
int has[N][N];
int soln[N][N];
int las[2][N];

void solve(){
    int n, k;
    cin >> n >> k;
    char f;
    for(int i = 0 ; i <= n + 1; i ++ ){
        for(int j = 0 ; j <= n + 1; j ++ ){
            has[i][j] = 0;
        }
    }
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cin >> f;
            has[i][j] = f - '0';
            soln[i][j] = 1;
        }
    }
    for(int i = 0 ; i <= n + 1; i ++ ){
        las[0][i] = 0;
        las[1][i] = 0;
    }
    int pv;
    // diagonal idx = j - i + n
    for(int i = n - k + 1; i >= 1; i -- ){
        las[0][1] ++ ;
        while((las[0][1] <= las[0][2] || las[0][1] <= las[1][2] || has[las[0][1]][las[0][1]] == 0) && las[0][1] <= n){
            las[0][1] ++ ;
        }
        if(las[0][1] > n){
            cout << "NO\n";
            return;
        }
        soln[las[0][1]][las[0][1]] = 0;
        las[1][1] = las[0][1];
        for(int p = 2; p <= i ; p ++ ){
            las[0][p] ++ ;
            las[1][p] ++ ;
            while((las[0][p] <= las[0][p + 1] || las[0][p] < las[0][p-1] || has[las[0][p] + p - 1][las[0][p]] == 0) && las[0][p] + p - 1 <= n){
                las[0][p] ++ ;
            }
            while((las[1][p] <= las[1][p + 1] || las[1][p] < las[1][p-1] || has[las[1][p]][las[1][p] + p - 1] == 0) && las[1][p] + p - 1 <= n){
                las[1][p] ++ ;
            }
            if((p - 1) + las[0][p] > n || (p - 1) + las[1][p] > n){
                cout << "NO\n";
                return;
            }

            soln[las[0][p] + p - 1][las[0][p]] = 0;
            soln[las[1][p]][las[1][p] + p - 1] = 0;
        }
    }
    cout << "YES\n";
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= n; j ++ ){
            cout << soln[i][j];
        }
        cout << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    int tc;
    cin >> tc;
    for(int iq = 1; iq <= tc; iq ++ ){
        solve();
    }
    return 0;
}