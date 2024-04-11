#include <stdio.h>
#include <string.h>
#include <algorithm>
#define MN 200000

const int INF = 0x7fffffff;

int len;
char s[MN+5];

void solve(){
	scanf("%s",&s[1]);
	len = strlen(&s[1]);
	int ans = INF;
	char ch[2];
	for(ch[0]='0';ch[0]<='9';ch[0]++){
		for(ch[1]='0';ch[1]<='9';ch[1]++){
			int tans = 0;
			int state = 0;
			for(int i=1;i<=len;i++){
				if(ch[state] == s[i]){
					state ^= 1;
				}else{
					tans++;
				}
			}
			if(ch[0]!=ch[1]&&state) tans++;
			ans = std::min(ans,tans);
		}
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve(); 
}