//#define __USE_MINGW_ANSI_STDIO 0
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout<<#x<<" :: "<<x<<endl;
#define debug2(x,y) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<endl;
#define debug3(x,y,z) cout<<#x<<" :: "<<x<<"\t"<<#y<<" :: "<<y<<"\t"<<#z<<" :: "<<z<<endl;

#define boost ios::sync_with_stdio(0); cin.tie(0)

#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;

const int N = 1e5 + 5;

/***************************************************************************/

ll P[N], S[N];
vector<int> adj[N];
ll ans;

void dfs(int v, int p, ll sum) {
	if(S[v] != -1) {
		if(S[v] < sum) {
			cout<<"-1\n";
			exit(0);
		}
		ans += S[v] - sum;
		sum = S[v];
	}
	else {
		ll mn = 1e18;
		for(auto it : adj[v]) {
			if(it == p) continue;
			mn = min(mn, S[it]);
		}
		if(mn < sum) {
			cout<<"-1\n";
			exit(0);
		}
		if(mn < 1e17) {
			ans += mn - sum;
			sum = mn;
		}
	}
	for(auto it : adj[v]) {
		if(it == p) continue;
		dfs(it, v, sum);
	}
}

int main() {

	boost;
	int n; cin>>n;
	for(int i=2; i<=n; i++) {
		cin>>P[i];
		adj[P[i]].pb(i), adj[i].pb(P[i]);
	}
	for(int i=1; i<=n; i++) {
		cin>>S[i];
	}
	dfs(1, 0, 0);
	cout<<ans<<"\n";
	return 0;
}