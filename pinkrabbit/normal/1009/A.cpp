#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)

int n,m;
int a[100001],c[100001];

int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n) scanf("%d",c+i);
	F(i,1,m) scanf("%d",a+i);
	int j=1,Ans=0;
	F(i,1,n)
		if(j<=m&&a[j]>=c[i]) ++j, ++Ans;
	printf("%d",Ans);
	return 0;
}