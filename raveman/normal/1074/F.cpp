#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdlib>
#include<memory.h>
#include<ctime>
#include<bitset>
#include<fstream>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,q;
vi o;
pii range[222222];
int p[22][222222];
vi v[222222];
int d[222222];

void dfs(int ver,int par=-1,int dp=0){
	d[ver]=dp;
	p[0][ver]=par;
	range[ver].first=o.size();
	REP(i,v[ver].size()){
		if(v[ver][i]!=par){
			dfs(v[ver][i],ver,dp+1);
		}
	}
	o.pb(ver);
	range[ver].second=o.size()-1;
}

set<pii> used;

struct Node{
	Node(){
		l=r=0;
		lf=rg=0;
		add=0;
	}
	int add;
	int l,r;
	int res;
	Node* lf;
	Node* rg;
};

void addVal(Node* curr,int l,int r,int val){
	if(l>r)return;
	if(r<curr->l || l>curr->r) return;
	if(l<=curr->l && curr->r<=r){
		curr->add+=val;
		if(curr->add==0){
			if(curr->l==curr->r)curr->res=1;
			else curr->res=curr->lf->res+curr->rg->res;
		}else curr->res=0;
		return;
	}
	addVal(curr->lf,l,r,val);
	addVal(curr->rg,l,r,val);

	if(curr->add) curr->res=0;
	else curr->res=curr->lf->res+curr->rg->res;
}


Node* buildTree(int l,int r){
	Node* curr = new Node();
	curr->l=l;
	curr->r=r;
	if(l!=r){
		curr->lf=buildTree(l,(l+r)/2);
		curr->rg=buildTree((l+r)/2+1,r);
	}
	curr->res=r-l+1;
	return curr;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif


	cin>>n>>q;
	CL(p,-1);
	Node* root = buildTree(0,n-1);
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0);
	FOR(i,1,20)REP(j,n)if(p[i-1][j]!=-1)p[i][j]=p[i-1][p[i-1][j]];
	int sm=0;
	REP(i,q){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		if(d[x]<d[y] || d[x]==d[y] && x<y)swap(x,y);
		
		int type = 0;
		if(used.count(pii(x,y))){
			type=1;
			used.erase(pii(x,y));
		}else used.insert(pii(x,y));

		vector<pii> prg;
		if(range[y].first<=range[x].first && range[x].second<=range[y].second){
			int ty = x;
			for(int j=19;j>=0;j--)if(d[ty]-(1<<j)>d[y]){
				ty=p[j][ty];
			}
			prg.pb(pii(range[ty].first,range[x].first-1));
			prg.pb(pii(range[x].second+1,range[ty].second));
		}else{
			if(range[x].first>range[y].first)swap(x,y);
			prg.pb(pii(0,range[x].first-1));
			prg.pb(pii(range[x].second+1,range[y].first-1));
			prg.pb(pii(range[y].second+1,n-1));
		}
		REP(j,prg.size()) addVal(root,prg[j].first,prg[j].second,type==1?1:-1);
		printf("%d\n",root->res);
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}