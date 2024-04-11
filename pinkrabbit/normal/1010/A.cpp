#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
typedef double ld;

int n,m;
int a[100001],b[100001];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",a+i);
	F(i,1,n) scanf("%d",b+i);
	ld Ans=m;
	F(i,1,n){
		if(a[i]==1) return 0*puts("-1");
		if(b[i]==1) return 0*puts("-1");
		Ans=Ans/(a[i]-1)*a[i];
		Ans=Ans/(b[i]-1)*b[i];
	} printf("%.15lf\n",Ans-m);
	return 0;
}