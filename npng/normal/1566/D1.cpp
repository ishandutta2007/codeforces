#include <cstdio>
#include <algorithm>
const int Maxn=300;
int n,m;
int a[Maxn*Maxn+5];
int d[Maxn*Maxn+5],d_len;
int sum[Maxn*Maxn+5];
bool vis[Maxn+5][Maxn+5];
int find_belong(int x){
	return (x-1)/m+1;
}
int find_bel_l(int x){
	return (x-1)*m+1;
}
int find_bel_r(int x){
	return x*m;
}
int find_x(int x){
	return (x-1)/m+1;
}
int find_y(int x){
	return x-(x-1)/m*m;
}
void solve(){
	d_len=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[i][j]=0;
		}
	}
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		d[++d_len]=a[i];
	}
	std::sort(d+1,d+1+d_len);
	d_len=std::unique(d+1,d+1+d_len)-d-1;
	for(int i=1;i<=d_len;i++){
		sum[i]=0;
	}
	for(int i=1;i<=n*m;i++){
		a[i]=std::lower_bound(d+1,d+1+d_len,a[i])-d;
		sum[a[i]]++;
	}
	for(int i=1;i<=d_len;i++){
		sum[i]+=sum[i-1];
	}
	int ans=0;
	for(int i=1;i<=n*m;i++){
		int x=find_belong(sum[a[i]-1]+1);
		while(vis[x][std::max(sum[a[i]-1]+1,find_bel_l(x))]){
			x++;
		}
		int id=std::min(sum[a[i]],find_bel_r(x));
		while(vis[find_x(id)][find_y(id)]){
			id--;
		}
		for(int j=1;j<find_y(id);j++){
			ans+=vis[find_x(id)][j];
		}
		vis[find_x(id)][find_y(id)]=1;
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}