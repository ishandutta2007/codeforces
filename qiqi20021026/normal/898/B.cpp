#include<bits/stdc++.h>

using namespace std;

int n,a,b;

int main(){
	scanf("%d%d%d",&n,&a,&b);
	for (int i=0;i*a<=n;i++){
		int j=(n-i*a)/b;
		if (i*a+j*b==n){printf("YES\n%d %d\n",i,j); return 0;}
	}
	puts("NO");
	
	return 0;
}