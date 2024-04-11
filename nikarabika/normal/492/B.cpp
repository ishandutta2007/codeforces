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
    ll n, l;
    cin >> n >> l;
    ll a[n + 10];
    rep(i, n)
        cin >> a[i];
    if(n == 1){
        cout << max(a[0] - 0, l - a[0]) << ".000000000" << endl;
        return 0;
    }
    sort(a, a + n);
    ll max_ = max(2 * (a[0] - 0), 2 * (l - a[n - 1]));
    //cerr << max_ << endl;
    reu(i, 1, n - 1)
        if(a[i] - a[i - 1] > max_)
            max_ = a[i] - a[i - 1];
    if(max_ % 2 == 0)
        cout << max_ / 2 << ".000000000" << endl;
    else
        cout << max_ / 2 << ".500000000" << endl;
	return 0;
}