#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main(){
    fastIO;
    int tc;
    cin >> tc;
    for(int t = 0; t < tc; t ++ ){
        int n;
        ll k;
        cin >> n >> k;
        int mx = -(int)2e9;
        int low = (int)2e9;
        vector<int> a(n);
        for(int i = 0 ; i < n; i ++ ){
            cin >> a[i];
            mx = max(mx, a[i]);
            low = min(low, a[i]);
        }
        for(int i = 0; i < n; i ++ ){
            if(k % 2 == 1) cout << mx - a[i] << " ";
            else cout << a[i] - low << " ";
        }
        cout << "\n";

    }
    return 0;
}