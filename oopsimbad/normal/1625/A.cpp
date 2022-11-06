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
    while(asdf--) {
        int n, m; cin >> n >> m;
        int arr[n];
        F0R(i, n) cin >> arr[i];
        int ans = 0;
        F0R(i, m) {
            int b = 1 << i;
            int cnt = 0;
            for(int x : arr)
                if(x & b) cnt++;
                else cnt--;
            if(cnt > 0) ans += b;
        }
        cout << ans << endl;
    }
	return 0;
}