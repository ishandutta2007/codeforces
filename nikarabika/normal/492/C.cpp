#include <bits/stdc++.h>

using namespace std;

#define rep(i, t) for(ll (i) = 0; (i) < (ll)(t); (i)++)
#define reu(i, s, e) for(ll (i) = (ll)(s); (i) <= (ll)(e); (i)++)
#define rer(i, s, e) for(ll (i) = (ll)(s); (i) < (ll)(e); (i)++)
#define For(i, v) for(__typeof((v).begin()) (i) = (v).begin(); (i) != (v).end(); (i) ++)
#define mset(arr, val) memset(arr, (val), sizeof arr)
#define pb push_back
#define mp make_pair
#define p1 first
#define p2 second

typedef unsigned long long int ull;
typedef long long int ll;
typedef pair<ll, ll> pie;

int main(){
    ios_base::sync_with_stdio(false);
    ll n, r, avg;
    ll sum = 0, lea, ans = 0;
    cin >> n >> r >> avg;
    lea = n * avg;
    pie a[n];
    rep(i, n){
        cin >> a[i].p2 >> a[i].p1;
        sum += a[i].p2;
    }
    sort(a, a + n);
    int i = 0;
    while(sum < lea){
        ans += a[i].p1 * min(r - a[i].p2, lea - sum);
        sum += min(r - a[i].p2, lea - sum);
        i ++;
    }
    cout << ans << endl;
    return 0;
}