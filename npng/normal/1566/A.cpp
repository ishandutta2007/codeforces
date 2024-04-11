#include <cstdio>
int n,s;
void solve(){
	scanf("%d%d",&n,&s);
	int len=(n-((n+1)>>1)+1);
	printf("%d\n",s/len);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		solve();
	}
	return 0;
}