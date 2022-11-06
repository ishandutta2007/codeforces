#include <cstdio>
const int Maxn=30;
const int Maxm=100000;
int n;
int p[Maxn+5],a[Maxn+5];
int len;
void work(int n){
	len=0;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			p[++len]=i;
			a[len]=0;
			while(n%i==0){
				a[len]++;
				n/=i;
			}
		}
	}
	if(n>1){
		p[++len]=n;
		a[len]=1;
	}
}
int ans[Maxm+5],m;
void dfs(int x,int val,bool use=0){
	if(x>len){
		if(val==n||(!use)){
			return;
		}
		ans[++m]=val;
		return;
	}
	dfs(x+1,val,use);
	for(int i=1;i<=a[x];i++){
		val*=p[x];
		dfs(x+1,val,1);
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		work(n);
		if(len==1){
			int now=1;
			for(int i=1;i<=a[1];i++){
				now*=p[1];
				printf("%d ",now);
			}
			puts("");
			puts("0");
			continue;
		}
		if(len==2&&a[1]==1&&a[2]==1){
			printf("%d %d %d\n",p[1],p[2],p[1]*p[2]);
			puts("1");
			continue;
		}
		m=0;
		for(int i=1;i<=len;i++){
			int now=1;
			for(int j=1;j<=a[i];j++){
				now*=p[i];
				ans[++m]=now;
			}
			now=1;
			for(int j=1;j<=a[i];j++){
				now*=p[i];
				dfs(i+1,now);
			}
		}
		ans[++m]=n;
		for(int i=1;i<=m;i++){
			printf("%d ",ans[i]);
		}
		puts("");
		puts("0");
	}
	return 0;
}