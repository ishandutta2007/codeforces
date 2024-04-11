#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, ans, a[400000], cnt[1<<25], p[1<<25];

void print(int x) {
	for (int i=23; ~i; --i)
		cout << (x>>i&1);
	cout << endl;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	for (int i=24; ~i; --i) {
		for (int j=0; j<n; ++j) {
			a[j]&=(1<<i+1)-1;
			++cnt[a[j]], ++p[a[j]];
		}
		for (int j=1; j<1<<i+1; ++j)
			p[j]+=p[j-1];
		ll cur=0;
		for (int j=0; j<1<<i; ++j) {
			if (!cnt[j])
				continue;
			if (j<<1&1<<i)
				cur+=(ll)cnt[j]*(cnt[j]-1)/2;
			cur+=(ll)cnt[j]*(p[(1<<i+1)-j-1]-p[max(j, (1<<i)-j-1)]);
		}
		for (int j=1<<i; j<1<<i+1; ++j) {
			if (!cnt[j])
				continue;
			if (j<<1&1<<i)
				cur+=(ll)cnt[j]*(cnt[j]-1)/2;
			if (j==1<<i)
				continue;
			int mn=((1<<i+1)-j)|1<<i;
			mn=max(mn-1, j);
			cur+=(ll)cnt[j]*(n-p[mn]);
		}
		if (cur&1)
			ans|=1<<i;
		memset(cnt, 0, 4*(1<<i));
		memset(p, 0, 4*(1<<i));
	}
	//print(ans);
	cout << ans;
	return 0;
}