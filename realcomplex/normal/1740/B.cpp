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
    for(int iq = 1; iq <= tc; iq ++ ){
        int n;
        cin >> n;
        ll res = 0ll;
        ll maxi = 0ll;
        ll a, b;
        for(int i = 1; i <= n; i ++ ){
            cin >> a >> b;
            res += min(a, b);
            maxi = max(maxi, a);
            maxi = max(maxi, b);
        }
        res += maxi;
        cout << res * 2ll << "\n";
    }
    return 0;
}