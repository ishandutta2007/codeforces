#include<bits/stdc++.h>
using namespace std;
int T,n,k,tot,a[10001];
int main() {
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k),tot=0;
		if(k%(n-1)==0) printf("%d\n",k/(n-1)*n-1);
		else printf("%d\n",k/(n-1)*n+k%(n-1));
	}
	return 0;
}