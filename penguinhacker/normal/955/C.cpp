#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const ll INF=1e18;

ll mul(ll a, ll b) {
	if ((double)a*b>=2*INF)
		return 2*INF;
	return a*b;
}

ll bp(ll b, ll p) {
	ll r=1;
	for (; p; p>>=1, b=mul(b, b))
		if (p&1)
			r=mul(r, b);
	return r;
}

vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};
vector<ar<int, 3>> po; // {power, PIE, limit}

int search(int i, ll x) {
	int l=0, r=po[i][2];
	while(l<r) {
		int mid=(l+r+1)/2;
		if (bp(mid, po[i][0])<=x)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}

int solve(ll x) {
	int ans=x>0;
	for (int i=0; i<po.size(); ++i)
		ans+=po[i][1]*max(0, search(i, x)-1);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i=1; i<1<<primes.size(); ++i) {
		int x=__builtin_popcount(i);
		if (x>3)
			continue;
		int p=1;
		for (int j=0; j<primes.size(); ++j)
			if (i&1<<j)
				p*=primes[j];
		if (p<60)
			po.push_back({p, x%2?1:-1, (int)1e9+7});
	}
	for (int i=0; i<po.size(); ++i)
		po[i][2]=search(i, INF);
	int t;
	cin >> t;
	while(t--) {
		ll l, r;
		cin >> l >> r;
		cout << solve(r)-solve(l-1) << "\n";
	}
	return 0;
}