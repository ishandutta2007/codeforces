#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 355;
int A[N][N];

void solve(){
    int n;
    cin >> n;
    for(int i = 0 ; i < n; i ++ ){
        for(int j = 0 ; j < n; j ++ ){
            A[i][j] = 0;
        }
    }
    int v;
    for(int i = 0 ; i < n; i ++) {
        for(int j = 0 ; j < n ; j ++ ){
            A[i][(i + j) % n] = (j * i) % n;
        }
    }
    int x;
    for(int i = 0 ; i < n; i ++ ){
        cin >> x;
        for(int j = 0; j < n; j ++ ){
            A[j][i] += x;
            A[j][i] %= n;
        }
    }
    for(int i = 0 ; i < n; i ++) {
        for(int j = 0 ; j < n; j ++) {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){
    fastIO;
    //freopen("in.txt", "r", stdin);
    solve();
    return 0;
}