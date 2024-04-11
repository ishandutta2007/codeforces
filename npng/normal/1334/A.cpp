#include <cstdio>
const int Maxn=100;
int n;
int p[Maxn+5],c[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	bool flag;
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d",&p[i],&c[i]);
		}
		flag=1;
		for(int i=1;i<=n;i++){
			if(c[i]-c[i-1]>p[i]-p[i-1]||p[i]<p[i-1]||c[i]<c[i-1]){
				flag=0;
				break;
			}
		}
		if(flag){
			puts("YES");
		}
		else{
			puts("NO");
		}
	}
	return 0;
}