#include <bits/stdc++.h>
using namespace std;

const int N = 1234;

char s[N][N];
int days[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif
	
	int n, m;
	scanf("%d%d", &n, &m);

	for(int i = 1; i <= m; ++i){
		scanf("%s", s[i] + 1);
		for(int j = 1; j <= n; ++j){
			if(s[i][j] == '0'){
				days[i] = 1;
			}		
		}	
	}

	int ans = 0;
	for(int i = 1; i <= m; ++i){
		days[i] = days[i - 1] * days[i] + days[i];
		ans = max(ans, days[i]);
	}
	printf("%d", ans);
}