#include <stdio.h>
#include <algorithm>
#include <map>
#define MN 200000

int n,m,b[MN+5];

void solve(){
	scanf("%d",&n);
	std::map<int,int> cnt;
	for(int i=1,a;i<=n;i++){
		scanf("%d",&a);
		cnt[a]++;
	}
	m = 0;
	for(auto p:cnt)
		b[++m] = p.second;
	std::sort(b+1,b+1+m);
	int ans = 0x7fffffff;
	for(int i=1;i<=m;i++)
		ans = std::min(ans,n-(m-i+1)*b[i]);
	printf("%d\n",ans);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}