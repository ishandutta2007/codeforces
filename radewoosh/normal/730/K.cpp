#include <bits/stdc++.h>
using namespace std;

struct node
{
	int id;
	int roz;
	int pri;
	node * lew;
	node * pra;
	node * oj;
	node()
	{
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		pri=rand();
	}
	node(int idid)
	{
		id=idid;
		lew=NULL;
		pra=NULL;
		oj=NULL;
		roz=1;
		pri=rand();
	}
	void update()
	{
		roz=1;
		if (lew!=NULL)
			roz+=lew->roz;
		if (pra!=NULL)
			roz+=pra->roz;
	}
};

node * merge(node * v, node * u)
{
	if (v==NULL)
		return u;
	if (u==NULL)
		return v;
	if ((v->pri)>=(u->pri))
	{
		v->pra=merge(v->pra, u);
		if (v->pra!=NULL)
			v->pra->oj=v;
		v->update();
		return v;
	}
	else
	{
		u->lew=merge(v, u->lew);
		if (u->lew!=NULL)
			u->lew->oj=u;
		u->update();
		return u;
	}
}

pair <node*, node*> split(node * v, int chceroz)
{
	if (v==NULL)
		return make_pair(v, v);
	v->oj=NULL;
	int nalew=1;
	if (v->lew!=NULL)
		nalew+=v->lew->roz;
	if (nalew<=chceroz)
	{
		pair <node*, node*> ret=split(v->pra, chceroz-nalew);
		v->pra=ret.first;
		if (v->pra!=NULL)
			v->pra->oj=v;
		v->update();
		ret.first=v;
		return ret;
	}
	else
	{
		pair <node*, node*> ret=split(v->lew, chceroz);
		v->lew=ret.second;
		if (v->lew!=NULL)
			v->lew->oj=v;
		v->update();
		ret.second=v;
		return ret;
	}
}

int poznaj(node * v, int czytu)
{
	int ret=1;
	if (v->lew!=NULL)
		ret+=v->lew->roz;
	if (!czytu)
		ret=0;
	if (v->oj==NULL)
		return ret;
	return ret+poznaj(v->oj, ((v->oj->pra)==v));
}

node * korz;

int t;

int n, m;

int ss, tt;

vector <int> graf[1000007];

int bylo[1000007];

int ojc[1000007];

int odl[1000007];

int juz[1000007];

vector < pair < int , pair <int,int> > > kan;

vector <int> pro;

int ostkol[1000007];

node * wsk[1000007];

void czys()
{
	for (int i=1; i<=n; i++)
		bylo[i]=0;
}

void dfs1(int v, int oj)
{
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==oj)
			swap(graf[v][i], graf[v][0]);
	}
	for (int i=0; i<graf[v].size(); i++)
		if (!bylo[graf[v][i]])
			dfs1(graf[v][i], v);
}

void dfs2(int v)
{
	bylo[v]=1;
	for (int i=0; i<graf[v].size(); i++)
	{
		if (graf[v][i]==ojc[v])
			continue;
		if (!bylo[graf[v][i]])
		{
			odl[graf[v][i]]=odl[v]+1;
			ojc[graf[v][i]]=v;
			dfs2(graf[v][i]);
			continue;
		}
		if (odl[v]>odl[graf[v][i]])
			kan.push_back(make_pair(odl[graf[v][i]], make_pair(v, graf[v][i])));
	}
}

int main()
{
	srand(69);
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d%d%d%d", &n, &m, &ss, &tt);
		for (int i=1; i<=n; i++)
			graf[i].clear();
		for (int i=1; i<=n; i++)
			wsk[i]=NULL;
		for (int i=1; i<=n; i++)
			juz[i]=0;
		for (int i=1; i<=m; i++)
		{
			int p1, p2;
			scanf("%d%d", &p1, &p2);
			graf[p1].push_back(p2);
			graf[p2].push_back(p1);
		}
		czys();
		dfs1(tt, 0);
		czys();
		odl[ss]=1;
		kan.clear();
		ojc[ss]=0;
		dfs2(ss);
		sort(kan.begin(), kan.end());
		pro.clear();
		int pom=tt;
		korz=NULL;
		while(pom)
		{
			wsk[pom]=new node(pom);
			korz=merge(wsk[pom], korz);
			juz[pom]=1;
			pom=ojc[pom];
		}
		for (int i=0; i<kan.size(); i++)
		{
			int x=kan[i].second.first;
			int y=kan[i].second.second;
			if (juz[x])
				continue;
			vector <int> stos;
			int pom=x;
			while(!juz[pom])
			{
				if (pom==y)
                    break;
				stos.push_back(pom);
				pom=ojc[pom];
			}
			if (pom==y)
				break;
			int raz=poznaj(wsk[y], 1);
			int dwa=poznaj(wsk[pom], 1);
			if (raz>dwa)
			{
				swap(raz, dwa);
				swap(y, pom);
				reverse(stos.begin(), stos.end());
			}
			node * nowy = NULL;
			for (int j=0; j<stos.size(); j++)
			{
				wsk[stos[j]]=new node(stos[j]);
				nowy=merge(nowy, wsk[stos[j]]);
				juz[stos[j]]=1;
			}
			pair <node *, node *> bier=split(korz, raz);
			korz=merge(merge(bier.first, nowy), bier.second);
		}
		if (korz->roz!=n)
		{
			printf("No\n");
			continue;
		}
		for (int i=1; i<=n; i++)
			ostkol[i]=poznaj(wsk[i], 1);
		printf("Yes\n");
		for (int i=1; i<=n; i++)
		{
			for (int j=0; j<graf[i].size(); j++)
			{
				if (ostkol[i]<=ostkol[graf[i][j]])
				{
					printf("%d %d\n", i, graf[i][j]);
				}
			}
		}
	}
	return 0;
}