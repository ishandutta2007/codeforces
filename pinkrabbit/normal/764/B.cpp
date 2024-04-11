#include<cstdio>
int n,a[200000],t;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;++i) scanf("%d",a+i);
	for(int i=0;2*i<n;i+=2) t=a[i],a[i]=a[n-i-1],a[n-i-1]=t;
	for(int i=0;i<n;++i) printf("%d ",a[i]);
	return 0;
}