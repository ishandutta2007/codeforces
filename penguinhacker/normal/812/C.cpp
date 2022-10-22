#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, S, a[100000], ans;
ll a2[100000];

ll eval(int k) {
	for (int i=0; i<n; ++i)
		a2[i]=a[i]+1ll*k*(i+1);
	sort(a2, a2+n);
	ll sum=0;
	for (int i=0; i<k; ++i)
		sum+=a2[i];
	return sum;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> S;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	
	int l=0, r=n;
	while(l<r) {
		int mid=(l+r+1)/2;
		ll c=eval(mid);
		if (c<=S)
			l=mid;
		else
			r=mid-1;
	}
	cout << l << ' ' << eval(l);
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/