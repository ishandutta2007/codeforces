#include <cstdio>
const int Maxn=100000;
int n;
char s[Maxn+5];
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%s",s+1);
		int l=0,r=n+1;
		while(l<n&&s[l+1]=='0'){
			l++;
		}
		if(l==n){
			for(int i=1;i<=n;i++){
				putchar(s[i]);
			}
			puts("");
			continue;
		}
		while(r>1&&s[r-1]=='1'){
			r--;
		}
		if(r==1){
			for(int i=1;i<=n;i++){
				putchar(s[i]);
			}
			puts("");
			continue;
		}
		if(l+1==r){
			for(int i=1;i<=n;i++){
				putchar(s[i]);
			}
			puts("");
			continue;
		}
		for(int i=1;i<=l;i++){
			putchar(s[i]);
		}
		putchar('0');
		for(int i=r;i<=n;i++){
			putchar(s[i]);
		}
		puts("");
	}
	return 0;
}