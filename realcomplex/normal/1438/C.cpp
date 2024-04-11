#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, m;
    cin >> n >> m;
    int a;
    int xr;
    for(int i = 1; i <= n; i ++ ){
        for(int j = 1; j <= m; j ++ ){
            xr = (i&1)^(j&1);
            cin >> a;
            xr ^= (a&1);
            cout << a + xr << " ";
        }
        cout << "\n";
    }
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ ){
        solve();
    }
    return 0;
}