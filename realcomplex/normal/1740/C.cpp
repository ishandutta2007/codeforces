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
        vector<ll> a;
        ll x;
        for(int i = 0 ; i < n; i ++) {
            cin >> x;
            a.push_back(x);
        }
        sort(a.begin(), a.end());
        ll res = 0ll;
        for(int i = 0 ; i + 1 < n; i ++ ){
            res = max(res, a[n - 1] - a[i] + a[i + 1] - a[i]);
        }
        for(int i = 1; i < n; i ++ ){
            res = max(res, a[i] - a[i - 1] + a[i] - a[0]);
        }
        cout << res << "\n";
    }
    return 0;
}