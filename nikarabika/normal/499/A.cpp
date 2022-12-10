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
typedef pair<int, int> pie;

int main(){
    ios_base::sync_with_stdio(false);
    int n, x;
    cin >> n >> x;
    int l[n + 10];
    int r[n + 10];
    l[0] = 0;
    r[0] = 0;
    int ans = 0;
    reu(i, 1, n){
        cin >> l[i] >> r[i];
        ans += r[i] - l[i] + 1;
        ans += (l[i] - r[i - 1] - 1) % x;
    }
    cout << ans << endl;
    return 0;
}