#include <stdio.h>
#include <algorithm>

using std::min;
using std::max;

void solve(){
	int W,H,x1,x2,y1,y2,w,h;
	scanf("%d%d%d%d%d%d%d%d",&W,&H,&x1,&y1,&x2,&y2,&w,&h);
	if(x2-x1+w>W&&y2-y1+h>H){
		puts("-1");
		return;
	}
	int ans = 0x7fffffff;
	if(x2-x1+w<=W) ans = min({ans,w-x1,x2-(W-w)});
	if(y2-y1+h<=H) ans = min({ans,h-y1,y2-(H-h)});
	ans = max(ans,0);
	printf("%d\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}