#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
const int Maxn=100000;
int n,k,z;
int a[Maxn+5];
int sum[Maxn+5];
int maxn[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&k,&z);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			sum[i]=sum[i-1]+a[i];
			maxn[i]=0;
		}
		for(int i=2;i<=n;i++){
			maxn[i]=max(maxn[i-1],a[i-1]+a[i]);
		}
		int ans=0;
		for(int i=0;i<=z&&k-(i<<1)+1>0;i++){
			ans=max(ans,sum[k-(i<<1)+1]+maxn[k-(i<<1)+1]*i);
			if(i>0){
				ans=max(ans,sum[k-((i<<1)-1)+1]+maxn[k-((i<<1)-1)+1]*(i-1)+a[k-((i<<1)-1)]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}