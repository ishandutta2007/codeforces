#include <stdio.h>
#include <vector>
#define MN 100000
typedef long long ll;
const int mod = 998244353;

using std::vector;

int ans[MN+5];

vector<int> e[MN+5];

int qpow(int bsc,int y){
	int ret = 1;
	while(y){
		if(y&1) ret = (ll)ret*bsc%mod;
		bsc = (ll)bsc*bsc%mod;
		y >>= 1;
	}
	return ret;
}

bool flag;
int d;

int dfs(int u,int f){
	int cnt = 0;
	for(int v:e[u]){
		if(v==f) continue;
		int sum = dfs(v,u);
		if(!flag) return 0;
		if(sum%d&&(sum+1)%d){
			flag = false;
			return 0;
		}
		cnt += sum+1;
	}
	return cnt;
}

bool check(int _d){
	flag = true;
	d = _d;
	dfs(1,0);
	return flag;
}

void solve(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		ans[i] = 0;
	int cnto = 0;
	vector<int> fs;
	for(int i=2;i*i<=n-1;i++)
		if((n-1)%i==0){
			fs.push_back(i);
			if(i*i!=n-1)
				fs.push_back((n-1)/i);
		}
	if(n-1!=1) fs.push_back(n-1);
	for(int d:fs){
		if(check(d)){
			cnto++;
			ans[d] = 1;
		}
	}
	for(int x:fs){
		if(!ans[x]) continue;
		for(int y:fs){
			if(!ans[y]) continue;
			if(x!=y&&x%y==0){
				ans[y] = 0;
				cnto--;
			}
		}
	}
	ans[1] = (qpow(2,n-1)+mod-cnto)%mod;
	for(int i=1;i<=n;i++)
		printf("%d%c",ans[i]," \n"[i==n]);
	for(int i=1;i<=n;i++){
		e[i].clear();
	}
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--) solve();
}