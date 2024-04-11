#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
const int N = 6e5 + 7, inf = 1e5 + 1;
int n, k, a[N];
map < int, int > mp;
int main () {
    ios :: sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    ll ns = 0;
    cin >> n >> k;
    L(r, 1, n) {
    	cin >> a[r];
    	ll ret1 = 1, ret2 = 1;
		L(i, 2, sqrt (a[r])) if(a[r] % i == 0) {
			int cnt = 0;
			while(a[r] % i == 0) a[r] /= i, cnt += 1;
			cnt %= k;
			if(!cnt) continue;
			L(j, 1, cnt) ret1 *= i;
			L(j, 1, k - cnt) ret2 *= i, ret2 = min(ret2, (ll) inf);
		} 
		ret1 *= a[r];
		L(j, 1, k - 1) ret2 *= a[r], ret2 = min(ret2, (ll) inf);
		
		
		ns += mp[ret2];
		mp[ret1] += 1;
//		cout << ret1 << ' ' << ret2 << '\n';
	}
	cout << ns << '\n';
	return 0;
}