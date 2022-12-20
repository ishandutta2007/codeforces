#include <stdio.h>
#include <algorithm>
#define MN 300000

int n,k;
char s[MN+5];

void solve(){
	scanf("%d%d%s",&n,&k,&s[1]);
	int c[2]={0};
	for(int i=1;i<=k;i++){
		char std = '?';
		for(int j=i;j<=n;j+=k){
			if(s[j]!='?'){
				if(std=='?'){
					std = s[j];
				}else{
					if(std != s[j]){
						puts("NO");
						return;
					}
				}
			}
		}
		if(std!='?'){
			c[std-'0']++;
		}
	}
	if(std::max(c[0],c[1])>(k>>1)){
		puts("NO");
	}else{
		puts("YES");
	}
} 

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}