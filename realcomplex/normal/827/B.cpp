#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	scanf("%i %i",&n,&k);
	printf("%i\n",(n-1)/k*2+min(2,(n-1)%k));
	for(int i = 2;i<=n;i++){
		printf("%i %i\n",i,max(i-k,1));
	}
	return 0;
}