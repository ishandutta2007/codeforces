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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int t[111111];
int s[111111];

struct Node {
	Node() {
		from=to=0;
		lf=rg=0;
		mv=mx=sum=0;
	}
	int from,to;
	Node *lf;
	Node* rg;
	int sum;
	int mv;
	int mx;

	void add(int b,int e,int v){
		if(b>to || e<from)return;
		if(b<=from && to<=e){
			sum+=v;
			return;
		}
		lf->add(b,e,v);
		rg->add(b,e,v);
		mv=min(lf->mv+lf->sum,rg->mv+rg->sum);
		mx=max(lf->mx+lf->sum,rg->mx+rg->sum);
		//cout<<from<<' '<<to<<" = "<<mv+sum<<" "<<mx+sum<<endl;
	}

	int solve(int need=1){
		//cout<<"! "<<mv+sum<<' '<<mx+sum<<endl;
		if(mv+sum>need || mx+sum<need)return -1;
		if(from==to)return from;
		int p = rg->solve(need-sum);
		if(p!=-1)return p;
		return lf->solve(need-sum);
	}
};

Node* buildTree(int from,int to){
	Node* c = new Node();
	c->from=from;
	c->to=to;
	if(from!=to){
		c->lf = buildTree(from,(from+to)/2);
		c->rg = buildTree((from+to)/2+1,to);
	}
	return c;
}

map<int,int> w;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	Node* root = buildTree(0,n-1);
	REP(i,n){
		int p,t;
		scanf("%d %d",&p,&t);
		p--;
		if(t==0){
			root->add(0,p,-1);
		}else{
			int x;
			scanf("%d",&x);
			w[p]=x;
			root->add(0,p,1);
		}
		int pos = root->solve();
		if(pos==-1)puts("-1");
		else{
			map<int,int>::iterator it= w.lower_bound(pos+1);
			it--;
			printf("%d\n",it->second);
		}
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}