#include <cstdio>
const int Maxn=300;
int a[Maxn+5][Maxn+5];
int num[Maxn+5][Maxn+5];
int n,m;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		bool flag=1;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				scanf("%d",&a[i][j]);
				num[i][j]=4;
			}
		}
		for(int i=1;i<=n;i++){
			num[i][1]=num[i][m]=3;
		}
		for(int j=1;j<=m;j++){
			num[1][j]=num[n][j]=3;
		}
		num[1][1]=num[1][m]=num[n][1]=num[n][m]=2;
		for(int i=1;i<=n&&flag;i++){
			for(int j=1;j<=m&&flag;j++){
				if(a[i][j]>num[i][j]){
					flag=0;
					break;
				}
			}
		}
		if(!flag){
			puts("NO");
		}
		else{
			puts("YES");
			for(int i=1;i<=n;i++){
				for(int j=1;j<=m;j++){
					printf("%d ",num[i][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}