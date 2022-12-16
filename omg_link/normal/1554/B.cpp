#include <stdio.h>
#include <algorithm>
typedef long long ll;

using std::max;

struct xxx{
	int mem[2];
	void clear(){
		mem[0] = mem[1] = 0;
	}
	void insert(int x){
		if(x==mem[0]||x==mem[1]) return;
		if(x>mem[0]){
			mem[1] = mem[0];
			mem[0] = x;
		}else if(x>mem[1]){
			mem[1] = x;
		}
	}
}f[1<<18];

void solve(){
	int n,k,S,w;
	scanf("%d%d",&n,&k);
	for(S=1,w=0;S<=n;S<<=1,w++);
	for(int i=0;i<S;i++)
		f[i].clear();
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		f[a].insert(i);
	}
	ll ans = -0x7fffffffffffffff;
	for(int i=0;i<S;i++){
		for(int j=0;j<w;j++){
			if(i&(1<<j)){
				f[i].insert(f[i^(1<<j)].mem[0]);
				f[i].insert(f[i^(1<<j)].mem[1]);
			}
		}
		if(f[i].mem[0]&&f[i].mem[1])
			ans = max(ans,(ll)f[i].mem[0]*f[i].mem[1]-k*i);
	}
	printf("%lld\n",ans);
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}