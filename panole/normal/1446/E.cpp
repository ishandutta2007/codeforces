#include<bits/stdc++.h>
using namespace std;

int n,l,r,id[1010][1010];
bool bo[1010][1010];

struct node
{
	int x,y;
	void init() {scanf("%d%d",&x,&y);}
	pair<vector<node>,int> e()
	{
		vector<node> v; int c=0;
		v.push_back((node){x+1,y});
		if (x>0) v.push_back((node){x-1,y}); else c++;
		if (x&1) {if (x>0) v.push_back((node){x-1,y+1}); else c++;}
		else {if (y>0) v.push_back((node){x+1,y-1}); else c++;}
		return make_pair(v,c);
	}
}a[250010],q[2500010];

vector<node> V; 

void dfs(node x,node la)
{
	if (bo[x.x][x.y]) puts("SICK"),exit(0);
	V.push_back(x),bo[x.x][x.y]=1;
	vector<node> v=x.e().first;
	for (int j=0,sz=v.size(); j<sz; j++)
		if (id[v[j].x][v[j].y]&&(v[j].x!=la.x||v[j].y!=la.y)) dfs(v[j],x);
}

int main()
{
	scanf("%d",&n);
	for (int i=1; i<=n; i++) a[i].init(),bo[a[i].x][a[i].y]=1;
	l=1,r=n;
	for (int i=1; i<=n; i++) q[i]=a[i];
	while (l<=r)
	{
		id[q[l].x][q[l].y]=l;
		vector<node> u=q[l].e().first,v;
		for (int j=0,sz=u.size(); j<sz; j++)
		{
			if (bo[u[j].x][u[j].y]) continue;
			v=u[j].e().first;
			for (int k=0,Sz=v.size(); k<Sz; k++)
				if (id[v[k].x][v[k].y]&&id[v[k].x][v[k].y]!=l) {q[++r]=u[j],bo[u[j].x][u[j].y]=1; break;}
		}
		l++;
	}
	int cnt=0,ans=0;
	memset(bo,0,sizeof(bo));
	for (int i=1; i<=r; i++) if (!bo[q[i].x][q[i].y]) 
	{
		V.clear();
		cnt++,dfs(q[i],(node){-1,-1});
		if (V.size()==4)
		{
			int cc=0;
			for (int j=0; j<4; j++) if (id[V[j].x][V[j].y]>n)
			{
				cc++;
				vector<node> v=V[j].e().first;
				if (v.size()==3)
				{
					for (int k=0; k<4; k++) if (k!=j)
					{
						bool bo=0;
						for (int l=0; l<3; l++)
							if (V[k].x==v[l].x&&V[k].y==v[l].y) bo=1;
						if (bo) cc-=10;
					}
				}
			}
			if (cc==-29) cnt++;
		}
	}
	for (int i=n+1; i<=r; i++) id[q[i].x][q[i].y]=0;
	for (int i=1; i<=n; i++)
	{
		pair<vector<node>,int> v=q[i].e();
		ans+=v.second;
		for (int u,j=0,sz=v.first.size(); j<sz; j++)
			if (!id[v.first[j].x][v.first[j].y]) ans++;
	}
	printf("RECOVERED\n%d\n",ans-2*cnt);
	return 0;
}