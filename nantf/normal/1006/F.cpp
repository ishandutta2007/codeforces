#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int d[2][2]={{1,0},{0,1}};
int n,m;
ll k,a[22][22],ans;
map<pair<pair<int,int>,ll>,ll> cnt;
pair<pair<int,int>,ll> MP(int x,int y,ll z){
	return make_pair(make_pair(x,y),z);
}
void dfs1(int dep,int x,int y,ll sum){
	if(dep==n) return void(cnt[MP(x,y,sum)]++);
	for(int i=0;i<2;i++){
		int tx=x+d[i][0],ty=y+d[i][1];
		if(tx>n || ty>m) continue;
		dfs1(dep+1,tx,ty,sum^a[tx][ty]);
	}
}
void dfs2(int dep,int x,int y,ll sum){
	if(dep==m) return void(ans+=cnt[MP(x,y,k^sum^a[x][y])]);
	for(int i=0;i<2;i++){
		int tx=x-d[i][0],ty=y-d[i][1];
		if(tx<1 || ty<1) continue;
		dfs2(dep+1,tx,ty,sum^a[tx][ty]);
	}
}
int main(){
	scanf("%d%d%lld",&n,&m,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) scanf("%lld",a[i]+j);
	dfs1(1,1,1,a[1][1]);
	dfs2(1,n,m,a[n][m]);
	printf("%lld\n",ans);
}