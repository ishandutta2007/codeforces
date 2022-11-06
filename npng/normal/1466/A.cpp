#include <cstdio>
#include <cstring>
const int Maxn=50;
int n;
int x[Maxn+5];
int num[Maxn+5];
void solve(){
	memset(num,0,sizeof num);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&x[i]);
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(num[x[j]-x[i]]==0){
				ans++;
			}
			num[x[j]-x[i]]++;
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