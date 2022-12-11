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
        cin >> n;
        ll ans = 0;
        vector<int> a(n);
        for(int i = 0 ;i < n; i ++ ){
            cin >> a[i];
            if(i && a[i] < a[i - 1])
                ans += a[i - 1] - a[i];
        }
        cout << ans << "\n";
    }
    return 0;
}