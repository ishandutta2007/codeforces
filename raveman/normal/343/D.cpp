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

int n;
vi   v[500055];
bool u[500055];
int  b[500055];
int  e[500055];
int  c;
int  p[500055];

void dfs(int ver){
	u[ver]=true;
	p[c]=ver;
	b[ver]=c;
	++c;
	REP(i,v[ver].size())
		if(!u[v[ver][i]]){
			dfs(v[ver][i]);
		}
	e[ver]=c-1;
}

struct Node{
	int l,r;
	Node *lf;
	Node *rg;
	int mx1,mx2;
	Node(){l=r=0;lf=rg=0;mx1=mx2=0;}
};

Node* buildTree(int l,int r){
	Node* nd = new Node();
	nd->l = l;
	nd->r = r;
	if(l!=r){
		nd->lf = buildTree(l,(l+r)/2);
		nd->rg = buildTree((l+r)/2+1,r);
	}
	return nd;
}

Node* root;

void updateMax(Node *curr, int from, int to, int val){
	if(to<curr->l || from > curr->r) return;
	if(from<=curr->l && curr->r<=to){
		curr->mx1=val;
	}else{
		updateMax(curr->lf, from, to, val);
		updateMax(curr->rg, from, to, val);
	}
}
void updateMax2(Node *curr, int from, int val){
	if(from<curr->l || from>curr->r) return;
	curr->mx2 = val;
	if(curr->lf)updateMax2(curr->lf, from, val);
	if(curr->rg)updateMax2(curr->rg, from, val);
}
int getValue2(Node *curr, int from, int to){
	if(from<=curr->l && curr->r<=to) return curr->mx2;
	if(to<curr->l || from>curr->r) return 0;
	return max(getValue2(curr->lf, from, to), getValue2(curr->rg, from, to));
}
int getValue(Node *curr, int from){
	if(from<curr->l ||from>curr->r) return 0;
	int val = curr->mx1;
	if(curr->lf) val=max(val,getValue(curr->lf,from));
	if(curr->rg) val=max(val,getValue(curr->rg,from));
	return val;
}
	
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n;

	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		v[x-1].pb(y-1);
		v[y-1].pb(x-1);
	}
	dfs(0);
	int q,type,ver;
	cin>>q;
	root = buildTree(0,n-1);
	REP(i,q){
		scanf("%d %d",&type,&ver);
		ver--;
		if(type==1){
			updateMax(root,b[ver],e[ver],i+1);
		}else if(type==2){
			updateMax2(root,b[ver],i+1);
		}else if(type==3){
			int t1 = getValue(root,b[ver]);
			int t2 = getValue2(root,b[ver],e[ver]);
			printf("%c\n",(t1>t2?'1':'0'));
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}