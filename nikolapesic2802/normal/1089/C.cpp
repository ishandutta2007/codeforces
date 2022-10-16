#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
const int N=1005;
const int M=2*N;
struct Cactus
{
	vector<int> G[M],E[M];
	vector<int> Cycle[M];
	vector<pair<int,int> > edges;
	int cc,nc;
	set<int> myCycle[M];
	Cactus(){}
	int par[M],dep[M],was[M];
	bool ban[M];
	int sz[M];
	int mark[M];
	set<pair<int,int> > bad;
	void Clear()
	{
		for(int i=0;i<M;i++)
		{
			G[i].clear();
			E[i].clear();
			Cycle[i].clear();
			myCycle[i].clear();
			par[i]=0;
			dep[i]=0;
			was[i]=0;
			ban[i]=0;
			sz[i]=0;
			mark[i]=0;
		}
		edges.clear();
		bad.clear();
		cc=0;
		nc=0;
	}
	void SetN(int n){ nc=n;cc=n;}
	void AddCactusEdge(int u, int v)
	{
		edges.pb(mp(u,v));
		G[u].pb(v);
		G[v].pb(u);
	}
	void DFS(int u, int p)
	{
		was[u]=1;
		par[u]=p;
		dep[u]=dep[p]+1;
		for(int v:G[u]) if(!was[v]) DFS(v,u);
	}
	vector<int> FindCycle(int u, int v)
	{
		if(dep[u]<dep[v]) swap(u,v);
		vector<int> x,y;
		while(dep[u]>dep[v])
		{
			x.pb(u);u=par[u];
		}
		while(u!=v)
		{
			x.pb(u);y.pb(v);
			u=par[u];v=par[v];
		}
		x.pb(u);
		reverse(y.begin(),y.end());
		for(int i:y) x.pb(i);
		return x;
	}
	void AddEdge(int u, int v)
	{
		E[u].pb(v);
		E[v].pb(u);
		//printf("(%i %i)\n",u,v);
	}
	void BuildCactusTree()
	{
		DFS(1,0);
		for(auto e:edges)
		{
			int u=e.first;
			int v=e.second;
			if(par[u]!=v && par[v]!=u)
			{
				cc++;
				Cycle[cc]=FindCycle(u,v);
				for(int i:Cycle[cc])
				{
					myCycle[i].insert(cc);
					AddEdge(cc,i);
				}
				for(int i=1;i<Cycle[cc].size();i++)
				{
					bad.insert(mp(Cycle[cc][i],Cycle[cc][i-1]));
				}
				bad.insert(mp(Cycle[cc][0],Cycle[cc].back()));
			}
		}
		for(auto e:edges)
		{
			int u=e.first;
			int v=e.second;
			if(!bad.count(mp(u,v)) && !bad.count(mp(v,u))) AddEdge(u,v);
		}
	}
	void DFSSZ(int u, int p, int &n)
	{
		sz[u]=1;
		n++;
		//printf("%i %i %i\n",u,p,n);
		for(int v:E[u]) if(v!=p && !ban[v]) DFSSZ(v,u,n),sz[u]+=sz[v];
	}
	int FindCentroid(int u, int p, int n)
	{
		for(int v:E[u])
		{
			//printf("%i p:%i -> %i sz:%i\n",u,p,v,sz[v]);
			if(v!=p && !ban[v] && sz[v]>n/2) return FindCentroid(v,u,n);
		}
		return u;
	}
	int FindCentroid(int u){ int n=0;DFSSZ(u,u,n);return FindCentroid(u,u,n);}
	void DFSMark(int u, int p, int m)
	{
		mark[u]=m;
		for(int v:E[u]) if(v!=p) DFSMark(v,u,m);
	}
	void Rotate(vector<int> &v, int f)
	{
		int i;
		for(i=0;i<v.size();i++) if(v[i]==f) break;
		vector<int> tmp;
		for(int j=i;j<v.size();j++) tmp.pb(v[j]);
		for(int j=0;j<i;j++) tmp.pb(v[j]);
		v=tmp;
	}
	void Solve(int fir)
	{
		int cen=FindCentroid(fir);
		//printf("cen: %i\n",cen);
		if(cen<=nc && myCycle[cen].empty())
		{
			printf("%i\n",cen);
			fflush(stdout);
			char s[10];
			scanf("%s",s);
			if(s[0]=='F') return;
			int go;
			scanf("%i",&go);
			ban[cen]=1;
			Solve(go);
		}
		else if(cen<=nc && myCycle[cen].size())
		{
			for(int cyc:myCycle[cen])
			{
				Rotate(Cycle[cyc],cen);
				ban[cyc]=1;
				for(int i:Cycle[cyc]) if(i!=cen) myCycle[i].erase(cyc);
				//printf("cen:%i cyc:%i\n",cen,cyc);
				for(int i=1;i+1<Cycle[cyc].size();i++)
				{
					AddEdge(Cycle[cyc][i],Cycle[cyc][i+1]);
				}
			}
			myCycle[cen].clear();
			printf("%i\n",cen);
			fflush(stdout);
			char s[10];
			scanf("%s",s);
			if(s[0]=='F') return;
			int go;
			scanf("%i",&go);
			ban[cen]=1;
			Solve(go);
		}
		else
		{
			int cyc;
			if(cen<=nc) cyc=*myCycle[cen].begin();
			if(cen>nc) cyc=cen;
			//printf(":D cyc:%i cen:%i\n",cyc,cen);
			vector<int> pref(Cycle[cyc].size()+1,0);
			int n=0;
			DFSSZ(cyc,cyc,n);
			int sze=Cycle[cyc].size(),hal=(sze+2)/2;
			for(int i=0;i<Cycle[cyc].size();i++)
			{
				pref[i+1]=pref[i]+sz[Cycle[cyc][i]];
			}
			int best=0,val=n;
			for(int i=1;i<=sze;i++)
			{
				int tmp1=0,tmp2=0,tmp;
				for(int j=1;j<=hal;j++)
				{
					int v=Cycle[cyc][(i+j-1)%sze];
					tmp1+=sz[v];
					v=Cycle[cyc][(i-1-j+sze)%sze];
					tmp2+=sz[v];
				}
				/*if(i+hal-1<=sze)
				{
					tmp1=pref[i+hal-1]-pref[i];
					tmp2=pref[i-1]+pref[sze]-pref[sze-hal+i-1];
				}
				else
				{
					tmp1=pref[i-1]-pref[i-hal];
					tmp2=pref[i-hal]+pref[sze]-pref[sze-hal+i-hal];
				}*/
				tmp=max(tmp1,tmp2);//n-tmp-sz[Cycle[cyc][i-1]]);
				for(int v:E[Cycle[cyc][i-1]]) if(v!=cyc && !ban[v])
				{
					tmp=max(tmp,sz[v]);
				}
				if(tmp<=val) best=Cycle[cyc][i-1],val=tmp;
			}
			printf("%i\n",best);
			fflush(stdout);
			char s[10];
			scanf("%s",s);
			if(s[0]=='F') return;
			ban[cyc]=1;
			ban[best]=1;
			Rotate(Cycle[cyc],best);
			int go;
			scanf("%i",&go);
			for(int i:Cycle[cyc]) myCycle[i].erase(cyc);
			if(go==Cycle[cyc][1])
			{
				//printf("go:%i Cycle:%i\n",go,Cycle[cyc][1]);
				for(int i=1;i+1<hal;i++)
				{
					AddEdge(Cycle[cyc][i],Cycle[cyc][i+1]);
				}
				Solve(go);
			}
			else if(go==Cycle[cyc].back())
			{
				//printf("go:%i CycleBack:%i cyc:%i\n",go,Cycle[cyc].back(),cyc);
				for(int i=1;i+1<hal;i++)
				{
					AddEdge(Cycle[cyc][sze-i],Cycle[cyc][sze-i-1]);
				}
				Solve(go);
			}
			else
			{
				//printf("AC\n");
				for(int cyc:myCycle[best])
				{
					Rotate(Cycle[cyc],best);
					ban[cyc]=1;
					//printf("Erase Cycle: %i\n",cyc);
					for(int i:Cycle[cyc]) if(i!=best) myCycle[i].erase(cyc);
					for(int i=1;i+1<Cycle[cyc].size();i++)
					{
						AddEdge(Cycle[cyc][i],Cycle[cyc][i+1]);
					}
				}
				myCycle[best].clear();
				Solve(go);
			}
		}
	}
};
int main()
{
	vector<pair<int,int> > edges;
	set<pair<int,int> > was;
	int n,i,u,v,m;
	scanf("%i %i",&n,&m);
	while(m--)
	{
		int k;
		scanf("%i",&k);
		vector<int> us;
		while(k--) scanf("%i",&u),us.pb(u);
		for(int i=1;i<us.size();i++)
		{
			u=us[i];
			v=us[i-1];
			if(u>v) swap(u,v);
			if(!was.count(mp(u,v))) edges.pb(mp(u,v));
			was.insert(mp(u,v));
		}
	}
	Cactus Solver;
	for(int j=1;j<=n;j++)
	{
		Solver.Clear();
		Solver.SetN(n);
		for(auto p:edges) Solver.AddCactusEdge(p.first,p.second);
		Solver.BuildCactusTree();
		//printf(":D\n");
		Solver.Solve(1);
	}
	return 0;
}