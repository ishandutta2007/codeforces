#include <cstdio>
const int Maxn=100;
int n,m;
char mp[Maxn+5][Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%s",mp[i]+1);
		}
		int ans=0;
		for(int i=1;i<n;i++){
			if(mp[i][m]!='D'){
				ans++;
			}
		}
		for(int i=1;i<m;i++){
			if(mp[n][i]!='R'){
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}