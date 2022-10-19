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
#define N 800010
using namespace std;
ll n,q,dep[N],fa[N],bel[N],col[N],cnt=0;
string allst[N];
char res[N];
bool mstch[N],vis[N];
vector<ll> ed[N],vt[N],nxt[N];
vector<pair<ll,ll> > qry;
vector<pair<ll,pair<char,char> > > rst[N];
void dfs(ll x,ll lst,ll d)
{
	dep[x]=d;
	fa[x]=lst;
	ll i;
	for(i=0;i<ed[x].size();i++)
	{
		if(ed[x][i]!=lst)
		{
			dfs(ed[x][i],x,d+1);
		}
	}
	return;
}
void build(ll x)
{
	ll i,mask1=0,mask2=(1<<26)-1;
	char fx1='$',ps1='$',ps2='$';
	for(i=0;i<rst[x].size();i++)
	{
		if(rst[x][i].S.F==rst[x][i].S.S)
		{
			if(fx1!='$'&&fx1!=rst[x][i].S.F)
			{
				cout<<"NO"<<endl;
				exit(0);
			}
			fx1=rst[x][i].S.F;
		}
		mask1|=((1<<(rst[x][i].S.F-'a'))|(1<<(rst[x][i].S.S-'a')));
		mask2&=((1<<(rst[x][i].S.F-'a'))|(1<<(rst[x][i].S.S-'a')));
	}
	if(mask2==0)
	{
		cout<<"NO"<<endl;
		exit(0);
	}
	if(__builtin_popcount(mask1)>2)
	{
		assert(__builtin_popcount(mask2)==1);
		for(i=0;i<26;i++)
		{
			if(mask2&(1<<i))
			{
				fx1=(char)('a'+i);
			}
		}
	}
	else
	{
		for(i=0;i<26;i++)
		{
			if(mask1&(1<<i))
			{
				if(ps1=='$')
				{
					ps1=(char)('a'+i);
				}
				else
				{
					ps2=(char)('a'+i);
				}
			}
		}
	}
	if(fx1>='a'&&fx1<='z')
	{
		res[x]=fx1;
		for(i=0;i<rst[x].size();i++)
		{
			if(rst[x][i].S.F!=rst[x][i].S.S)
			{
				if(rst[x][i].S.F==fx1)
				{
					mstch[rst[x][i].F<<1]=true;
				}
				else
				{
					mstch[(rst[x][i].F<<1)|1]=true;
				}
			}
		}
		return;
	}
	else
	{
		vector<ll> nd1,nd2;
		for(i=0;i<rst[x].size();i++)
		{
			if(rst[x][i].S.F==ps1)
			{
				nd1.push_back(rst[x][i].F<<1);
				nd2.push_back((rst[x][i].F<<1)|1);
			}
			else
			{
				nd1.push_back((rst[x][i].F<<1)|1);
				nd2.push_back(rst[x][i].F<<1);
			}
		}
		for(i=0;i<nd1.size();i++)
		{
			vt[nd1[i]].push_back(nd1[(i+1)%nd1.size()]);
		}
		for(i=0;i<nd2.size();i++)
		{
			vt[nd2[i]].push_back(nd2[(i+1)%nd2.size()]);
		}
	}
	return;
}
void getcc(ll x)
{
	vis[x]=true;
	bel[x]=cnt;
	ll i;
	for(i=0;i<vt[x].size();i++)
	{
		if(!vis[vt[x][i]])
		{
			getcc(vt[x][i]);
		}
	}
	return;
}
void dfs2(ll x)
{
	vis[x]=true;
	ll i;
	for(i=0;i<nxt[x].size();i++)
	{
		if(col[nxt[x][i]]==col[x])
		{
			cout<<"NO"<<endl;
			exit(0);
		}
		if(!vis[nxt[x][i]])
		{
			col[nxt[x][i]]=col[x]^1;
			dfs2(nxt[x][i]);
		}
	}
	return;
}
void update(ll x,ll y,string s)
{
	ll i;
	vector<ll> rd1,rd2;
	while(dep[x]>dep[y])
	{
		rd1.push_back(x);
		x=fa[x];
	}
	while(dep[y]>dep[x])
	{
		rd2.push_back(y);
		y=fa[y];
	}
	while(x!=y)
	{
		rd1.push_back(x);
		rd2.push_back(y);
		x=fa[x],y=fa[y];
	}
	rd1.push_back(x);
	for(i=rd2.size()-1;i>=0;i--)
	{
		rd1.push_back(rd2[i]);
	}
	for(i=0;i<rd1.size();i++)
	{
		res[rd1[i]]=s[i];
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,x,y;
	string s;
	cin>>n>>q;
	for(i=1;i<n;i++)
	{
		cin>>x>>y;
		x--,y--;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(0,-1,0);
	for(i=0;i<q;i++)
	{
		cin>>x>>y>>s;
		allst[i]=s;
		x--,y--;
		qry.push_back(make_pair(x,y));
		vector<ll> rd1,rd2;
		while(dep[x]>dep[y])
		{
			rd1.push_back(x);
			x=fa[x];
		}
		while(dep[y]>dep[x])
		{
			rd2.push_back(y);
			y=fa[y];
		}
		while(x!=y)
		{
			rd1.push_back(x);
			rd2.push_back(y);
			x=fa[x],y=fa[y];
		}
		rd1.push_back(x);
		for(j=rd2.size()-1;j>=0;j--)
		{
			rd1.push_back(rd2[j]);
		}
		for(j=0;j<rd1.size();j++)
		{
			rst[rd1[j]].push_back(make_pair(i,make_pair(s[j],s[s.size()-j-1])));
		}
	}
	for(i=0;i<n;i++)
	{
		res[i]='a';
	}
	for(i=0;i<n;i++)
	{
		build(i);
	}
	for(i=0;i<(q<<1);i++)
	{
		if(!vis[i])
		{
			getcc(i);
			cnt++;
		}
	}
	for(i=0;i<q;i++)
	{
		if(bel[i<<1]==bel[(i<<1)|1])
		{
			cout<<"NO"<<endl;
			return 0;
		}
		nxt[bel[i<<1]].push_back(bel[(i<<1)|1]);
		nxt[bel[(i<<1)|1]].push_back(bel[i<<1]);
	}
	memset(col,-1,sizeof(col));
	memset(vis,false,sizeof(vis));
	for(i=0;i<(q<<1);i++)
	{
		if(mstch[i])
		{
			if(col[bel[i]]==1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			col[bel[i]]=0;
			dfs2(bel[i]);
		}
	}
	for(i=0;i<cnt;i++)
	{
		if(!vis[i])
		{
			if(col[i]!=-1)
			{
				cout<<"NO"<<endl;
				return 0;
			}
			col[i]=0;
			dfs2(i);
		}
	}
	cout<<"YES"<<endl;
	for(i=0;i<q;i++)
	{
		if(col[bel[i<<1]]==0)
		{
			update(qry[i].F,qry[i].S,allst[i]);
		}
		else
		{
			update(qry[i].S,qry[i].F,allst[i]);
		}
	}
	for(i=0;i<n;i++)
	{
		cout<<res[i];
	}
	return 0;
}