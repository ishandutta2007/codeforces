#include<bits/stdc++.h>

#define y1 dmytxdy
#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,tot,cnt,vcnt;
int a[200005],h[200005],v[400005],nxt[400005],du[200005],ans[200005];
bool vis[200005],cir[200005],hv[200005];

void addedge(int x,int y){
	v[++tot]=y; nxt[tot]=h[x]; h[x]=tot; du[y]++;
	v[++tot]=x; nxt[tot]=h[y]; h[y]=tot; du[x]++;
}

void dfs(int u,int fa){
	vis[u]=1;
	vcnt++;
	int son=0;
	for(int p=h[u];p;p=nxt[p]){
		if(cir[v[p]]||v[p]==fa) continue;
		dfs(v[p],u);
		if(!son) ans[v[p]]=u;
		son++;
	}
	if(son) cnt+=son-1;
	if(fa==-1&&son) cnt++;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) h[i]=vis[i]=cir[i]=ans[i]=du[i]=hv[i]=0; tot=0;
		for(int i=1;i<=n;i++) addedge(i,a[i]);
		int res=0;
		for(int i=1;i<=n;i++){
			if(vis[i]) continue;
			int j;
			for(j=i;!vis[j];j=a[j]) vis[j]=1;
			vector<int> vec(0);
			for(int k=j;!cir[k];k=a[k]) cir[k]=1,vec.pb(k);
			vcnt=cnt=0;
			for(auto r:vec) dfs(r,-1);
			if(vcnt==vec.size()){
				res+=vec.size();
				for(int i=0;i<vec.size()-1;i++) ans[vec[i]]=vec[i+1];
				ans[vec.back()]=vec[0];
			}
			else{
				res+=vcnt-cnt;
				for(int i=0;i<vec.size()-1;i++) if(du[vec[i+1]]==2) ans[vec[i]]=vec[i+1];
				if(du[vec[0]]==2) ans[vec.back()]=vec[0];
			}
		}
		printf("%d\n",res);
		for(int i=1;i<=n;i++) hv[ans[i]]=1;
		vector<pii> tmp(0);
		for(int i=1;i<=n;i++){
			if(hv[i]) continue;
			int st=i,ed=i;
			while(ans[ed]) ed=ans[ed];
			tmp.pb(mp(st,ed));
		}
		if(tmp.size()){
			for(int i=1;i<tmp.size();i++) ans[tmp[i-1].se]=tmp[i].fi;
			ans[tmp.back().se]=tmp[0].fi;
		}
		for(int i=1;i<=n;i++) printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}