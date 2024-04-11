#include "bits/stdc++.h"
using namespace std;
int n , k;
vector < int > v;
int main(){
	cin >> n >> k;
	v.clear();
	for(int i = 2 ; i <= n ; ++i){
		if(n % i == 0){
			while(n % i == 0){
				n /= i;
				v.emplace_back(i);
			}
		}
	}
	if(v.size() < k){
		cout << -1 << endl;
	}
	else{
		for(int i = 1 ; i < k ; ++i){
			printf("%d " , v[i - 1]);
		}
		int ans = 1;
		for(int i = k - 1 ; i < v.size() ; ++i){
			ans *= v[i];
		}
		printf("%d\n" , ans);
	}
}