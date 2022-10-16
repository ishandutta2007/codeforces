#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=10,maxs=128,mod=1000000007,inv100=570000004;
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
int n,P[maxn][maxn],cnt[maxn],cur=1,tr[maxn][maxn*4][maxn],pr[maxn][maxs];
bool vis[maxn];
map<ll,int> dp[2];
vector<int> id[maxn][maxn*4];
map<vector<int>,int> mp[maxn];
void dfs(int at,int cur,int dep){
	if(dep>n){
		cnt[at]++;
		FOR(i,1,n) if(vis[i]) id[at][cnt[at]].PB(i);
		mp[at][id[at][cnt[at]]]=cnt[at];
		return;
	}
	if(cur) vis[dep]=true,dfs(at,cur-1,dep+1),vis[dep]=false;
	if(dep+cur!=n+1) dfs(at,cur,dep+1);
}
int main(){
	n=read();
	FOR(i,1,n) FOR(j,1,n) P[i][j]=1ll*read()*inv100%mod;
	FOR(i,0,n) dfs(i,i,1);
	dp[0][1]=1;
	FOR(i,0,n-1) FOR(j,1,cnt[i]) FOR(k,1,n){
		vector<int> tmp=id[i][j];
		bool flag=true;
		FOR(l,0,(int)tmp.size()-1) if(tmp[l]==k){flag=false;break;}
		if(!flag) continue;
		tmp.PB(k);
		sort(tmp.begin(),tmp.end());
		tr[i][j][k]=mp[i+1][tmp];
	}
	FOR(i,1,n){
		FOR(j,0,(1<<n)-1){
			pr[i][j]=1;
			FOR(k,1,n) if((j>>(k-1))&1) pr[i][j]=1ll*pr[i][j]*P[k][i]%mod;
			else pr[i][j]=1ll*pr[i][j]*(mod+1-P[k][i])%mod;
		}
		dp[cur].clear();
		for(map<ll,int>::iterator it=dp[cur^1].begin();it!=dp[cur^1].end();it++){
			ll s=it->first;
			int p=it->second;
			FOR(j,0,(1<<n)-1){
				ll t=0;
				FOR(k,1,cnt[i-1]) if((s>>(k-1))&1){
					FOR(l,1,n) if(((j>>(l-1))&1) && tr[i-1][k][l]) t|=1ll<<(tr[i-1][k][l]-1);
				}
				dp[cur][t]=(dp[cur][t]+1ll*p*pr[i][j])%mod;
			}
		}
		cur^=1;
	}
	printf("%d\n",dp[cur^1][1]); 
}