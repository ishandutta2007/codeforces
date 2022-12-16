#include <stdio.h>
#include <map>
#define MN 100000

using std::map;

int n,k,a[MN+5],p[MN+5];

void lsh(){
	map<int,int> mp;
	for(int i=1;i<=n;i++)
		mp[a[i]];
	int cnt = 0;
	for(auto& p:mp)
		p.second = ++cnt;
	for(int i=1;i<=n;i++)
		a[i] = mp[a[i]];
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	lsh();
	for(int i=1;i<=n;i++)
		p[a[i]] = i;
	int ans = 1;
	for(int i=2;i<=n;i++)
		if(p[i]!=p[i-1]+1)
			ans++;
	puts(ans<=k?"Yes":"No");
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}