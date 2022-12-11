#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

void solve(){
    int n, k;
    cin >> n >> k;
    int d = n - k;
    for(int i = 1; i < k - d; i ++ ){
        cout << i << " ";
    }
    int m = k;
    for(int i = k - d ; i <= k; i ++ ){
        cout << m << " ";
        m--;
    }
    cout << "\n";
}

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 1; t <= tc; t ++ )
        solve();
    return 0;
}