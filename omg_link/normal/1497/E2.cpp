#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <vector>
#define MN 200000
#define MK 20
#define MA 10000000

int n,k,a[MN+5],f[MN+5][MK+5];
bool np[MA+5];
int mp[MA+5];
int nxa[MA+5],nxt[MN+5];
std::vector<int> ps;

void init(){
	for(int i=2;i<=MA;i++){
		if(!np[i]){
			ps.push_back(i);
			mp[i] = i;
		}
		for(int p:ps){
			if(p*i>MA) break;
			np[p*i] = true;
			mp[p*i] = p;
			if(i%p==0) break;
		}
	}
}

void solve(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int tmp = 1;
		while(a[i]!=1){
			if(tmp%mp[a[i]]) tmp *= mp[a[i]];
			else tmp /= mp[a[i]];
			a[i] /= mp[a[i]];
		}
		a[i] = tmp;
	}
	for(int i=1;i<=n;i++)
		nxa[a[i]] = n+1;
	std::multiset<int> s;
	for(int i=n;i>=1;i--){
		nxt[i] = nxa[a[i]];
		s.insert(nxt[i]);
		nxa[a[i]] = i;
	}
	for(int i=1;i<=k;i++)
		s.insert(n+1);
	memset(f[1],0,sizeof(*f));
	memset(f+2,0x7f,sizeof(*f)*n);
	for(int i=1;i<=n;i++){
		auto it = s.begin();
		for(int j=0;j<=k;j++,it++)
			for(int s=0;s+j<=k;s++)
				f[*it][s+j] = std::min(f[*it][s+j],f[i][s]+1);
		s.erase(s.find(nxt[i]));
	}
	int ans = 0x7f7f7f7f;
	for(int i=0;i<=k;i++)
		ans = std::min(ans,f[n+1][i]);
	printf("%d\n",ans);
}

int main(){
	init();
	int T; scanf("%d",&T);
	while(T--) solve();
}