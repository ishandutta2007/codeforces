#include"bits/stdc++.h"
using namespace std;



int n;
int m;

vector<long long int> v;
int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++){
		int a;
		scanf("%d", &a);
		v.push_back(a);
	}
	long long int ans = 1;
	for (int i = 0; i < v.size(); i++){
		if (i)v[i] += v[i - 1];
		long long int go = (v[i] + m) / (long long int)(m);
		if (i)printf(" ");
		printf("%lld", go - ans);
		ans = go;
	}
	puts("");
	return 0;
}