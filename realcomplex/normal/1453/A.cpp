#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int cnt[105];

void solve(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < 105; i ++ ){
        cnt[i] = 0;
    }
    int x, y;
    for(int i = 1; i <= n; i ++ ){
        cin >> x;
        cnt[x] ++ ;
    }
    for(int i = 1; i <= m ; i ++ ){
        cin >> y;
        cnt[y] ++ ;
    }
    int sol = 0;
    for(int i =0  ;i  <  105; i ++ ){
        if(cnt[i] >= 2)
            sol ++ ;
    }
    cout << sol << "\n";
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