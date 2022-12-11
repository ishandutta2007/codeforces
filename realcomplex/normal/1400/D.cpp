#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int M = 3005;
const int N = M * 2;
int pf[N][M];

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0 ; i < n; i ++ ){
        cin >> a[i];
        a[i]--;
        for(int j =0 ; j < 2 * n; j ++ ){
            pf[i][j]=0;
        }
    }
    ll ans = 0;
    for(int i = 0 ; i < n ; i ++ ){
        for(int l = i+1; l < n; l ++ ){
            ans += pf[a[i]][a[i] + a[l]];
        }
        for(int j = i - 1; j >= 0 ;j -- ){
            pf[a[j]][a[j]+a[i]] ++ ;
        }
    }
    cout << ans << "\n";
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