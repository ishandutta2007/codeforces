#include<cstdio>
int n,x,cnt[601],ans;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&x), cnt[x]++;
	for(int i=1;i<=600;++i) if(cnt[i]) ++ans;
	printf("%d",ans);
	return 0;
}