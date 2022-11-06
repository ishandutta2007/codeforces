#include <cstdio>
#include <algorithm>
using namespace std;
int p,f;
int cnt_s,cnt_w;
int s,w;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&p,&f);
		scanf("%d%d",&cnt_s,&cnt_w);
		scanf("%d%d",&s,&w);
		if(s>w){
			swap(s,w);
			swap(cnt_s,cnt_w);
		}
		if(p/s+f/s<=cnt_s){
			printf("%d\n",p/s+f/s);
			continue;
		}
		int ans=0;
		for(int i=0;i<=cnt_s;i++){
			if(1ll*s*i>p||1ll*s*(cnt_s-i)>f){
				continue;
			}
			ans=max(ans,cnt_s+min((p-s*i)/w+(f-(cnt_s-i)*s)/w,cnt_w));
		}
		printf("%d\n",ans);
	}
	return 0;
}