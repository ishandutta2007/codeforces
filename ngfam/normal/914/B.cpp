#include <bits/stdc++.h>

using namespace std;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	map < int, int > f;
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		++f[x];
	}

	for(auto p : f){
		if(p.second % 2) {
			cout << "Conan";
			return 0;
		}
	}

	cout << "Agasa";

	return 0;
}