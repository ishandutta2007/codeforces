#include "bits/stdc++.h"
using namespace std;
int r , d;
int n;
int x , y , rn;
int ans;
int main(){
	scanf("%d %d" , &r , &d);
	scanf("%d" , &n);
	while(n--){
		scanf("%d %d %d" , &x , &y , &rn);
		long long tmp = rn + r - d;
		tmp *= tmp;
		long long tmp2 = r - rn;
		tmp2 *= tmp2;
		if(1LL * x * x + 1LL * y * y >= tmp && 1LL * x * x + 1LL * y * y <= tmp2){
			++ans;
		}
	}
	printf("%d\n" , ans);
}