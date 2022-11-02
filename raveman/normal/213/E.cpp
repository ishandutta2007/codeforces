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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back


ll st[222222];
int n,m;
int a[222222];
int b[222222];
int w[222222];

struct Node{
	int l,r;
	Node *lf;
	Node *rg;
	ll hash;
	int num;
	Node(){lf=rg=0;hash=num=0;}
};

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

void insert(Node *curr, int pos, int val,int sgn=1){
	if(pos<curr->l || pos>curr->r) return;
	curr->num += sgn;
	if(curr->l == curr->r){
		curr->hash = (sgn == 1 ? val : 0);
	}else{
		insert(curr->lf, pos, val,sgn);
		insert(curr->rg, pos, val,sgn);
		curr->hash = curr->lf->hash + curr->rg->hash * st[curr->lf->num];
	}
}


int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	st[0] = 1;
	FOR(i,1,222222) st[i] = st[i-1] * 1000003;
	cin>>n>>m;
	ll sum = 0;
	REP(i,n) sum += st[i];
	REP(i,n) scanf("%d",a+i);

	REP(j,m) scanf("%d",b+j);
	REP(j,m) w[b[j]]=j;

	Node *root1 = buildTree(0,200000);
	Node *root2 = buildTree(0,200000);
	REP(i,n) insert(root1, i, a[i]);
	

	REP(i,m) if(b[i]>=1 && b[i]<=n)
		insert(root2,i,b[i]);
	ll hash = root1->hash;
	int res = 0;
	REP(diff,m-n+1){
		if(hash == root2->hash) res ++;
		hash += sum;
		if(diff!=m-n){
			insert(root2,w[diff+1],diff+1,-1);
			insert(root2,w[diff+n+1],diff+1+n);
		}
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}