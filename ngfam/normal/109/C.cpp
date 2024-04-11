#include <bits/stdc++.h>
using namespace std;

typedef long long llint;
const int N = 123456;

int n, m, k, lab[N];

void join(int u, int v){
	if(lab[u] > lab[v]) swap(u, v);
	lab[u] += lab[v];
	lab[v] = u;
}

int fin(int u){
	if(lab[u] < 0) return u;
	return lab[u] = fin(lab[u]);
}

bool beauty(int u){
	if(u == 0) return true;
	if(u % 10 != 4 && u % 10 != 7) return false;
	return beauty(u / 10);
}

int main(){
	//freopen("1.inp", "r", stdin);
	//freopen("1.out", "w", stdout);

	scanf("%d", &n);
	memset(lab, -1, sizeof lab);

	for(int i = 1; i < n; ++i){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(!beauty(w)){
			join(fin(u), fin(v));
		}
	}
	llint result = 0, one = 0, two = 0, spetwo = 0;
	for(int i = 1; i <= n; ++i){	
		if(lab[i] < 0){
		 	llint cur = -lab[i];
			result += cur * two * 6 + one * cur * (cur - 1) + cur * spetwo;
			two += cur * one;
			spetwo += (cur * (cur - 1));
		 	one += cur;	
		}
	}
	printf("%lld", result);
}