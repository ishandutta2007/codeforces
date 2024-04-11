#include<bits/stdc++.h>
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::vector<int>pos[300010],vec[300010];
std::vector<int>tr[300010],tl[300010];
std::unordered_map<int,int>Map[300010];
int px[300010],pyl[300010],pyr[300010],psz[300010],m;
int fir[300010],dis[600010],nxt[600010],id;
void link(int a,int b){nxt[++id]=fir[a],fir[a]=id,dis[id]=b;}
int f[300010],siz[300010],N,rt,FA[300010];
bool vis[300010];
void getrt(int x,int fa=-1){
	f[x]=0,siz[x]=psz[x];
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa||vis[dis[i]])continue;
		getrt(dis[i],x);
		f[x]=std::max(f[x],siz[dis[i]]);
		siz[x]+=siz[dis[i]];
	}
	f[x]=std::max(f[x],N-siz[x]);
	if(f[x]<f[rt])rt=x;
}
struct data{int d,l,r,L,R,o;};
std::vector<data>dp[300010];
int num[300010];
void dfs(int x,int sL,int sR,std::vector<data>&s,int delta,int fa=-1){
	data sx=s[num[x]-delta];
	for(int i=fir[x];i;i=nxt[i]){
		if(dis[i]==fa||num[dis[i]]<sL||num[dis[i]]>sR)continue;
		if(sx.o){
			assert(sx.l==sx.r);assert(sx.L==sx.R);
			if(sx.l<pyl[dis[i]])s[num[dis[i]]-delta]={sx.d+1+pyl[dis[i]]-sx.l,pyl[dis[i]],pyl[dis[i]],sx.L,sx.R,1};
			else if(pyr[dis[i]]<sx.r)s[num[dis[i]]-delta]={sx.d+1+sx.r-pyr[dis[i]],pyr[dis[i]],pyr[dis[i]],sx.L,sx.R,1};
			else s[num[dis[i]]-delta]={sx.d+1,sx.l,sx.r,sx.L,sx.R,1};
		}else if(sx.r<pyl[dis[i]])s[num[dis[i]]-delta]={sx.d+1+pyl[dis[i]]-sx.r,pyl[dis[i]],pyl[dis[i]],sx.r,sx.r,1};
		else if(pyr[dis[i]]<sx.l)s[num[dis[i]]-delta]={sx.d+1+sx.l-pyr[dis[i]],pyr[dis[i]],pyr[dis[i]],sx.l,sx.l,1};
		else s[num[dis[i]]-delta]={sx.d+1,std::max(sx.l,pyl[dis[i]]),std::min(sx.r,pyr[dis[i]]),std::max(sx.l,pyl[dis[i]]),std::min(sx.r,pyr[dis[i]]),0};
		dfs(dis[i],sL,sR,s,delta,x);
	}
}
void solve(int x){
	vis[x]=1;num[x]=++num[0];
	for(int i=fir[x];i;i=nxt[i]){
		if(vis[dis[i]])continue;
		rt=0,N=siz[dis[i]],getrt(dis[i]);
		FA[rt]=x,solve(rt);
	}
	dp[x].resize(num[0]-num[x]+1);
	dp[x][0]={0,pyl[x],pyr[x],pyl[x],pyr[x],0};
	dfs(x,num[x],num[0],dp[x],num[x]);
}
void updatel(std::vector<int>&t,int x,int sz,int d){while(x<=sz)t[x]=std::min(t[x],d),x+=x&-x;}
int queryl(std::vector<int>&t,int x,int sz){int r=1e9;while(x)r=std::min(t[x],r),x-=x&-x;return r;}
void updater(std::vector<int>&t,int x,int sz,int d){while(x)t[x]=std::min(t[x],d),x-=x&-x;}
int queryr(std::vector<int>&t,int x,int sz){int r=1e9;while(x<=sz)r=std::min(t[x],r),x+=x&-x;return r;}
int main(){
#ifdef XZZSB
	freopen("in.in","r",stdin);
	freopen("out.out","w",stdout);
#endif
	int n=gi(),D=300000,x,y;
	for(int i=1;i<=n;++i)x=gi(),y=gi(),pos[x].push_back(y);
	for(int i=1;i<=D;++i){
		std::sort(pos[i].begin(),pos[i].end());
		for(int l=0,r;l<pos[i].size();l=r+1){
			r=l;while(r+1<pos[i].size()&&pos[i][r+1]==pos[i][r]+1)++r;
			px[++m]=i,pyl[m]=pos[i][l],pyr[m]=pyl[m]+r-l;psz[m]=r-l+1;
			for(int j=pyl[m];j<=pyr[m];++j)Map[i][j]=m;
			vec[i].push_back(m);
		}
	}
	for(int i=1;i<D;++i){
		int p1=0,p2=0,a,b;
		while(p1<vec[i].size()&&p2<vec[i+1].size()){
			a=vec[i][p1],b=vec[i+1][p2];
			if(pyr[a]<pyl[b])++p1;
			else if(pyr[b]<pyl[a])++p2;
			else link(a,b),link(b,a),pyr[a]<pyr[b]?++p1:++p2;
		}
	}
	f[0]=1e9,N=n,getrt(1),solve(rt);
	for(int i=1;i<=m;++i)tl[i].resize(psz[i]+1,1e9),tr[i].resize(psz[i]+1,1e9);
	int q=gi(),o,p,s,py,d,yes=0,ans;
	while(q--){
		o=gi(),x=gi(),y=gi(),p=s=Map[x][y];
		yes|=o==1;if(!yes&&o==2){puts("-1");continue;}
		ans=1e9;
		while(s){
			data to=dp[s][num[p]-num[s]];
			py=y;
			if(!to.o)
				if(to.l<=py&&py<=to.r)d=to.d;
				else if(py<to.l)d=to.d+to.l-py,py=to.l;
				else d=to.d+py-to.r,py=to.r;
			else d=to.d+abs(py-to.l),py=to.L;
			if(o==1)updatel(tl[s],py-pyl[s]+1,psz[s],d-py),updater(tr[s],py-pyl[s]+1,psz[s],d+py);
			else ans=std::min(ans,d+std::min(py+queryl(tl[s],py-pyl[s]+1,psz[s]),queryr(tr[s],py-pyl[s]+1,psz[s])-py));
			s=FA[s];
		}
		if(o==2)printf("%d\n",ans);
	}
	return 0;
}