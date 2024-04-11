#include <stdio.h>
#define MN 100000

int n,d[MN+5];
char s[MN+5],t[MN+5]; 

int ansn,ans[MN*2+5];

void solve(){
	scanf("%d%s%s",&n,&s[1],&t[1]);
	for(int i=1;i<=n;i++){
		d[i] = s[i] ^ t[i];
	}
	ansn = 0;
	int c[2]={1,n};
	for(int i=n,st=0;i>=1;i--){
		if(st==0){
			if(s[c[0]]==t[i]){
				ans[++ansn] = 1;
			}
			c[0]++;
		}else{
			if(s[c[1]]!=t[i]){
				ans[++ansn] = 1;
			}
			c[1]--;
		}
		ans[++ansn] = i;
		st ^= 1;
	}
	printf("%d ",ansn);
	for(int i=1;i<=ansn;i++)
		printf("%d ",ans[i]);
	puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}