#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 1;

int prime[N], a[N], n;
vector < int > pr;

int adj[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
	}

	for(int i = 2; i < N; ++i){
		if(prime[i] == 0){
			pr.push_back(i);
			for(int j = i + i; j < N; j += i){
				prime[j] = i;
			}
			prime[i] = i;	
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i){
		int val = a[i];
		if(val == 1){
			 ans = 1;
			 continue;
		}
		while(val > 1){
			int u = prime[val];
			++adj[u];
			while(val % u == 0) val /= u;
		}
	}

	for(int i = 1; i < N; ++i){
	    	ans = max(ans, adj[i]);
	}

	cout << ans;

	//cout << pr.size() << endl;

	return 0;
}