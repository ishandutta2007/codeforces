#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, k;
vector < int > mod[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &k, &m);

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		mod[x % m].push_back(x);
	}

	for(int i = 0; i < m; ++i){
		if(mod[i].size() >= k){
			puts("Yes");
			for(int j = 0; j < k; ++j){
				printf("%d ", mod[i][j]);
			}
			exit(0);
		}
	}

	cout << "No";

	return 0;
}