#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 140;
ll F[N][N];

void calc(ll k){
    for(int i = 0 ; i < N; i ++ ){
        for(int j = 0 ; j < N; j ++ ){
            F[i][j]=0;
        }
    }
    F[0][0]=k;
    for(int i = 0 ; i < 120; i ++ ){
        for(int j = 0 ; j < 120; j ++ ){
            F[i][j+1] += (F[i][j] + 1) / 2;
            F[i+1][j] += F[i][j] / 2;
        }
    }
}

void solve(){
    ll tt;
    ll x, y;
    cin >> tt >> x >> y;
    calc(tt - x - y);
    ll v1 = F[x][y];
    calc(tt - x - y + 1);
    ll v2 = F[x][y];
    if(v1 != v2){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
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