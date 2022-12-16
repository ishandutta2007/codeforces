#include <stdio.h>
#include <algorithm>
#define MN 1000
int n,h,a[MN+5],b[MN+5];
bool check(int x){
	for(int i=1;i<=x;i++) b[i]=a[i];
	std::sort(b+1,b+1+x);
	int th=h;
	for(int i=x;i>=1;i-=2){
		if(b[i]>th) return false;
		th-=b[i];
	}
	return true;
}
int main(){
	scanf("%d%d",&n,&h);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=n;i>=1;i--)
		if(check(i)){
			printf("%d\n",i);
			return 0;
		}
	puts("0");
}