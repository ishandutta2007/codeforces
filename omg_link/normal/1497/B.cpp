#include <stdio.h>
#include <algorithm>
#define MM 100000

int cnt[MM+5];

void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		cnt[i] = 0;
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		cnt[a%m]++;
	}
	int ans = 0;
	for(int i=1;i<m-i;i++){
		if(cnt[i]==0&&cnt[m-i]==0) continue;
		int p = std::min(cnt[i],cnt[m-i]);
		cnt[i] -= p;
		cnt[m-i] -= p;
		ans += std::max({cnt[i],cnt[m-i],1});
	}
	if(!(m&1)){
		if(cnt[m>>1]){
			ans++;
		}
	}
	if(cnt[0]){
		ans++;
	}
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}