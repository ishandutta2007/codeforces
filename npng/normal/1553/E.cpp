#include <cstdio>
const int Maxn=300000;
int n,m;
int p[Maxn+5],q[Maxn+5];
int sum[Maxn+5];
int a[Maxn+5],t[Maxn+5];
bool vis[Maxn+5];
bool check(int k){
	for(int i=0;i<n;i++){
		a[(i+k)%n]=i;
	}
	for(int i=0;i<n;i++){
		t[i]=q[a[i]];
	}
	for(int i=0;i<n;i++){
		vis[i]=0;
	}
	int num=0;
	for(int i=0;i<n;i++){
		if(vis[i]){
			continue;
		}
		for(int j=i;!vis[j];j=t[j]){
			vis[j]=1;
		}
		num++;
	}
	return n-num<=m;
}
int lis[Maxn+5],lis_len;
void solve(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		sum[i]=0;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&p[i]);
		p[i]--;
		q[p[i]]=i;
		int delta=(i-p[i]+n)%n;
		sum[delta]++;
	}
	lis_len=0;
	for(int i=0;i<n;i++){
		if(sum[i]>=n/3){
			if(check(i)){
				lis[++lis_len]=i;
			}
		}
	}
	printf("%d ",lis_len);
	for(int i=1;i<=lis_len;i++){
		printf("%d ",lis[i]);
	}
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}