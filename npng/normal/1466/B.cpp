#include <cstdio>
const int Maxn=100000;
const int Inf=0x3f3f3f3f;
int n;
int x[Maxn+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	int last=Inf;
	int ans=0;
	for(int i=n;i>0;i--){
		if(x[i]+1<last){
			last=x[i]+1;
			ans++;
		}
		else if(x[i]<last){
			last=x[i];
			ans++;
		}
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