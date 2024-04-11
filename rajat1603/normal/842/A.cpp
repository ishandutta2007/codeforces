#include "bits/stdc++.h"
using namespace std;
int l , r , x , y , k;
int main(){
	cin >> l >> r >> x >> y >> k;
	for(int i = x ; i <= y ; ++i){
		long long tmp = 1LL * i * k;
		if(tmp >= l && tmp <= r){
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
}