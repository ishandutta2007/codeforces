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

struct Node{
	int l,r;
	Node* lf;
	Node* rg;
	ll sum;
	int mx;
	Node(){
		lf=rg=0;
		l=r=sum=mx=0;
	}
};

Node* root;

int n,m;
int a[111111];

Node* buildTree(int l, int r){
	Node* curr = new Node();
	curr->l = l;
	curr->r = r;
	if(l==r){
		curr->mx = curr->sum = a[l];
	}else{
		curr->lf = buildTree(l,(l+r)/2);
		curr->rg = buildTree((l+r)/2+1,r);
		curr->sum = curr->lf->sum + curr->rg->sum;
		curr->mx = max(curr->lf->mx, curr->rg->mx);
	}
	return curr;
}

ll getSum(Node* curr,int l,int r){
	if(curr->r < l) return 0;
	if(curr->l > r) return 0;
	if(l<=curr->l && curr->r<=r) return curr->sum;
	return getSum(curr->lf,l,r)+getSum(curr->rg,l,r);
}

void doMod(Node* curr,int l,int r,int mod){
	if(curr->r < l) return;
	if(curr->l > r) return;
	if(curr->mx < mod) return;
	if(curr->lf==0){
		curr->sum %= mod;
		curr->mx = curr->sum;
		return;
	}
	doMod(curr->lf,l,r,mod);
	doMod(curr->rg,l,r,mod);
	curr->sum = curr->lf->sum+curr->rg->sum;
	curr->mx= max(curr->lf->mx,curr->rg->mx);
}

void setVal(Node *curr,int l,int x){
	if(curr->r < l) return;
	if(curr->l > l) return;
	if(curr->lf==0){
		curr->mx=curr->sum = x;
		return;
	}
	setVal(curr->lf,l,x);
	setVal(curr->rg,l,x);
	curr->sum = curr->lf->sum+curr->rg->sum;
	curr->mx= max(curr->lf->mx,curr->rg->mx);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)scanf("%d",a+i);
	root = buildTree(0,n-1);
	int t,l,r,x;
	REP(i,m){
		scanf("%d",&t);
		if(t==1){
			scanf("%d %d",&l,&r);
			l--,r--;
			cout<<getSum(root,l,r)<<"\n";
		}
		if(t==2){
			scanf("%d %d %d",&l,&r,&x);
			l--,r--;
			doMod(root,l,r,x);
		}
		if(t==3){
			scanf("%d %d",&l,&x);
			l--;
			setVal(root,l,x);
		}
	}
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}