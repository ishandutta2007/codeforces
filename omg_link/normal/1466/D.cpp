#include <stdio.h>
#include <algorithm>
#include <functional>
#include <queue>
#define MN 100000

int n;
struct node{
	int val,cnt;
}p[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i].val);
		p[i].cnt = 0;
	}
	for(int i=2,u,v;i<=n;i++){
		scanf("%d%d",&u,&v);
		p[u].cnt++,p[v].cnt++;
	}
	long long ans = 0;
	std::vector<int> v;
	for(int i=1;i<=n;i++){
		ans += p[i].val;
		p[i].cnt--;
		while(p[i].cnt--)
			v.push_back(p[i].val);
	}
	std::sort(v.begin(),v.end());
	printf("%lld",ans);
	for(int i=2;i<=n-1;i++){
		ans += v.back();
		v.pop_back();
		printf(" %lld",ans);
	}puts("");
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}