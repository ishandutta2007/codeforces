#include <stdio.h>
#include <algorithm>

int p,f;
int cs,cw,s,w;
int ans;

void solve(){
	scanf("%d%d",&p,&f);
	scanf("%d%d",&cs,&cw);
	scanf("%d%d",&s,&w);
	if(s>w){
		std::swap(s,w);
		std::swap(cs,cw);
	}
	ans = 0;
	for(int ts1=0;ts1<=cs;ts1++){
		if(ts1*s>p) break;
		int ans=0,cs=::cs,cw=::cw;
		ans += ts1; cs -= ts1;
		int tw1 = std::min((p-ts1*s)/w,cw);
		ans += tw1; cw -= tw1;
		int ts2 = std::min(f/s,cs);
		ans += ts2; cs -= ts2;
		int tw2 = std::min((f-ts2*s)/w,cw);
		ans += tw2; cw -= tw2;
		::ans = std::max(::ans,ans);
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}