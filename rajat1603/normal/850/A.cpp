#include "bits/stdc++.h"
using namespace std;
const int N = 105;
int n;
vector < int > v[N];
int main(){
	cin >> n;
	if(n >= N){
		printf("0\n");
		return 0;
	}
	if(n == 2){
		printf("2\n1\n2\n");
		return 0;
	}
	for(int i = 0 ; i < n ; ++i){
		v[i].clear();
		v[i].resize(5);
		for(int j = 0 ; j < 5 ; ++j){
			cin >> v[i][j];
		}
	}
	for(int i = 0 ; i < n ; ++i){
		bool ok = 1;
		for(int j = 0 ; j < n && ok ; ++j){
			if(j == i){
				continue;
			}
			for(int k = 0 ; k < j && ok ; ++k){
				if(k == i){
					continue;
				}
				int dot = 0;
				for(int l = 0 ; l < 5 ; ++l){
					dot += (v[k][l] - v[i][l]) * (v[j][l] - v[i][l]);
				}
				if(dot > 0){
					ok = 0;
				}
			}
		}
		if(ok){
			printf("1\n%d\n" , i + 1);
			return 0;
		}
	}
	printf("0\n");
}