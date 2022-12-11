#include <bits/stdc++.h>

using namespace std;

set<int>I;
int n,k,a,m,l,r,xi;

int main(){
	scanf("%i %i %i",&n,&k,&a);
	a++;n++;
	int ans = n/a;
	scanf("%i",&m);
	I.insert(0);
	I.insert(n);
	for(int j = 1;j<=m;j++){
		scanf("%i",&xi);
		auto x = I.lower_bound(xi);
		r = *x,l = *--x;
		ans -= (r-l)/a;
		ans += (xi-l)/a+(r-xi)/a;
		if(ans<k){
			printf("%i\n",j);
			exit(0);
		}
		I.insert(xi);
	}
	printf("-1\n");
	return 0;
}