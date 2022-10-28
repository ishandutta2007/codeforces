#include <bits/stdc++.h>

const int MX = 1e3 + 23;

int read(){
	char k = getchar(); int x = 0;
	while(k < '0' || k > '9') k = getchar();
	while(k >= '0' && k <= '9') x = x * 10 + k - '0' ,k = getchar();
	return x;
}

char str[MX][MX];

void solve(){
	int n = read() ,m = read();
	for(int i = 1 ; i <= n ; ++i){
		scanf("%s" ,str[i] + 1);
	}
	for(int i = 1 + (m % 3 == 0) ; i <= m ; ){
		for(int j = 1 ; j <= n ; ++j) str[j][i] = 'X';
		i += 3;
		if(i > m) break;

		int p = 1;
		if(n == 1 || (str[2][i - 1] != 'X' && str[2][i - 2] != 'X')) p = 1;
		else p = 2;
		str[p][i - 1] = str[p][i - 2] = 'X';
	}
	for(int i = 1 ; i <= n ; ++i) puts(str[i] + 1);
}

int main(){
	int T = read();
	for(int i = 1 ; i <= T ; ++i) solve();
	return 0;
}