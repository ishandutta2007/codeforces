#include <cstdio>
typedef long long ll;
const int Maxn=3000;
int a[Maxn+5];
int sum[Maxn+5][Maxn+5];
ll num[Maxn+5][Maxn+5];
int n;
ll query(int i,int j,int c){
	return 1ll*(sum[j][c]-sum[i-1][c])*(sum[n][c]-sum[j][c]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				sum[i][j]=sum[i-1][j];
			}
			scanf("%d",&a[i]);
			sum[i][a[i]]++;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]==a[i]){
					num[i][j]=num[i][j-1];
					continue;
				}
				num[i][j]=num[i][j-1];
				num[i][j]-=query(i,j-1,a[j]);
				num[i][j]+=query(i,j,a[j]);
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(sum[n][i]>=4){
				ans+=1ll*sum[n][i]*(sum[n][i]-1)*(sum[n][i]-2)*(sum[n][i]-3)/24;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					ans+=num[i][j];
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}