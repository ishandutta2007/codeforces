#include <bits/stdc++.h>
#define MAXN 100007
#define eps 0.00000001
using namespace std;
pair<int,int> k[MAXN];
bool vi[MAXN],fas;
vector<int> g[MAXN],st[MAXN],kf,c;
double sol[MAXN],x;
void dfs(int s)
{
	kf.push_back(k[s].second*k[s].first); c.push_back(s);
	vi[s]=true;
	for(int i=0;i<g[s].size();i++)
	{
		if(!vi[g[s][i]]) {k[g[s][i]]={-k[s].first,st[s][i]-k[s].second}; dfs(g[s][i]);}
		else
		{
			if(x==-1000000000)
			{
				pair<int,int> pr={k[s].first+k[g[s][i]].first,k[s].second+k[g[s][i]].second};
				if(pr.first==0) {if(pr.second!=st[s][i]) fas=true;}
				else x=((double)st[s][i]-pr.second)/((double)pr.first);
			}
			
			else if(abs(x*(k[s].first+k[g[s][i]].first)+(k[s].second+k[g[s][i]].second)-st[s][i])>eps) fas=true; 
		}
	}
}
int main()
{
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int t1,t2,t3;
		cin>>t1>>t2>>t3;
		g[t1].push_back(t2);
		g[t2].push_back(t1);
		st[t1].push_back(t3);
		st[t2].push_back(t3);
	}
	for(int i=1;i<=n;i++) if(!vi[i])
	{
		k[i]={1,0}; x=-1000000000; kf.clear(); c.clear();
		dfs(i); 
		if(x==-1000000000) {sort(kf.begin(),kf.end()); x=-kf[kf.size()/2];}
		for(int j=0;j<c.size();j++) sol[c[j]]=x*k[c[j]].first+k[c[j]].second;
	}
	if(fas) printf("NO");
	else
	{
		printf("YES\n");
		for(int i=1;i<=n;i++) printf("%f ",sol[i]);
	}
}