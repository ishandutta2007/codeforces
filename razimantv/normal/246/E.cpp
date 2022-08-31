# include <iostream>
# include <vector>
# include <map>
# include <string>
# include <algorithm>

using namespace std;

struct query
{
	int l,r,index;
	bool operator<(const query &q)const
	{
		return r<q.r;
	}
};

const int NMAX=100001,MMAX=100000;
int N,M;
int name[NMAX],numnames=1;
map<string,int> namemap;

vector<int>adjlist[NMAX];
int parent[NMAX][17];
int bfsarray[NMAX],bfspos[NMAX],level[NMAX];
int startlevel[NMAX],endlevel[NMAX];

int arrayforseg[NMAX],segtree[1<<18],base=1<<17;
map<int,int>posmap;
query querylist[MMAX];
int answer[MMAX];

int findparent(int u,int height,int w)
{
	if(u==-1)return -1;
	else if(height==0)return bfspos[u];
	else if(height&(1<<w))return findparent(parent[u][w],height^(1<<w),w+1);
	else return findparent(u,height,w+1);
}

void update(int pos,int delta)
{
	while(pos)
	{
		segtree[pos]+=delta;
		pos>>=1;
	}
}

int findcount(int node,int l,int r,int L,int R)
{
	if(l==L&&r==R)return segtree[node];
	int M=(L+R)>>1;
	if(r<=M)return findcount(node<<1,l,r,L,M);
	else if(l>M)return findcount((node<<1)|1,l,r,M+1,R);
	else return findcount(node<<1,l,M,L,M)+findcount((node<<1)|1,M+1,r,M+1,R); 
}

int main()
{
	cin>>N;
	for(int i=1;i<=N;i++)
	{
		string nm;
		int par;
		cin>>nm>>par;

		if(namemap.count(nm))name[i]=namemap[nm];
		else	namemap[nm]=name[i]=numnames++;

		adjlist[par].push_back(i);
	}

	bfsarray[0]=bfspos[0]=arrayforseg[0]=level[0]=0;
	parent[0][0]=-1;
	for(int i=0,j=1;i<=N;i++)
	{
		int u=bfsarray[i];
		for(int k=0;k<adjlist[u].size();j++,k++)
		{
			int v=adjlist[u][k];
			parent[v][0]=u;
			bfsarray[j]=v;
			arrayforseg[j]=name[v];
			bfspos[v]=j;
			level[v]=level[u]+1;
			if(startlevel[level[v]]==0)startlevel[level[v]]=j;
			endlevel[level[v]]=j;
		}
	}

	for(int i=1;i<17;i++)
		for(int u=0;u<=N;u++)
			parent[u][i]=(parent[u][i-1]==-1)?-1:parent[parent[u][i-1]][i-1];

	cin>>M;
	for(int i=0;i<M;i++)
	{
		int u,depth;
		cin>>u>>depth;
		querylist[i].index=i;
		int start=0,end=N+1,mid;
		while(end-start>1)
		{
			mid=(start+end)>>1;
			if(findparent(bfsarray[mid],depth,0)<bfspos[u])start=mid;
			else end=mid;
		}
		querylist[i].l=end;
		start=0,end=N+1;	
		while(end-start>1)
		{
			mid=(start+end)>>1;
			if(findparent(bfsarray[mid],depth,0)<=bfspos[u])start=mid;
			else end=mid;
		}
		querylist[i].r=start;
	}
	sort(querylist,querylist+M);

	int next=0;
	for(int i=0;i<M;i++)
	{
		for(;next<=querylist[i].r;next++)
		{
			int thisnum=arrayforseg[next];
			if(posmap.count(thisnum))update(base+posmap[thisnum],-1);
			posmap[thisnum]=next;
			update(base+next,1);
		}
		if(querylist[i].r<querylist[i].l)answer[querylist[i].index]=0;
		else answer[querylist[i].index]=findcount(1,querylist[i].l,querylist[i].r,0,base-1);
	}

	for(int i=0;i<M;i++)
		cout<<answer[i]<<endl;
	return 0;
}