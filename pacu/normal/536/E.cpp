#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int coef[100000];

class arr
{
private:
	int *llen;
	int *segval;
	int *rlen;
	int *l;
	int *r;
	int SEG;
	int N;
public:
	arr(int n)
	{
		SEG = 1;
		while(SEG < n)
			SEG *= 2;
		N = n;
		llen = new int[2*SEG];
		rlen = new int[2*SEG];
		segval = new int[2*SEG];
		l = new int[2*SEG];
		r = new int[2*SEG];
		for(int i=SEG;i<2*SEG;i++)
			l[i] = r[i] = i-SEG;
		for(int i=SEG-1;i>0;i--)
			l[i] = l[2*i], r[i] = r[2*i+1];
		for(int i=0;i<2*SEG;i++)
			llen[i] = rlen[i] = segval[i] = 0;
	}
	void update(int i)
	{
		i += SEG;
		llen[i] = rlen[i] = 1;
		segval[i] = 0;
		int sz = 1;
		for(i/=2;i>0;i/=2, sz *= 2)
		{
			if(llen[2*i] == sz && rlen[2*i+1] == sz)
				llen[i] = sz+sz, rlen[i] = sz+sz, segval[i] = 0;
			else if(llen[2*i] == sz)
				llen[i] = sz+llen[2*i+1], rlen[i] = rlen[2*i+1], segval[i] = segval[2*i+1];
			else if(rlen[2*i+1] == sz)
				rlen[i] = sz+rlen[2*i], llen[i] = llen[2*i], segval[i] = segval[2*i];
			else
				llen[i] = llen[2*i], rlen[i] = rlen[2*i+1], segval[i] = segval[2*i] + segval[2*i+1] + coef[rlen[2*i]+llen[2*i+1]];
		}
	}
	void getVal(int i,int low,int high,int &gllen,int &grlen, int &gsegval,int &sz)
	{
		if(l[i] >= low && r[i] <= high)
		{
			gllen = llen[i], grlen = rlen[i], gsegval = segval[i],sz=r[i]+1-l[i];
			return;
		}
		if(high <= r[2*i])
		{
			getVal(2*i,low,high,gllen,grlen,gsegval,sz);
			return;
		}
		else if(low >= l[2*i+1])
		{
			getVal(2*i+1,low,high,gllen,grlen,gsegval,sz);
			return;
		}
		int al,ar,av,bl,br,bv,fl,asz,bsz;
		getVal(2*i,low,high,al,ar,av,asz);
		getVal(2*i+1,low,high,bl,br,bv,bsz);
		if(al==asz && bl==bsz)
			gllen = asz+bsz, grlen = asz+bsz, gsegval = 0;
		else if(al==asz)
			gllen = asz+bl, grlen = br, gsegval = bv;
		else if(bl==bsz)
			grlen = bsz+ar, gllen = al, gsegval = av;
		else
			gllen = al, grlen = br, gsegval = av + bv + coef[ar+bl];
		sz = asz+bsz;
//		cout << l[i] << ' ' << r[i] << ": " << gllen << ' ' << grlen << ' ' << gsegval << '\n';
	}
};

int N;
int loc[100000];		//index of vertex in dfs ordering
int dorder[1000000];		//depths of vertices in dfs ordering
int oSize = 0;

#define SEGLCA (1<<18)
int segLCA[2*SEGLCA],ll[2*SEGLCA],rr[2*SEGLCA];

void init()
{
	for(int i=SEGLCA;i<2*SEGLCA;i++)
		ll[i] = rr[i] = i-SEGLCA, segLCA[i] = (((i-SEGLCA)<oSize)?dorder[i-SEGLCA]:1000000);
	for(int i=SEGLCA-1;i>0;i--)
	{
		segLCA[i] = min(segLCA[2*i],segLCA[2*i+1]);
		ll[i] = ll[2*i], rr[i] = rr[2*i+1];
	}
}

int getLCA(int i,int low,int high)
{
	if(ll[i] > high || rr[i] < low) return 1000000;
	if(ll[i] >= low && rr[i] <= high) return segLCA[i];
	return min(getLCA(2*i,low,high),getLCA(2*i+1,low,high));
}

int nCh;
int head[100000];	//head of chain
arr *A[100000];

int cPos[200000];		//position in chain of edge
int cNum[200000];		//index of chain of edge
int parEdge[200000];	//parent edge of a vertex
int par[200000];		//parent of a vertex
int nxt[200000];
int val[200000];
int eWeight[200000];
vector<int> edges[100000];
bool vis[100000];
int subsize[100000];

int dfs1(int i,int d)
{
	vis[i] = 1;
	subsize[i] = 1;
	loc[i] = oSize;
	dorder[oSize++] = d;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[nxt[edges[i][j]]])
		{
			par[nxt[edges[i][j]]] = i;
			parEdge[nxt[edges[i][j]]] = edges[i][j];
			subsize[i] += dfs1(nxt[edges[i][j]],d+1);
			dorder[oSize++] = d;
		}
	}
	vis[i] = 0;
	return subsize[i];
}

