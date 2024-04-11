#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, INF=1e9;
int n, a[mxN], inc[mxN], dc[mxN];

ar<int, 2> check(int i) {
	assert(i<n);
	if (a[i]>a[i-1]) {
		int x=inc[i-1];
		if (a[i]>dc[i-1]) {
			//assert(x>a[i-1]);
			x=max(x, a[i-1]);
		}
		int y=a[i]<inc[i-1]?a[i-1]:INF;
		return {x, y};
	} else {
		int y=dc[i-1];
		if (a[i]<inc[i-1]) {
			//assert(y<a[i-1]);
			y=min(y, a[i-1]);
		}
		int x=a[i]>dc[i-1]?a[i-1]:-INF;
		return {x, y};
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	inc[0]=INF, dc[0]=-INF;
	int j=0;
	while(j+1<n) {
		ar<int, 2> x=check(j+1);
		if (x[0]!=-INF||x[1]!=INF) {
			++j;
			inc[j]=x[0], dc[j]=x[1];
		} else
			break;
	}
	//for (int i=0; i<=j; ++i)
	//	cout << inc[i] << " " << dc[i] << endl;
	ll ans=j+1;
	for (int i=1; i<n; ++i) {
		inc[i]=INF, dc[i]=-INF;
		for (int k=i+1; k<=j; ++k) {
			ar<int, 2> x=check(k);
			if (x[0]==inc[k]&&x[1]==dc[k])
				break;
			inc[k]=x[0], dc[k]=x[1];
		}
		while(j+1<n) {
			ar<int, 2> x=check(j+1);
			if (x[0]!=-INF||x[1]!=INF) {
				++j;
				inc[j]=x[0], dc[j]=x[1];
			} else
				break;
		}
		ans+=j-i+1;
	}
	cout << ans;
	return 0;
}