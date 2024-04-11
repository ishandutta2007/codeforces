#include <bits/stdc++.h>

using namespace std;

int main(){

	int n, A, B, na, nb = -1;

	cin >> n >> A >> B;

	for(na = 0; na * A <= n; ++na){
		if((n - na * A) % B == 0){
			nb = (n - na * A) / B;
			break;
		}
	}

	if(nb == -1){
		cout << -1;
		return 0;
	}

	int cur = 1;

	for(int i = 1; i <= na; ++i){
		for(int j = 1; j < A; ++j){
			printf("%d ", cur + j);
		}
		printf("%d ", cur);
		cur += A;
	}

	for(int i = 1; i <= nb; ++i){
		for(int j = 1; j < B; ++j){
			printf("%d ", cur + j);
		}
		printf("%d ", cur);
		cur += B;
	}

	return 0;
}