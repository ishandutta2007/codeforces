#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a,b,c;
	scanf("%d%d%d%d",&n,&a,&b,&c);
	if(n==1){
		printf("0\n");
		return 0;
	}
	--n;
	if(c<a&&c<b){
		printf("%d\n",(n-1)*c+min(a,b));
	}
	else printf("%d\n",n*min(a,b));
	return 0;
}