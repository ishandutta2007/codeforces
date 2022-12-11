#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = 5010;
ll A[N];

int main(){
    fastIO;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i ++ ){
        cin >> A[i];
    }
    ll res = (ll)1e18;
    ll cur, las;
    ll cc;
    for(int p = 1; p <= n; p ++ ){
        cur = 0;
        las = 0;
        for(int j = p + 1; j <= n; j ++ ){
            cc = (las + A[j]) / A[j];
            cur += cc;
            las = cc * 1ll * A[j];
        }
        las = 0;
        for(int j = p - 1; j >= 1; j -- ){
            cc = (las + A[j]) / A[j];
            cur += cc;
            las = cc * 1ll * A[j];
        }
        res = min(res, cur);
    }
    cout << res << "\n";
    return 0;
}