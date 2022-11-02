#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k;
ll S;
unordered_map<ll, int> M[34];
ll ans, f[34];
ll a[34];


void solve(int cur, int ed, int use, ll sum) {
	if (cur==ed) {
		if (cur!=n+1) M[use][sum]++;
		else if (cur==n+1) {
			for(int i=0; i<=k; i++) {
				if (i+use>k) continue;
				if (M[i].count(S-sum)) ans+=M[i][S-sum];
			}
		}
		return;
	}
	if (a[cur]<=18) solve(cur+1, ed, use+1, sum+f[a[cur]]);
	solve(cur+1, ed, use, sum+a[cur]);
	solve(cur+1, ed, use, sum);
}

int main() {
	f[0]=1;
	for(int i=1; i<=18; i++) {
		f[i]=f[i-1]*i;	
	}
	cin>>n>>k>>S;
	for(int i=1; i<=n; i++) cin>>a[i];	
	m=n/2;
	solve(1, m+1, 0, 0);
	solve(m+1, n+1, 0, 0);
	cout<<ans<<endl;
	return 0;
}