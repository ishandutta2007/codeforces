#include<cstdio>
int n,ans=0;
char str[7];
int sums[7];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",str);
		for(int i=0;i<7;++i)
			sums[i]+=str[i]=='1';
	}
	for(int i=0;i<7;++i)
		if(ans<sums[i]) ans=sums[i];
	printf("%d",ans);
	return 0;
}