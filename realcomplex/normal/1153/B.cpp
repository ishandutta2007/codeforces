#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

mt19937 rnd(chrono::steady_clock().now().time_since_epoch().count());

const int N = 105;
bool use[N][N];

int main(){
    fastIO;
    int n, m, h;
    cin >> n >> m >> h;
    ll a[m], b[n];
    ll v[n][m];
    for(int i = 0 ; i < m ; i ++ ){
        cin >> a[i];
    }
    for(int j = 0 ; j < n; j ++ ){
        cin >>  b[j];
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cin >> v[i][j];
        }
    }
    for(int i = 0 ; i < m; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            if(v[j][i] == 1){
                if(a[i] <= b[j]){
                    v[j][i] = a[i];
                    break;
                }
            }
        }
    }
    
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            if(v[i][j] == 1){
                if(b[i] <= a[j]){
                    v[i][j] = b[i];
                    break;
                }
            }
        }
    }
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < m ; j ++ ){
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}