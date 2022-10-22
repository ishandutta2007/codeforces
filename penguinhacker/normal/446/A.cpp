#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans, a[100000], l[100000], r[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	l[0]=r[n-1]=1;
	for (int i=1; i<n; ++i) {
		if (a[i]>a[i-1])
			l[i]=l[i-1]+1;
		else
			l[i]=1;
	}
	for (int i=n-2; i>=0; --i) {
		if (a[i]<a[i+1])
			r[i]=r[i+1]+1;
		else
			r[i]=1;
	}
	ans=max(r[0]+1, l[n-1]+1);
	if (ans>n)
		ans=n;
	for (int i=1; i<n-1; ++i) {
		if (a[i-1]+1<a[i+1])
			ans=max(ans, l[i-1]+r[i+1]+1);
		else
			ans=max(ans, max(l[i-1],r[i+1])+1);
	}
	cout << ans;
	return 0;
}