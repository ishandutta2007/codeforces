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
        int N; cin >> N;
        int arr[N];
        F0R(i, N) cin >> arr[i];
        map<int,int> m;
        int ans = -1;
        F0R(i, N) {
            if(m.find(arr[i]) == m.end()) m[arr[i]] = i;
            else {
                ans = max(ans, m[arr[i]] + N-i);
                m[arr[i]] = i;
            }
        }
        cout << ans << endl;
    }
	return 0;
}