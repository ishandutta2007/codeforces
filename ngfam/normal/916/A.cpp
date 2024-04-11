#include <bits/stdc++.h>

using namespace std;

const int mod = 1440;

int convert(int x, int y){
	return x * 60 + y;
}

int lucky(int x){
	if(x == 0) return 0;
	return (x % 10 == 7) || lucky(x / 10);
}

int mark[mod];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int x, h, m;
	cin >> x >> h >> m;

	int now = convert(h, m);

	int ans = 1e9;

	for(int u = 0; u < 24; ++u){
		for(int v = 0; v < 60; ++v){
			if(!lucky(u) && !lucky(v)) continue;
			
			memset(mark, 0, sizeof mark);

			int t = convert(u, v), steps = 0;

			while(true){
				if(mark[t]) break;
				mark[t] = ++steps;
				t = (t + x) % mod;
			}

			if(mark[now]) ans = min(ans, mark[now] - 1);
		}
	}

	cout << ans;

	return 0;
}