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

///
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	int q; cin >> q;
	while(q-->0) {
		string a, b; cin >> a >> b;
		int i = 0;
		while(b[b.length()-1-i] == '0') i++;
		int j = 0;
		while(a[a.length()-1-i-j] == '0') j++;
		cout << j << endl;
	}
///
	return 0;
}