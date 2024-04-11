#include <stdio.h>
#include <algorithm>
#define MN 200000

int n;
char s[MN+5];

void solve(){
	scanf("%d%s",&n,&s[1]);
	int op1=1,op2=1,ans=0;
	while(op1<=n&&op2<=n){
		op1 = std::max(op1,op2);
		while(s[op1]!=s[op1+1]&&op1<=n) op1++;
		op1++;
		if(op1>n) break;
		while(s[op2]==s[op2+1]) op2++;
		op2++;
		ans++;
	}
	int tans = 0;
	if(op2<=n){
		while(op2<=n){
			if(s[op2]!=s[op2+1])
				tans++;
			op2++;
		}
	}
	ans += ((tans+1)>>1);
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}