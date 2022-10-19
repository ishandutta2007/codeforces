//ANMHLIJKTJIY!
#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC diagnostic error "-fwhole-program"
#pragma GCC diagnostic error "-fcse-skip-blocks"
#pragma GCC diagnostic error "-funsafe-loop-optimizations"
#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define x0 x114514
#define x1 x1919810
#define y0 y114514
#define y1 y1919810
#define N 400010
using namespace std;
struct SegT{
	ll lo[N],hi[N],val[N],vid[N];
	void build(ll x,ll l,ll r)
	{
		lo[x]=l,hi[x]=r,val[x]=INF,vid[x]=-1;
		if(l==r)
		{
			return;
		}
		ll mid=(l+r)>>1,a=x<<1;
		build(a,l,mid);
		build(a|1,mid+1,r);
		return;
	}
	void update(ll x,ll l,ll r,ll v,ll id)
	{
		ll tl=lo[x],tr=hi[x];
		if(l<=tl&&tr<=r)
		{
			if(val[x]>v)
			{
				val[x]=v,vid[x]=id;
			}
			return;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			update(a,l,r,v,id);
		}
		if(mid<r)
		{
			update(a|1,l,r,v,id);
		}
		return;
	}
	pair<ll,ll> query(ll x,ll l)
	{
		ll tl=lo[x],tr=hi[x];
		pair<ll,ll> ret=make_pair(val[x],vid[x]);
		if(l<=tl&&tr<=l)
		{
			return ret;
		}
		ll mid=(tl+tr)>>1,a=x<<1;
		if(mid>=l)
		{
			ret=min(ret,query(a,l));
		}
		else
		{
			ret=min(ret,query(a|1,l));
		}
		return ret;
	}
}segt;
bool vis[N];
ll dirx[]={1,0,-1,0},diry[]={0,1,0,-1};
ll n,m,q,dir[N],nxt[N],nxtwei[N],reqt[N],f[N][20],g[N][20],cyclen[N],deg[N];
pair<ll,ll> st[N],ed[N],nxtnd[N];
vector<ll> dirs[4],updrow[N],updcol[N],qrys[N],upd[N];
int main(){
	ll i,j,x1,x2,y1,y2;
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++)
	{
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		st[i]=make_pair(x1,y1);
		ed[i]=make_pair(x2,y2);
		if(x1==x2)
		{
			dir[i]=(y1<y2)?1:3;
			updrow[x1].push_back(i);
		}
		else
		{
			dir[i]=(x1<x2)?0:2;
			updcol[y1].push_back(i);
		}
		dirs[dir[i]].push_back(i);
	}
	scanf("%lld",&q);
	for(i=n;i<n+q;i++)
	{
		scanf("%lld%lld",&x1,&y1);
		st[i]=ed[i]=make_pair(x1,y1);
		char c;
		scanf(" %c",&c);
		dir[i]=(c=='R')?0:((c=='U')?1:((c=='L'?2:3)));
		scanf("%lld",&reqt[i]);
		dirs[dir[i]].push_back(i);
	}
	ll cnt=n+q;
	{
		segt.build(1,0,m);
		for(i=0;i<=m;i++)
		{
			upd[i]=updrow[i];
			qrys[i].clear();
		}
		for(i=0;i<dirs[0].size();i++)
		{
			qrys[ed[dirs[0][i]].F].push_back(dirs[0][i]);
			if(dirs[0][i]<n)
			{
				upd[st[dirs[0][i]].F].push_back(dirs[0][i]);
			}
		}
		for(i=0;i<dirs[2].size();i++)
		{
			if(dirs[2][i]<n)
			{
				upd[st[dirs[2][i]].F].push_back(dirs[2][i]);
			}
		}
		for(i=m;i>=0;i--)
		{
			for(j=0;j<upd[i].size();j++)
			{
				segt.update(1,min(st[upd[i][j]].S,ed[upd[i][j]].S),max(st[upd[i][j]].S,ed[upd[i][j]].S),i,upd[i][j]);
			}
			for(j=0;j<qrys[i].size();j++)
			{
				pair<ll,ll> cur=segt.query(1,ed[qrys[i][j]].S);
				if(cur.S==-1)
				{
					st[cnt]=ed[cnt]=make_pair(m,ed[qrys[i][j]].S);
					cur.S=cnt++;
				}
				nxt[qrys[i][j]]=cur.S;
				nxtnd[qrys[i][j]]=make_pair((min(st[cur.S].F,ed[cur.S].F)<=ed[qrys[i][j]].F&&ed[qrys[i][j]].F<=max(st[cur.S].F,ed[cur.S].F))?ed[qrys[i][j]].F:st[cur.S].F,ed[qrys[i][j]].S);
				nxtwei[qrys[i][j]]=abs(ed[cur.S].F-ed[qrys[i][j]].F)+abs(ed[cur.S].S-ed[qrys[i][j]].S);
			}
		}
	}
	{
		segt.build(1,0,m);
		for(i=0;i<=m;i++)
		{
			upd[i]=updrow[i];
			qrys[i].clear();
		}
		for(i=0;i<dirs[2].size();i++)
		{
			qrys[ed[dirs[2][i]].F].push_back(dirs[2][i]);
			if(dirs[2][i]<n)
			{
				upd[st[dirs[2][i]].F].push_back(dirs[2][i]);
			}
		}
		for(i=0;i<dirs[0].size();i++)
		{
			if(dirs[0][i]<n)
			{
				upd[st[dirs[0][i]].F].push_back(dirs[0][i]);
			}
		}
		for(i=0;i<=m;i++)
		{
			for(j=0;j<upd[i].size();j++)
			{
				segt.update(1,min(st[upd[i][j]].S,ed[upd[i][j]].S),max(st[upd[i][j]].S,ed[upd[i][j]].S),-i,upd[i][j]);
			}
			for(j=0;j<qrys[i].size();j++)
			{
				pair<ll,ll> cur=segt.query(1,ed[qrys[i][j]].S);
				if(cur.S==-1)
				{
					st[cnt]=ed[cnt]=make_pair(0,ed[qrys[i][j]].S);
					cur.S=cnt++;
				}
				nxt[qrys[i][j]]=cur.S;
				nxtnd[qrys[i][j]]=make_pair((min(st[cur.S].F,ed[cur.S].F)<=ed[qrys[i][j]].F&&ed[qrys[i][j]].F<=max(st[cur.S].F,ed[cur.S].F))?ed[qrys[i][j]].F:st[cur.S].F,ed[qrys[i][j]].S);
				nxtwei[qrys[i][j]]=abs(ed[cur.S].F-ed[qrys[i][j]].F)+abs(ed[cur.S].S-ed[qrys[i][j]].S);
			}
		}
	}
	{
		segt.build(1,0,m);
		for(i=0;i<=m;i++)
		{
			upd[i]=updcol[i];
			qrys[i].clear();
		}
		for(i=0;i<dirs[1].size();i++)
		{
			qrys[ed[dirs[1][i]].S].push_back(dirs[1][i]);
			if(dirs[1][i]<n)
			{
				upd[st[dirs[1][i]].S].push_back(dirs[1][i]);
			}
		}
		for(i=0;i<dirs[3].size();i++)
		{
			if(dirs[3][i]<n)
			{
				upd[st[dirs[3][i]].S].push_back(dirs[3][i]);
			}
		}
		for(i=m;i>=0;i--)
		{
			for(j=0;j<upd[i].size();j++)
			{
				segt.update(1,min(st[upd[i][j]].F,ed[upd[i][j]].F),max(st[upd[i][j]].F,ed[upd[i][j]].F),i,upd[i][j]);
			}
			for(j=0;j<qrys[i].size();j++)
			{
				pair<ll,ll> cur=segt.query(1,ed[qrys[i][j]].F);
				if(cur.S==-1)
				{
					st[cnt]=ed[cnt]=make_pair(ed[qrys[i][j]].F,m);
					cur.S=cnt++;
				}
				nxt[qrys[i][j]]=cur.S;
				nxtnd[qrys[i][j]]=make_pair(ed[qrys[i][j]].F,(min(st[cur.S].S,ed[cur.S].S)<=ed[qrys[i][j]].S&&ed[qrys[i][j]].S<=max(st[cur.S].S,ed[cur.S].S))?ed[qrys[i][j]].S:st[cur.S].S);
				nxtwei[qrys[i][j]]=abs(ed[cur.S].F-ed[qrys[i][j]].F)+abs(ed[cur.S].S-ed[qrys[i][j]].S);
			}
		}
	}
	{
		segt.build(1,0,m);
		for(i=0;i<=m;i++)
		{
			upd[i]=updcol[i];
			qrys[i].clear();
		}
		for(i=0;i<dirs[3].size();i++)
		{
			qrys[ed[dirs[3][i]].S].push_back(dirs[3][i]);
			if(dirs[3][i]<n)
			{
				upd[st[dirs[3][i]].S].push_back(dirs[3][i]);
			}
		}
		for(i=0;i<dirs[1].size();i++)
		{
			if(dirs[1][i]<n)
			{
				upd[st[dirs[1][i]].S].push_back(dirs[1][i]);
			}
		}
		for(i=0;i<=m;i++)
		{
			for(j=0;j<upd[i].size();j++)
			{
				segt.update(1,min(st[upd[i][j]].F,ed[upd[i][j]].F),max(st[upd[i][j]].F,ed[upd[i][j]].F),-i,upd[i][j]);
			}
			for(j=0;j<qrys[i].size();j++)
			{
				pair<ll,ll> cur=segt.query(1,ed[qrys[i][j]].F);
				if(cur.S==-1)
				{
					st[cnt]=ed[cnt]=make_pair(ed[qrys[i][j]].F,0);
					cur.S=cnt++;
				}
				nxt[qrys[i][j]]=cur.S;
				nxtnd[qrys[i][j]]=make_pair(ed[qrys[i][j]].F,(min(st[cur.S].S,ed[cur.S].S)<=ed[qrys[i][j]].S&&ed[qrys[i][j]].S<=max(st[cur.S].S,ed[cur.S].S))?ed[qrys[i][j]].S:st[cur.S].S);
				nxtwei[qrys[i][j]]=abs(ed[cur.S].F-ed[qrys[i][j]].F)+abs(ed[cur.S].S-ed[qrys[i][j]].S);
			}
		}
	}
	for(i=n+q;i<cnt;i++)
	{
		nxt[i]=i;
		nxtwei[i]=1;
	}
	for(i=0;i<cnt;i++)
	{
//		cout<<i<<" -> "<<nxt[i]<<": "<<nxtwei[i]<<": "<<nxtnd[i].F<<" , "<<nxtnd[i].S<<endl;
		f[i][0]=nxt[i];
		g[i][0]=nxtwei[i];
		deg[nxt[i]]++;
	}
	for(i=1;i<20;i++)
	{
		for(j=0;j<cnt;j++)
		{
			f[j][i]=f[f[j][i-1]][i-1];
			g[j][i]=g[j][i-1]+g[f[j][i-1]][i-1];
		}
	}
	memset(vis,false,sizeof(vis));
	queue<ll> que;
	for(i=0;i<cnt;i++)
	{
		if(deg[i]==0)
		{
			que.push(i);
			vis[i]=true;
		}
	}
	while(!que.empty())
	{
		ll x=que.front();
		que.pop();
		deg[nxt[x]]--;
		if(deg[nxt[x]]==0)
		{
			vis[nxt[x]]=true;
			que.push(nxt[x]);
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			ll tot=nxtwei[i];
			for(j=nxt[i];j!=i;j=nxt[j])
			{
				vis[j]=true;
				tot+=nxtwei[j];
			}
			cyclen[i]=tot;
			for(j=nxt[i];j!=i;j=nxt[j])
			{
				cyclen[j]=tot;
			}
		}
	}
	for(i=n;i<n+q;i++)
	{
		ll curt=reqt[i],x=i;
		for(j=19;j>=0;j--)
		{
			if(curt>=g[x][j])
			{
				curt-=g[x][j];
				x=f[x][j];
			}
		}
		if(curt<nxtwei[x])
		{
			pair<ll,ll> cur=ed[x];
			if(curt==0)
			{
				printf("%lld %lld\n",cur.F,cur.S);
				continue;
			}
			ll dis=abs(nxtnd[x].F-cur.F)+abs(nxtnd[x].S-cur.S);
			if(curt<=dis)
			{
				printf("%lld %lld\n",cur.F+dirx[dir[x]]*curt,cur.S+diry[dir[x]]*curt);
				continue;
			}
			cur=nxtnd[x];
			curt-=dis;
			x=nxt[x];
			printf("%lld %lld\n",cur.F+dirx[dir[x]]*curt,cur.S+diry[dir[x]]*curt);
			continue;
		}
		curt%=cyclen[x];
		for(j=19;j>=0;j--)
		{
			if(curt>=g[x][j])
			{
				curt-=g[x][j];
				x=f[x][j];
			}
		}
		assert(curt<nxtwei[x]);
		pair<ll,ll> cur=ed[x];
		if(curt==0)
		{
			printf("%lld %lld\n",cur.F,cur.S);
			continue;
		}
		ll dis=abs(nxtnd[x].F-cur.F)+abs(nxtnd[x].S-cur.S);
		if(curt<=dis)
		{
			printf("%lld %lld\n",cur.F+dirx[dir[x]]*curt,cur.S+diry[dir[x]]*curt);
			continue;
		}
		cur=nxtnd[x];
		curt-=dis;
		x=nxt[x];
		printf("%lld %lld\n",cur.F+dirx[dir[x]]*curt,cur.S+diry[dir[x]]*curt);
	}
	return 0;
}