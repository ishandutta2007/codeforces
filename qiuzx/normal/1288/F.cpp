#include <bits/stdc++.h>
#define INF 1000000000
#define LINF 1000000000000000000
#define MOD 1000000007
#define mod 998244353
#define F first
#define S second
#define ll long long
#define N 510
using namespace std;
struct Edge{
	ll v,bkid,cap,cost,edid;
};
struct Flow{
	vector<Edge> vt[N];
	ll n,m,s,t,dep[N],cur[N],totcost;
	bool vis[N],inq[N];
	void init(ll _n)
	{
		n=_n,m=0,s=_n-2,t=_n-1;
		ll i;
		for(i=0;i<n;i++)
		{
			vt[i].clear();
		}
		return;
	}
	void addedge(ll x,ll y,ll w,ll c,ll id)
	{
		Edge cur;
		cur.v=y,cur.bkid=vt[y].size(),cur.cap=w,cur.cost=c,cur.edid=id;
		vt[x].push_back(cur);
		cur.v=x,cur.bkid=vt[x].size()-1,cur.cap=0,cur.cost=-c;
		vt[y].push_back(cur);
		return;
	}
	bool spfa()
	{
		queue<ll> q;
		ll i,x,w;
		for(i=0;i<n;i++)
		{
			dep[i]=LINF;
			inq[i]=false;
		}
		q.push(s);
		dep[s]=0;
		while(!q.empty())
		{
			x=q.front();
			w=dep[x];
			inq[x]=false;
			q.pop();
			for(i=0;i<vt[x].size();i++)
			{
				if(vt[x][i].cap>0&&dep[vt[x][i].v]>w+vt[x][i].cost)
				{
					dep[vt[x][i].v]=w+vt[x][i].cost;
					if(!inq[vt[x][i].v])
					{
						inq[vt[x][i].v]=true;
						q.push(vt[x][i].v);
					}
				}
			}
		}
		return (dep[t]<0);
	}
	ll dfs(ll x,ll lft)
	{
		vis[x]=true;
		if(x==t||lft<=0)
		{
			return lft;
		}
		ll i,v,ret=0;
		for(i=cur[x];i<vt[x].size();i++,cur[x]++)
		{
			if((!vis[vt[x][i].v])&&vt[x][i].cap>0&&dep[vt[x][i].v]==dep[x]+vt[x][i].cost)
			{
				v=dfs(vt[x][i].v,min(lft,vt[x][i].cap));
				totcost+=v*vt[x][i].cost;
				ret+=v;
				vt[x][i].cap-=v;
				vt[vt[x][i].v][vt[x][i].bkid].cap+=v;
				lft-=v;
				if(lft<=0)
				{
					break;
				}
			}
		}
		return ret;
	}
	ll min_cost_max_flow()
	{
		ll ret=0,i;
		totcost=0;
		while(spfa())
		{
			for(i=0;i<n;i++)
			{
				vis[i]=0;
				cur[i]=0;
			}
			ret+=dfs(s,LINF);
		}
		return totcost;
	}
}fl;
ll n1,n2,m,r,b,ans[N];
string s1,s2;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll i,j,x,y,num;
	cin>>n1>>n2>>m>>r>>b>>s1>>s2;
	num=n1+n2;
	fl.init(n1+n2+2);
	for(i=0;i<n1;i++)
	{
		if(s1[i]=='R')
		{
			fl.addedge(fl.s,i,1,-INF,-1);
			fl.addedge(fl.s,i,INF,0,-1);
		}
		else if(s1[i]=='B')
		{
			fl.addedge(i,fl.t,1,-INF,-1);
			fl.addedge(i,fl.t,INF,0,-1);
		}
		else
		{
			num--;
			fl.addedge(fl.s,i,INF,0,-1);
			fl.addedge(i,fl.t,INF,0,-1);
		}
	}
	for(i=0;i<n2;i++)
	{
		if(s2[i]=='B')
		{
			fl.addedge(fl.s,i+n1,1,-INF,-1);
			fl.addedge(fl.s,i+n1,INF,0,-1);
		}
		else if(s2[i]=='R')
		{
			fl.addedge(i+n1,fl.t,1,-INF,-1);
			fl.addedge(i+n1,fl.t,INF,0,-1);
		}
		else
		{
			num--;
			fl.addedge(fl.s,i+n1,INF,0,-1);
			fl.addedge(i+n1,fl.t,INF,0,-1);
		}
	}
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		x--,y--;
		y+=n1;
		fl.addedge(x,y,1,r,i);
		fl.addedge(y,x,1,b,i);
	}
	ll res=fl.min_cost_max_flow()+num*INF;
	if(res>=INF)
	{
		cout<<-1<<endl;
		return 0;
	}
	cout<<res<<endl;
	for(i=0;i<n1;i++)
	{
		vector<Edge> cur=fl.vt[i];
		for(j=0;j<cur.size();j++)
		{
			if(cur[j].edid!=-1&&cur[j].cost==r&&cur[j].cap==0)
			{
				ans[cur[j].edid]=1;
			}
		}
	}
	for(i=n1;i<n1+n2;i++)
	{
		vector<Edge> cur=fl.vt[i];
		for(j=0;j<cur.size();j++)
		{
			if(cur[j].edid!=-1&&cur[j].cost==b&&cur[j].cap==0)
			{
				ans[cur[j].edid]=-1;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		if(ans[i]==0)
		{
			cout<<"U";
		}
		else if(ans[i]==-1)
		{
			cout<<"B";
		}
		else
		{
			cout<<"R";
		}
	}
	return 0;
}