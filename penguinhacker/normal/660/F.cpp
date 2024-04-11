#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5;
int n, a[mxN];
ll p1[mxN+1], p2[mxN+1];
deque<ar<ll, 2>> dq={{0, 0}};

ll ix(ar<ll, 2> l1, ar<ll, 2> l2) { // first time l2 overtakes l1
	assert(l1[0]<l2[0]);
	ll x=l2[0]-l1[0], y=l1[1]-l2[1];
	return y>=0?(y+x-1)/x:y/x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> a[i];
		p1[i+1]=p1[i]+a[i];
		p2[i+1]=p2[i]+(ll)(i+1)*a[i];
	}
	vector<int> ints(n);
	iota(ints.begin(), ints.end(), 0);
	ll ans=0;
	for (int i=1; i<=n; ++i) {
		int pos=*lower_bound(ints.begin(), ints.begin()+dq.size()-1, p1[i], [&](int x, ll y) { return dq[x][0]*y+dq[x][1]<dq[x+1][0]*y+dq[x+1][1]; } );
		//cout << pos << " " << dq[pos][0] << " " << dq[pos][1] << endl;
		ans=max(ans, p2[i]+dq[pos][0]*p1[i]+dq[pos][1]);
		ar<ll, 2> cur={-i, i*p1[i]-p2[i]};
		while(dq.size()>=2&&ix(cur, dq[1])<=ix(cur, dq[0]))
			dq.pop_front();
		dq.push_front(cur);
	}
	cout << ans;
	return 0;
}