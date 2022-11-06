#include <cmath>
#include <cstdio>
int max(int a,int b){
	return a>b?a:b;
}
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=100000;
int a[Maxn+5];
int sum_f[Maxn+5],sum_g[Maxn+5];
int n;
int num_f[Maxn+5][32],num_g[Maxn+5][32];
int f_min[20][Maxn+5],g_min[20][Maxn+5];
void init_f(int *a){
	for(int i=0;i<=n;i++){
		f_min[0][i]=a[i];
	}
	for(int i=1;(1<<i)<=n+1;i++){
		for(int j=0;j+(1<<i)-1<=n;j++){
			f_min[i][j]=min(f_min[i-1][j],f_min[i-1][j+(1<<(i-1))]);
		}
	}
}
void init_g(int *a){
	for(int i=1;i<=n+1;i++){
		g_min[0][i]=a[i];
	}
	for(int i=1;(1<<i)<=n+1;i++){
		for(int j=1;j+(1<<i)-1<=n+1;j++){
			g_min[i][j]=min(g_min[i-1][j],g_min[i-1][j+(1<<(i-1))]);
		}
	}
}
int query_f(int l,int r){
	int k=(int)log2(r-l+1);
	return min(f_min[k][l],f_min[k][r-(1<<k)+1]);
}
int query_g(int l,int r){
	int k=(int)log2(r-l+1);
	return min(g_min[k][l],g_min[k][r-(1<<k)+1]);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum_f[i]=sum_f[i-1]+a[i];
		for(int j=0;j<=30;j++){
			num_f[i][j]=num_f[i-1][j];
		}
		if(a[i]>=0){
			num_f[i][a[i]]=i;
		}
	}
	init_f(sum_f);
	for(int i=n;i>0;i--){
		sum_g[i]=sum_g[i+1]+a[i];
	}
	init_g(sum_g);
	int ans=0;
	for(int j=0;j<=31;j++){
		num_g[n+1][j]=n+1;
	}
	for(int i=n;i>0;i--){
		for(int j=0;j<=31;j++){
			num_g[i][j]=num_g[i+1][j];
		}
		if(a[i]>=0){
			num_g[i][a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=29;j>=0;j--){
			num_f[i][j]=max(num_f[i][j],num_f[i][j+1]);
			num_g[i][j]=min(num_g[i][j],num_g[i][j+1]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]<0){
			continue;
		}
		ans=max(ans,sum_f[i-1]-query_f(num_f[i][a[i]+1],i-1)+sum_g[i+1]-query_g(i+1,num_g[i][a[i]+1]));
	}
	printf("%d\n",ans);
	return 0;
}