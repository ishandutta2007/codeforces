#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
#define MN 200000
typedef long long LL;
const LL INF = 0x3fffffffffffffffll;

int n,fa[MN+5],d[MN+5];
LL f[MN+5],s[MN+5],a[MN+5];
std::vector<int> e[MN+5],l[MN+5];

void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		s[i] = 0;
		f[i] = 0;
		e[i].clear();
		l[i].clear();
	}
	for(int i=2;i<=n;i++){	
		scanf("%d",&fa[i]);
		e[fa[i]].push_back(i);
	}
	for(int i=2;i<=n;i++)
		scanf("%lld",&a[i]);
	std::queue<int> q;
	q.push(1);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v:e[u]){
			d[v] = d[u]+1;
			q.push(v);
		}
	}
	int D = 0;
	for(int i=1;i<=n;i++){
		l[d[i]].push_back(i);
		D = std::max(D,d[i]);
	}
	for(int i=D;i>=1;i--){
		//max(abs(a[i]-a[j])+max(s[i],s[j]))
		//0 : +a[i]+s[i]-a[j]
		//1 : -a[i]+s[i]+a[j]
		//2 : +a[i]+s[j]-a[j]
		//3 : -a[i]+s[j]+a[j]
		LL m[4] = {-INF,-INF,-INF,-INF};
		for(auto j:l[i]){
			m[0] = std::max(m[0],-a[j]);
			m[1] = std::max(m[1],a[j]);
			m[2] = std::max(m[2],s[j]-a[j]);
			m[3] = std::max(m[3],s[j]+a[j]);
		}
		for(auto j:l[i]){
			f[j] = std::max({
				m[0]+a[j]+s[j],
				m[1]-a[j]+s[j],
				m[2]+a[j],
				m[3]-a[j]
			});
			s[fa[j]] = std::max(s[fa[j]],f[j]);
		}
	}
	printf("%lld\n",s[1]);
}

int main(){
	int T; scanf("%d",&T);
	while(T--) solve();
}