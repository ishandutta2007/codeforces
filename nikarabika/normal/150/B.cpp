#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 2e3 + 85 - 75;
int par[maxn];
int n, m, k, P;
const LL D = 1e9 + 7;

int root(int x) { return (par[x] < 0) ? x : par[x] = root(par[x]);}

void merge(int x, int y){
	if((x = root(x)) == (y = root(y)))
		return;
	P--;
	if(par[x] > par[y])
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}

LL pow(LL b){
	if(b == 0) return 1;
	if(b == 1) return m;
	LL t;
	return (((t = pow(b / 2) % D) * t) % D) * pow(b & 1);
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	memset(par, -1, sizeof par);
	cin >> n >> m >> k;
	P = n;
	for(int i = 1; i + k - 1 <= n; i++)
		for(int j = 0; j < k; j++)
			merge(i + j, i + k - j - 1);
	cout << pow(P) % D << endl;
	return 0;
}