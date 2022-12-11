#include<bits/stdc++.h> 
using namespace std;
int n,A,B,i,j,k,tot;
int main(){
	scanf("%d%d%d",&n,&A,&B);
	for(i=0;i<=n/A;i++)
		if((n-i*A)%B==0)break;
	if(i>n/A){puts("-1");return 0;}
	for(j=1;j<=i;j++){
		printf("%d ",j*A);
		for(k=1;k<A;k++)
			printf("%d ",j*A-A+k);
	}
	tot=i*A;
	for(j=1;tot+j*B<=n;j++){
		printf("%d ",tot+j*B);
		for(k=1;k<B;k++)
			printf("%d ",tot+j*B-B+k);
	}	
}