#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
 
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define F0R(i, a) for (int i=0; i<(a); i++)
#define FORd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define F0Rd(i,a) for (int i = (a)-1; i >= 0; i--)
#define f first
#define s second
#define mp make_pair
#define pb push_back

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);

    int asdf; cin >> asdf;

    while(asdf-->0) {
        int n; cin >> n;
        vector<ll> v(n);

        ll sum = 0;
        F0R(i, n) {
            cin >> v[i];
            sum += v[i];
        }

        bool ok = sum % (n*(n+1L) / 2) == 0;

        sum /= n * (n+1L) / 2;

        vector<int> ans(n);
        F0R(i, n) {
            ans[i] = sum - (v[i] - v[(i + n-1) % n]);
            ok &= ans[i] % n == 0;
            ans[i] /= n;
            ok &= ans[i] > 0 && ans[i] <= 1000000000;
        }
        if(ok) {
            cout << "YES\n";
            for(auto x : ans)
                cout << x << " ";
            cout << '\n';
        } else cout << "NO\n";
    }

	return 0;
}