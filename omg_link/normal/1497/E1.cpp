#include <stdio.h>
#include <vector>
#include <set>
#define MN 200000
#define MA 10000000

int n,k,a[MN+5];
bool nP[MA+5];
int mp[MA+5];
std::vector<int> ps;

void init(){
	for(int i=2;i<=MA;i++){
		if(!nP[i]){
			ps.push_back(i);
			mp[i] = i;
		}
		for(int p:ps){
			if(p*i>MA) break;
			nP[p*i] = true;
			mp[p*i] = p;
			if(i%p==0) break;
		}
	}
}

void solve(){
	int ans = 1;
	std::set<int> s;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		int tmp = 1;
		while(a!=1){
			if(tmp%mp[a]) tmp *= mp[a];
			else tmp /= mp[a];
			a /= mp[a];
		}
		if(s.find(tmp)!=s.end()){
			ans++;
			s.clear();
		}
		s.insert(tmp);
	}
	printf("%d\n",ans);
}

int main(){
	init();
	int T; scanf("%d",&T);
	while(T--) solve();
}