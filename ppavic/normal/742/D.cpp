#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e3 + 50;
const int INF = 1e9+10000;


int dp[N][N];
int par[N],w[N],b[N],n,lim,m;
int saz[N],cnt = 0;
vector < int > group[N]; 
vector < int > sz;

int f(int i,int l){
	if(l < 0) return -INF;
	if(i == cnt) return 0;
	if(dp[i][l] != -1) return dp[i][l];
	dp[i][l] = f(i+1,l);
	int aw = 0,ab = 0;
	for(int j = 0;j<group[i].size();j++){
		dp[i][l] = max(f(i+1,l-w[group[i][j]]) + b[group[i][j]],dp[i][l]);
		aw += w[group[i][j]];
		ab += b[group[i][j]];
	}
	dp[i][l] = max(f(i+1,l-aw) + ab,dp[i][l]);
	return dp[i][l];
	
}

int pr(int x){
	if(x == par[x]) return x;
	par[x] = pr(par[x]);
	return par[x];

}

void mrg(int x,int y){
	x = pr(x);
	y = pr(y);
	par[y] = x;
}

int main(){
	memset(dp,-1,sizeof(dp));
	scanf("%d%d%d",&n,&m,&lim);
	for(int i = 0;i<n;i++){
		scanf("%d",w+i);
		par[i] = i;saz[i] = -1;
	}
	for(int i = 0;i<n;i++)
		scanf("%d",b+i);
	for(int i = 0;i<m;i++){
		int t1,t2;
		scanf("%d%d",&t1,&t2);
		t1--;t2--;
		mrg(t1,t2);
	}
	for(int i = 0;i<n;i++){
		int t1 = pr(i);
		if(saz[t1] == -1){
			saz[t1] = cnt;
			sz.push_back(t1);
			cnt++;
		}
		group[saz[t1]].push_back(i);
	}
	printf("%d\n",f(0,lim));
}