int dfs2(int i,int heavylen)
{
	vis[i] = 1;
	int hEdge = -1;
	int downlen = 0;
	for(int j=0;j<edges[i].size();j++)
	{
		if(!vis[nxt[edges[i][j]]])
		{
			if(2*subsize[nxt[edges[i][j]]] > subsize[i])
			{
//				cout << subsize[i] << ' ' << subsize[nxt[edges[i][j]]] << '\n';
				hEdge = edges[i][j];
				if(heavylen == 0)
				{
					head[nCh] = i;
					cNum[hEdge] = nCh;
					cPos[hEdge] = 0;
					nCh++;			
				}
				else
				{
					cNum[hEdge] = cNum[parEdge[i]];
					cPos[hEdge] = 1+cPos[parEdge[i]];					
				}
				downlen = 1+dfs2(nxt[edges[i][j]],heavylen+1);
				if(heavylen == 0)
					A[cNum[hEdge]] = new arr(downlen);
			}
			else
				dfs2(nxt[edges[i][j]],0);
		}
	}
	vis[i] = 0;
	return downlen;
}

int eid[100000];

bool cmpe(int a,int b)
{
	return eWeight[a] > eWeight[b];
}

int u[100000],v[100000],len[100000],qid[100000],ans[100000];

bool cmpq(int a,int b)
{
	return len[a] > len[b];
}

void getSubarr(int cur,int hDepth,int &av,int &ar)
{
	int curDepth = dorder[loc[cur]];
//	cout << curDepth << ' ' << hDepth << '\n';
	int low,e;
	int cl,cr,cv,csz;
	ar = av = 0;
	while(curDepth != hDepth)
	{
		e = parEdge[cur];
//		cout << "Edge " << e << '\n';
		if(cNum[e] == -1)
		{
//			cout << "val " << val[e] << '\n';
			if(val[e]) ar++;
			else
			{
				av += coef[ar];
				ar = 0;
			}
			cur = par[cur];
			curDepth--;
		}
		else
		{
			low = max(0,cPos[e]-(curDepth-hDepth-1));
			A[cNum[e]]->getVal(1,low,cPos[e],cl,cr,cv,csz);
//			cout << "chain " << cl << ' ' << cr << ' ' << cv << '\n';
			if(cr == (cPos[e]+1-low)) ar += cr;
			else
			{
				av = av + coef[ar+cr] + cv;
				ar = cl;
			}
			if(low == 0)
			{
				cur = head[cNum[e]];
				curDepth -= (cPos[e]+1-low);
			}
			else
				curDepth = hDepth;
		}
	}	
}

int main()
{
	cin.tie(0);
	ios::sync_with_stdio(0);
	int Q;
	cin >> N >> Q;
	for(int i=1;i<N;i++)
		cin >> coef[i];
	int a,b,w;
	for(int i=0;i<N-1;i++)
	{
		cin >> a >> b >> w;
		a--,b--;
		edges[a].push_back(2*i);
		nxt[2*i] = b, nxt[2*i+1] = a;
		edges[b].push_back(2*i+1);
		cNum[2*i] = cNum[2*i+1] = -1;
		eWeight[2*i] = eWeight[2*i+1] = w;
	}
	dfs1(0,0);
	dfs2(0,0);
	init();
//	for(int i=0;i<2*N-2;i++)
//		cout << "Chain #: " << cNum[i] << ' ' << cPos[i] << '\n';
	int cc = 0;
	for(int i=0;i<N;i++)
		for(int j=0;j<edges[i].size();j++)
			if(subsize[nxt[edges[i][j]]] < subsize[i])
				eid[cc++] = edges[i][j];
	sort(eid,eid+N-1,cmpe);
	for(int i=0;i<Q;i++)
	{
		cin >> u[i] >> v[i] >> len[i];
		u[i]--,v[i]--;
		qid[i] = i;
	}
	sort(qid,qid+Q,cmpq);
	int curq;
	int j = 0;
	int al,ar,av,asz,bl,br,bv,bsz;
//	cout << endl;
	for(int i=0;i<Q;i++)
	{
		curq = qid[i];
//		cout << u[curq] << ' ' << v[curq] << ' ' << len[curq] << '\n';
		while(j < N-1 && eWeight[eid[j]] >= len[curq])
		{
			if(cNum[eid[j]] != -1)
				A[cNum[eid[j]]]->update(cPos[eid[j]]);
			val[eid[j]] = 1;
			j++;
		}
		if(loc[u[curq]] > loc[v[curq]]) swap(u[curq],v[curq]);
		int hDepth = getLCA(1,loc[u[curq]],loc[v[curq]]);
		int curDepth = dorder[loc[u[curq]]];
		getSubarr(u[curq],hDepth,av,ar);
		getSubarr(v[curq],hDepth,bv,br);
		ans[curq] = av + bv + coef[ar+br];
	}
	for(int i=0;i<Q;i++)
		cout << ans[i] << '\n';
}