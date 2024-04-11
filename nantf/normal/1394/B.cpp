#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=200020,maxk=10,mod=998244353;
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31)*mod;}
int n,m,k,deg[maxn],cnt[maxk][maxk][maxn],ans,tl;
vector<PII> e[maxn];
PII tmp[maxn];
int lim[maxk][maxk];
bool bl[maxk][maxk][maxk][maxk];
void dfs(int dep){
	if(dep>k) return ans++,void();
	FOR(i,1,dep) if(!lim[dep][i]){
		FOR(j,i+1,k) FOR(k,1,j) if(bl[dep][i][j][k]) lim[j][k]++;
		dfs(dep+1);
		FOR(j,i+1,k) FOR(k,1,j) if(bl[dep][i][j][k]) lim[j][k]--;
	}
}
int main(){
	n=read();m=read();k=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		e[u].PB(MP(w,v));
		deg[u]++;
	}
	FOR(i,1,n){
		sort(e[i].begin(),e[i].end());
		FOR(j,0,(int)e[i].size()-1) cnt[deg[i]][j+1][e[i][j].second]++;
	}
	FOR(i,1,n){
		tl=0;
		FOR(j,1,k) FOR(k,1,j) if(cnt[j][k][i]>=2) lim[j][k]=1e9;
		else if(cnt[j][k][i]) tmp[++tl]=MP(j,k);
		FOR(j,1,tl) FOR(k,j+1,tl) bl[tmp[j].first][tmp[j].second][tmp[k].first][tmp[k].second]=true;//,printf("%d %d %d %d\n",tmp[j].first,tmp[j].second,tmp[k].first,tmp[k].second);
	}
//	FOR(i,1,n) FOR(j,1,9) FOR(k,1,9) if(cnt[i][j][k]) printf("cnt[%d][%d][%d]=%d\n",i,j,k,cnt[i][j][k]);
	dfs(1);
	printf("%d\n",ans);
}