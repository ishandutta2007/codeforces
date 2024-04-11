#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int mod=1e9+7;
int n,m,x,y,ans,cnt,as[13],gg,sz;
bool ok[5001];
vector<int>t[5001],z[5001];
inline int add(int x,int y){
	return x+y<mod?x+y:x+y-mod;
}
namespace tr2{
	int k,h[13],to[26],ne[26],d[13],ad[5001][5001];
	int qf[13];
	inline void link(int x,int y){
		k++;
		to[k]=y;
		ne[k]=h[x];
		h[x]=k;
	}
	inline int dfs(int i,int fa){
		sz++;
		int tp=1;
		for(int k=h[i];k;k=ne[k])
		if(to[k]!=fa) tp=ad[tp][dfs(to[k],i)];
		return tp;
	}
	inline void work(int x,int i,int n,int se,int tp){
		if(i>n){
			int a[13],s=0;
			for(int k=h[x];k;k=ne[k],tp>>=1)
			if(tp&1) a[++s]=to[k];
			sz=1;
			int g=1;
			for(int j=1;j<=s;j++) g=ad[g][qf[j]=dfs(a[j],x)];
			if(sz!=se||g) return;
			cnt++;
			if(sz==m) as[++gg]=cnt;
			memset(ok,0,sizeof(ok));
			for(int j=1;j<=s;j++){
				int qq=1;
				for(int k=1;k<=s;k++) if(k!=j) qq=ad[qq][qf[k]];
				if(ok[qq]) continue;
				ok[qq]=1;
				t[qq].push_back(qf[j]);
				z[qq].push_back(cnt);
				ad[qq][qf[j]]=cnt;
			}
			return;
		}
		work(x,i+1,n,se,tp<<1);
		work(x,i+1,n,se,tp<<1|1);
	}
	inline void build(){
		cnt=1;
		if(m==1) as[gg=1]=1;
		for(int l=2;l<=m;l++){
			for(int i=1;i<=m;i++){
				work(i,1,d[i],l,0);
			}
		}
	}
}
namespace tr1{
	int k,h[3001],to[6001],ne[6001];
	int f[3001][5001];
	inline void link(int x,int y){
		k++;
		to[k]=y;
		ne[k]=h[x];
		h[x]=k;
	}
	inline void dfs(int i,int fa){
		f[i][1]=1;
		for(int k=h[i];k;k=ne[k]){
			if(to[k]==fa) continue;
			dfs(to[k],i);
			for(int j=cnt;j;j--)
			for(int p=t[j].size()-1;~p;p--)
			f[i][z[j][p]]=add(f[i][z[j][p]],1ll*f[i][j]*f[to[k]][t[j][p]]%mod);
		}
		for(int j=1;j<=gg;j++) ans=add(ans,f[i][as[j]]);
	}
}
int main(){
	cin>>n;
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		tr1::link(x,y);
		tr1::link(y,x);
	}
	cin>>m;
	for(int i=1;i<m;i++){
		scanf("%d%d",&x,&y);
		tr2::link(x,y);
		tr2::link(y,x);
		tr2::d[x]++,tr2::d[y]++;
	}
	tr2::build();
	tr1::dfs(1,0);
	cout<<ans;
}