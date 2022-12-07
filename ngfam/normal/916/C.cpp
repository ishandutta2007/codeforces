#include <bits/stdc++.h>

using namespace std;

bool isPrime(int x){
	if(x == 1) return 0;
	for(int i = 2; i * i <= x; ++i){
		if(x % i == 0) return 0;	
	}
	return 1;
}

int n, m;
vector < pair < pair < int, int >, int > > edges;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> m;

	int current = n - 1;

	while(!isPrime(current)) ++current;

	int tot = 0;

	for(int i = 1; i < n; ++i){
		int w = current - tot;
		w -= n - i - 1;
		tot += w;
		edges.emplace_back(make_pair(i, i + 1), w);
	}

	m -= n - 1;

	for(int i = 1; i <= n; ++i){
		if(m == 0) continue;
		for(int j = i + 1; j <= n; ++j){
			if(abs(i - j) <= 1) continue;
			edges.emplace_back(make_pair(i, j), 1e9);
			if(--m == 0) break;
		}
	}

	printf("%d %d\n", tot, tot);

	for(int i = 0; i < edges.size(); ++i){
		printf("%d %d %d\n", edges[i].first.first, edges[i].first.second, edges[i].second);
	}

	return 0;
}