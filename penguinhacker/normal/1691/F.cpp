#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=1e9+7;
int n, k, s[mxN], p[mxN];
vector<int> adj[mxN];
ll f[mxN+1], iv[mxN+1], iF[mxN+1], dp[mxN];

ll C(int a, int b) {
	if (b>a)
		return 0;
	return f[a]*iF[b]%M*iF[a-b]%M;
}

void dfs(int u=0) {
	s[u]=1;
	for (int v : adj[u])
		if (v!=p[u]) {
			p[v]=u;
			dfs(v);
			s[u]+=s[v];
		}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i=1; i<n; ++i) {
		int u, v;
		cin >> u >> v, --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	f[0]=f[1]=iF[0]=iF[1]=iv[1]=1;
	for (int i=2; i<=n; ++i) {
		f[i]=f[i-1]*i%M;
		iv[i]=M-M/i*iv[M%i]%M;
		iF[i]=iF[i-1]*iv[i]%M;
	}
	dfs();
	ll ans=0;
	for (int i=0; i<n; ++i) { // whole tree
		ll cur=C(n, k);
		for (int j : adj[i])
			cur=(cur-C(p[j]==i?s[j]:n-s[i], k)+M)%M;
		ans=(ans+cur*n)%M;
	}
	for (int i=1; i<n; ++i) { // down subtrees
		ll cur=C(s[i], k);
		//cout << s[i] << " " << cur << endl;
		for (int j : adj[i])
			if (p[j]==i)
				cur=(cur-C(s[j], k)+M)%M;
		//cout << cur  << endl;
		ans=(ans+cur*s[i]%M*(n-s[i]))%M;
	}
	for (int i=0; i<n; ++i)
		for (int j : adj[i])
			dp[i]=(dp[i]+C(p[j]==i?s[j]:n-s[i], k))%M;
	for (int i=1; i<n; ++i) { // up subtree
		ll cur=(C(n-s[i], k)-dp[p[i]]+M+C(s[i], k))%M;
		//for (int j : adj[p[i]])
		//	if (j!=i)
		//		cur=(cur-C(p[j]==p[i]?s[j]:n-s[p[i]], k)+M)%M;
		ans=(ans+cur*(n-s[i])%M*s[i])%M;
	}
	cout << ans;
	return 0;
}