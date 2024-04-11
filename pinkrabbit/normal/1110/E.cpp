#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define MN 100005
int n,m,q,k;
int a[MN],b[MN],c[MN],d[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)scanf("%d",b+i);
	if(a[1]!=b[1]||a[n]!=b[n])return puts("No"),0;
	F(i,1,n-1)c[i]=a[i+1]-a[i];
	F(i,1,n-1)d[i]=b[i+1]-b[i];
	sort(c+1,c+n);sort(d+1,d+n);
	F(i,1,n-1)if(c[i]!=d[i])return puts("No"),0;
	puts("Yes");
	return 0;
}