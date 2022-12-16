#include <stdio.h>
#include <string.h>
#include <algorithm>

using std::max;
using std::min;

char s[30],t[30];

int calc(){
	int n = strlen(&s[1]);
	int m = strlen(&t[1]);
	int mch = 0;
	for(int i=1,j=1;i<=n&&j<=m;i++){
		if(s[i]==t[j]) mch++,j++;
	}
	return n+m-2*mch;
}

void solve(){
	int ans = 0x7fffffff;
	scanf("%s",&s[1]);
	for(int i=0;i<60;i++){
		sprintf(&t[1],"%lld",1ll<<i);
		ans = min(ans,calc());
	}
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}