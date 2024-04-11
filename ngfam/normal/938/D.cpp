#include <bits/stdc++.h>

using namespace std;

const int N = 200020;

int n, m;
int done[N];
long long d[N];
vector < pair < int, long long > > e[N];

bool minimize(long long &x, long long y){
	if(x > y){
		x = y;
		return true;
	}
	return false;
}

int main(){

	scanf("%d%d", &n, &m);

	while(m--){
		int u, v; long long w;
		scanf("%d%d%lld", &u, &v, &w);
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	set < pair < long long, int > > foo;

	for(int i = 1; i <= n; ++i){
		long long w;
		scanf("%lld", &w);
		foo.emplace(d[i] = w, i);
	}

	while(foo.size()){
		int x = foo.begin() -> second;
		foo.erase(foo.begin());

		if(done[x]) continue;
		done[x] = 1;

		for(auto p : e[x]){
			int y = p.first; long long w = p.second;
			if(minimize(d[y], d[x] + w + w)){
				foo.emplace(d[y], y);
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		printf("%lld ", d[i]);
	}

	return 0;
}