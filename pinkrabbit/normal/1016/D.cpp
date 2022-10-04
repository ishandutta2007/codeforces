#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,m;
int a[1001],b[1001];
int A,B;

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i), A^=a[i];
	F(i,1,m) scanf("%d",b+i), B^=b[i];
	A^=a[1], B^=b[1];
	int m11=a[1]^B;
	if((m11^A)!=b[1]) return 0*puts("NO");
	puts("YES");
	printf("%d ",m11);
	F(i,2,m) printf("%d ",b[i]);
	puts("");
	F(i,2,n){
		printf("%d ",a[i]);
		F(j,2,m) printf("0 ");
		puts("");
	}
	return 0;
}