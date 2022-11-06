#include <cstdio>
const int Maxn=100000;
char s[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++){
			putchar(s[n]);
		}
		puts("");
	}
	return 0;
}