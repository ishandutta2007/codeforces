#include<cstdio>
int n,ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;++i) if(i%(n-i)==0) ++ans;
	printf("%d",ans);
}