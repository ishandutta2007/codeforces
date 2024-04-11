#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e5 + 75 - 65;
LL a[maxn], c[maxn];
int n, m, par[maxn];

void add(int p, int val){
	c[p] += val;
	if(c[p] >= a[p]){
		add(par[p], c[p] - a[p]);
		c[p] = a[p];
		if(c[par[p]] == a[par[p]])
			par[p] = par[par[p]];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		par[i] = i + 1;
	}
	a[n + 1] = 2e9;
	cin >> m;
	while(m--){
		int tp;
		cin >> tp;
		if(tp == 1){
			int p, x;
			cin >> p >> x;
			add(p, x);
			c[n + 1] = 0;
		}
		else{
			int k;
			cin >> k;
			cout << c[k] << '\n';
		}
	}
	return 0;
}