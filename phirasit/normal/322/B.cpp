#include <stdio.h>

int r,g,b;
int ans = 0;
int max(int i,int j) {
	if(i > j) return i;
	return j;
}
int min(int i,int j) {
	if(i < j) return i;
	return j;
}
int main() {
	int m,M;
	scanf("%d %d %d",&r,&g,&b);
	m = min(r,min(g,b));
	M = min(r%3==0?3:r%3,min(g%3==0?3:g%3,b%3==0?3:b%3));
	ans = max(ans,m + (r-m)/3 + (g-m)/3 + (b-m)/3);
	ans = max(ans,r/3 + g/3 + b/3 + min(r%3,min(g%3,b%3)));
	if(r-M >= 0 && g-M >= 0 && b-M >= 0)
	ans = max(ans,M + (r-M)/3 + (g-M)/3 + (b-M)/3);
	printf("%d\n",ans);
	return 0;
}