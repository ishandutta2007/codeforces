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
int t[222222];
int x[222222];
int l[222222];
int r[222222];

vector<pii> mlta[222222];

vi  v[222222];

const int mod = 998244353;

struct Node{
	Node(){
		l=r=0;
		lf=rg=0;
		sum=0;
		add=0;
		mlt=1;
	}
	int l,r;
	Node* lf;
	Node* rg;

	int sum;
	int add;
	int mlt;
};

Node* root;
Node* buildTree(int from,int to){
	Node* curr = new Node();
	curr->l = from;
	curr->r = to;
	if(from!=to){
		curr->lf = buildTree(from,(from+to)/2);
		curr->rg = buildTree((from+to)/2+1,to);
	}
	return curr;
}

void add(int& x,int v){
	x+=v;
	if(x>=mod)x-=mod;
	if(x<0)x+=mod;
}
void mlt(int& x,int v){
	x=(ll(x)*v)%mod;
}

void update(Node* curr){
	if(curr->l == curr->r){
		if(curr->mlt!=1){
			mlt(curr->sum, curr->mlt);
			curr->mlt=1;
		}
		if(curr->add){
			add(curr->sum, curr->add);
			curr->add=0;
		}
	}else{
		curr->sum = curr->lf->sum;
		add(curr->sum, curr->rg->sum);
		mlt(curr->sum, curr->mlt);
		add(curr->sum, curr->add*ll(curr->r-curr->l+1)%mod);
	}
}

void push(Node* curr){
	if(!(curr->l == curr->r)){
		if(curr->mlt!=1){
			mlt(curr->lf->mlt, curr->mlt);
			mlt(curr->rg->mlt, curr->mlt);
			mlt(curr->lf->add, curr->mlt);
			mlt(curr->rg->add, curr->mlt);
			curr->mlt = 1;
		}
		if(curr->add){
			add(curr->lf->add , curr->add);
			add(curr->rg->add , curr->add);
			curr->add=0;
		}
		update(curr->lf);
		update(curr->rg);
		curr->sum = curr->lf->sum;
		add(curr->sum, curr->rg->sum);
	}
	update(curr);
}


void addOne(Node* curr, int l, int r,int v){
	if(curr->r < l || curr->l > r) return;
	push(curr);
	if (l <= curr->l && curr->r <= r){
		add(curr->add,v);
	}else{
		addOne(curr->lf, l, r, v);
		addOne(curr->rg, l, r, v);
	}
	update(curr);
}

void multiply(Node* curr,int l,int r){
	if(curr->r<l || curr->l>r) return;
	push(curr);
	if(l<=curr->l && curr->r <= r){
		mlt(curr->mlt, 2);
		mlt(curr->add, 2);
	}else{
		multiply(curr->lf,l,r);
		multiply(curr->rg,l,r);
	}
	update(curr);
}

int getSum(Node* curr, int l,int r){
	if(curr->r<l || curr->l> r) return 0;
	//push(curr);
	update(curr);
	if(l<=curr->l && curr->r <= r) {
		return curr->sum;
	}
	push(curr);
	int rr = getSum(curr->lf, l, r);
	add(rr,getSum(curr->rg,l,r));
	return rr;
}

set<int> sts[2222];
int      sta[2222];
void stupid1(int l,int r,int v){
	FOR(i,l,r+1){
		if(sts[i].count(v)) sta[i]*=2,sta[i]%=mod;
		else sts[i].insert(v),sta[i]=(sta[i]+1)%mod;
	}
}
int stupid2(int l,int r){
	int res=0;
	FOR(i,l,r+1)res=(res+sta[i])%mod;
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	//int it = 0;
//start:
	//REP(i,1111)v[i].clear(),mlta[i].clear(),sts[i].clear(),sta[i]=0;

	cin>>n>>q;REP(i,q){scanf("%d %d %d",t+i,l+i,r+i);if(t[i]==1)scanf("%d",x+i);}
	//n=100;q=1000;	REP(i,q){		t[i]=rand()%2+1;		l[i]=rand()%n+1	;	r[i]=rand()%n+1;if(l[i]>r[i])swap(l[i],r[i]);x[i]=rand()%5+1;}
	//it++;cout<<it<<" "<<"start " << n<< ' '<<q<<endl;if(it==1586){REP(i,q){cout<<t[i]<<' '<<l[i]<<' '<<r[i];if(t[i]==1) cout<<" "<<x[i];puts("");}}

	REP(i,q){
		l[i]--,r[i]--;
		if(t[i]==1){
			v[x[i]].pb(i);
		}
	}
	root=buildTree(0,n-1);

	FOR(i,1,n+1){
		set<pii> ss;
		REP(j,v[i].size()){
			int from = l[v[i][j]];
			int to = r[v[i][j]];

			vector<pii> p;
			while(1){
				set<pii>::iterator it = ss.lower_bound(pii(to+1,0));
				if(it==ss.begin()) break;
				it--;
				if(it->second < from || it->first > to) break;
				p.pb(*it);
				ss.erase(it);
			}

			REP(k,p.size()){
				int ff = max(from,p[k].first);
				int tt = min(to,p[k].second);
				if(ff<=tt)mlta[v[i][j]].pb(pii(ff,tt));
			}

			REP(k,p.size()){
				from = min(from,p[k].first);
				to = max(to,p[k].second);
			}
			ss.insert(pii(from,to));
		}
	}

	REP(i,q){
		//cout<<"pr "<<i<<" "<<getSum(root,0,0)<<endl;
		//REP(ii,n)getSum(root,ii,ii);
		if(t[i]==1){
			//stupid1(l[i],r[i],x[i]);
			addOne(root,l[i],r[i],1);
			REP(j,mlta[i].size()){
				addOne(root,mlta[i][j].first,mlta[i][j].second,-1);
				multiply(root,mlta[i][j].first,mlta[i][j].second);
			}
		}else{
			//if(getSum(root,l[i],r[i])!=stupid2(l[i],r[i])) {cout<<getSum(root,l[i],r[i])<<" "<<stupid2(l[i],r[i])<<endl;puts("FUCK");return 0;}
			//else puts("OK");
			cout<<getSum(root,l[i],r[i])<<"\n";
		}
	}
	//puts("SUCCESS");
	//return 0;
	//goto start;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}