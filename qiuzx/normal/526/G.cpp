#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 200010
using namespace std;
ll rint(){
	ll ret=0;
	char c=getchar();
	while(!isdigit(c)) c=getchar();
	while(isdigit(c)) ret=ret*10+(c-'0'),c=getchar();
	return ret;
}
void rout(ll x){
	if(x<10) putchar(x+48);
	else rout(x/10),putchar((x%10)+48);
	return;
}
ll n,q,diax,diay,mxd;
vector<pair<ll,ll> > vt[N];
void pdfs(ll x,ll lst,ll d)
{
	if(d>mxd)
	{
		mxd=d;
		diax=x;
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			pdfs(vt[x][i].F,x,d+vt[x][i].S);
		}
	}
	return;
}
void pdfs2(ll x,ll lst,ll d)
{
	if(d>mxd)
	{
		mxd=d;
		diay=x;
	}
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(vt[x][i].F!=lst)
		{
			pdfs2(vt[x][i].F,x,d+vt[x][i].S);
		}
	}
	return;
}
struct Tree{
	ll rt,dep[N],tp[N],hson[N],mxdep[N],chid[N],chrk[N],rnk[N],sumlen[N],lw[N],f[N][20],tot;
	vector<pair<ll,ll> > allch;
	void dfs(ll x,ll lst,ll d)
	{
		ll i,mxid=-1;
		dep[x]=d;
		mxdep[x]=0;
		for(i=1;i<20;i++)
		{
			f[x][i]=f[f[x][i-1]][i-1];
		}
		for(i=0;i<vt[x].size();i++)
		{
			if(vt[x][i].F!=lst)
			{
				f[vt[x][i].F][0]=x;
				dfs(vt[x][i].F,x,d+vt[x][i].S);
				if(mxdep[x]<mxdep[vt[x][i].F]+vt[x][i].S)
				{
					mxdep[x]=mxdep[vt[x][i].F]+vt[x][i].S;
					mxid=i;
				}
			}
		}
		hson[x]=mxid;
		return;
	}
	void dfs2(ll x,ll lst,ll curd)
	{
		if(hson[x]==-1)
		{
			allch.push_back(make_pair(curd,tot));
			lw[x]=x;
			chid[x]=tot++;
			return;
		}
		dfs2(vt[x][hson[x]].F,x,curd+vt[x][hson[x]].S);
		lw[x]=lw[vt[x][hson[x]].F];
		chid[x]=chid[vt[x][hson[x]].F];
		ll i;
		for(i=0;i<vt[x].size();i++)
		{
			if(i!=hson[x]&&vt[x][i].F!=lst)
			{
				dfs2(vt[x][i].F,x,vt[x][i].S);
			}
		}
		return;
	}
	void init(ll _r)
	{
		ll i,j;
		rt=_r;
		tot=0;
		allch.clear();
		memset(hson,-1,sizeof(hson));
		for(i=0;i<n;i++)
		{
			for(j=0;j<20;j++)
			{
				f[i][j]=rt;
			}
		}
		dfs(rt,-1,0);
		dfs2(rt,-1,0);
		sort(allch.begin(),allch.end());
		reverse(allch.begin(),allch.end());
		sumlen[0]=0;
		for(i=0;i<allch.size();i++)
		{
			sumlen[i+1]=sumlen[i]+allch[i].F;
			rnk[allch[i].S]=i;
		}
		for(i=0;i<n;i++)
		{
			chrk[i]=rnk[chid[i]];
		}
		return;
	}
	ll query(ll x,ll k)
	{
		ll i,nx,ret;
		k=min((ll)allch.size(),2*k-1);
		if(chrk[x]<k)
		{
			return sumlen[k];
		}
		nx=x;
		for(i=19;i>=0;i--)
		{
			if(chrk[f[nx][i]]>=k)
			{
				nx=f[nx][i];
			}
		}
		nx=f[nx][0];
		return max(sumlen[k-1],sumlen[k]-(dep[lw[nx]]-dep[nx]))+dep[lw[x]]-dep[nx];
	}
}tr1,tr2;
int main(){
//	freopen("cover.in","r",stdin);
//	freopen("cover.out","w",stdout);
	ll i,tp,lastans=0,x,y,z;
	n=rint(),q=rint(),tp=1;//rint();
	for(i=1;i<n;i++)
	{
		x=rint()-1,y=rint()-1,z=rint();
		vt[x].push_back(make_pair(y,z));
		vt[y].push_back(make_pair(x,z));
	}
	mxd=-LINF;
	pdfs(0,-1,0);
	mxd=-LINF;
	pdfs2(diax,-1,0);
	tr1.init(diax);
	tr2.init(diay);
	while(q--)
	{
		x=(rint()-1+lastans*tp)%n,y=(rint()-1+lastans*tp)%n+1;
		rout(lastans=max(tr1.query(x,y),tr2.query(x,y))),putchar('\n');
	}
	return 0;
}