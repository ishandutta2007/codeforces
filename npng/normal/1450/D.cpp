#include <cstdio>
int min(int a,int b){
	return a<b?a:b;
}
const int Maxn=300000;
int n;
int a[Maxn+5];
bool vis[Maxn+5];
int qu[Maxn+5],qu_f,qu_t;
bool check(int k){
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	qu_f=1,qu_t=0;
	for(int i=1;i<k;i++){
		while(qu_f<=qu_t&&a[i]<=a[qu[qu_t]]){
			qu_t--;
		}
		qu[++qu_t]=i;
	}
	for(int i=k;i<=n;i++){
		while(qu_f<=qu_t&&i-qu[qu_f]+1>k){
			qu_f++;
		}
		while(qu_f<=qu_t&&a[i]<=a[qu[qu_t]]){
			qu_t--;
		}
		qu[++qu_t]=i;
		vis[a[qu[qu_f]]]=1;
	}
	for(int i=1;i<=n-k+1;i++){
		if(!vis[i]){
			return 0;
		}
	}
	return 1;
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		vis[i]=0;
	}
	bool flag=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(vis[a[i]]){
			flag=0;
		}
		vis[a[i]]=1;
	}
	printf("%d",flag);
	int left=2,right=n+1;
	while(left<right){
		int mid=(left+right)>>1;
		if(check(mid)){
			right=mid;
		}
		else{
			left=mid+1;
		}
	}
	for(int i=2;i<=n;i++){
		if(i<left){
			putchar('0');
		}
		else{
			putchar('1');
		}
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