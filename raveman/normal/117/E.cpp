#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
 
using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
int p[111111];
int P(int x){return p[x]==x?x:p[x]=P(p[x]);}
int ta,tb;
vector<pii> v[111111];
int lca[111111][20];
int s[111111];
int d[111111];

int dfs(int ver, int par=-1,int depth=0){
	lca[ver][0]=par;
	d[ver]=depth;
	s[ver]=1;
	REP(i,v[ver].size()) if(v[ver][i].first!=par)
		s[ver] += dfs(v[ver][i].first,ver,depth+1);
	return s[ver];
}

int covered[111111];
int edge_pos[111111];
int pr[111111];
int S[1<<18];
int pos;

void addPath(int ver){
	vi path;
	while(1){
		path.pb(ver);
		if(covered[ver]>=0 || path.size()>=2 && s[path[path.size()-2]] < s[ver]/2) break;
		ver = lca[ver][0];
		if(ver==-1) break;
	}
	REP(i,path.size()-1){
		if(i) pr[path[i]] = path[i-1];
		covered[path[i]]=path[path.size()-2];
		edge_pos[path[i]] = pos++;
	}
}

void dfs2(int ver,int par=-1){
	REP(i,v[ver].size()) if(v[ver][i].first!=par)
		dfs2(v[ver][i].first,ver);
	if(par!=-1 && covered[ver]==-1) addPath(ver);
}

int getParent(int ver,int num){
	for(int i=17;i>=0;i--)
		if((1<<i)<=num)
			ver = lca[ver][i],num-=(1<<i);
	return ver;
}
int getLCA(int x,int y){
	if(d[x]<d[y]) swap(x,y);
	x = getParent(x, d[x] - d[y]);
	for(int i=17;i>=0;i--)
		if(lca[x][i]!=lca[y][i])
			x=lca[x][i],y=lca[y][i];
	if(x!=y) x = lca[x][0],y = lca[y][0];
	return x;
}

struct Node{
	int l,r;
	int sum;
	bool rev;
	Node *lf;
	Node *rg;
	Node(){lf=rg=0;sum=rev=l=r=0;}
};

int getSum(Node *node){
	if(node->rev) return node->r-node->l+1-node->sum;
	return node->sum;
}
void treeInverse(Node *curr,int l,int r){
	if(r<curr->l || l>curr->r) return;
	if(l<=curr->l  && r>=curr->r) curr->rev ^= 1;
	else{
		if(curr->rev){
			curr->lf->rev^=1;
			curr->rg->rev^=1;
			curr->rev=0;
		}
		treeInverse(curr->lf,l,r);
		treeInverse(curr->rg,l,r);
		curr->sum = getSum(curr->lf)+getSum(curr->rg);
	}
}
int getSum(Node *curr,int l,int r){
	if(r<curr->l || l>curr->r) return 0;
	if(l<=curr->l  && r>=curr->r) return getSum(curr);
	else{
		if(curr->rev){
			curr->lf->rev^=1;
			curr->rg->rev^=1;
			curr->rev=0;
		}
		curr->sum = getSum(curr->lf)+getSum(curr->rg);
		return getSum(curr->lf,l,r)+getSum(curr->rg,l,r);
	}
}

int W,cycle;
Node *root;

Node *buildTree(int l,int r){
	Node *curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l!=r){
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
	}
	return curr;
}

void modify(int from,int to){
	if(from==to) return;
	if(covered[to] == covered[from])		treeInverse(root, edge_pos[from], edge_pos[pr[to]]);
	else if(lca[covered[from]][0] == to)    treeInverse(root, edge_pos[from], edge_pos[covered[from]]);
	else									treeInverse(root, edge_pos[from], edge_pos[covered[from]]),modify(lca[covered[from]][0],to);
}

int getNum(int from,int to){
	if(from==to) return 0;
	if(covered[to] == covered[from])		return getSum(root, edge_pos[from], edge_pos[pr[to]]);
	else if(lca[covered[from]][0] == to)    return getSum(root, edge_pos[from], edge_pos[covered[from]]);
	else									return getSum(root, edge_pos[from], edge_pos[covered[from]]) + getNum(lca[covered[from]][0],to);
}

int fullCycle(){
	if(!cycle) return 0;
	return getNum(ta,W)+getNum(tb,W)==d[ta]+d[tb]-2*d[W];
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) p[i]=i;	
	CL(lca,-1);
	REP(i,n){
		int x,y;
		scanf("%d %d",&x,&y);x--,y--;
		if(P(x)==P(y)) ta=x,tb=y;
		else p[P(x)]=P(y),v[x].pb(pii(y,i)),v[y].pb(pii(x,i));
	}
	dfs(0);
	FOR(j,1,20) REP(i,n) if(lca[i][j-1]!=-1)
		lca[i][j] = lca[lca[i][j-1]][j-1];

	CL(pr,-1);CL(covered,-1);
	
	dfs2(0);

	root = buildTree(0,n-2);
	W = getLCA(ta,tb);

	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);x--,y--;
		int par = getLCA(x,y);
		int dist1 = d[x] + d[y] - 2 * d[par];

		int first = ta;
		int second = tb;
		int par1_1 = getLCA(x,ta);
		int par1_2 = getLCA(y,tb);
		int dist2 = d[x] + d[ta] - 2 * d[par1_1] + d[y] + d[tb] - 2 * d[par1_2] + 1;

		int par2_1 = getLCA(x,tb);
		int par2_2 = getLCA(y,ta);
		int dist3 = d[x] + d[tb] - 2 * d[par2_1] + d[y] + d[ta] - 2 * d[par2_2] + 1;
		if(dist3 < dist2) first = tb,second = ta,par1_1 = par2_1,par1_2 = par2_2,dist2 = dist3;

		bool smallest = false;
		if(dist1==dist2){
			int down = -1;
			if(par1_1 == first) down = second;
			else down = getParent(first, d[first] - d[par1_1] - 1);
			if(par1_1==par){
				int v1 = getParent(y, d[y] - d[par] -1 );
				if(v1!=down){
					if(v1 < down) smallest= true;
				}else{
					int z = getLCA(first, y);
					if(z == first) down = second;
					else down = getParent(first, d[first] - d[z] - 1);
					if( getParent(y, d[y] - d[z] -1 ) < down) smallest= true;
				}
			}
			else if(d[par1_1] > d[par]){
				if(lca[par1_1][0] < down) smallest = true;
			}else if(lca[par][0] > getParent(y, d[y] - d[par] -1 )) smallest = true;
		}
		if(dist1<dist2 || dist1==dist2 && smallest){
			modify(x, par);
			modify(y, par);
		}else{
			modify(x, par1_1);
			modify(first, par1_1);
			cycle^=1;
			modify(y, par1_2);
			modify(second, par1_2);
		}

		printf("%d\n",n-getSum(root)-cycle+fullCycle());
	}
	
#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}