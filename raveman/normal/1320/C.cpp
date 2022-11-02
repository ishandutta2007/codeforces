#pragma comment(linker, "/STACK:60777216")  

#include <cassert>
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<complex>
#include<vector>
#include<cstring>
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
typedef pair<int,pii>	p3;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,m,p;
int a[222222];
int ca[222222];
int b[222222];
int cb[222222];
int x[222222];
int y[222222];
int z[222222];


struct Node{
	Node(){
		l=r=0;
		lf=rg=0;
		mx=0;
		add=0;
	}
	int l,r;
	Node* lf;
	Node* rg;
	ll mx;
	ll add;

	void addval(int from,int to,ll val){
		//cout<<"addval "<<from<<' '<<to<<' '<<val<<"  =  "<<l<<' '<<r<<' '<<add<<' '<<mx<<endl;
		if(from>r || to<l)return;
		if(from<=l && r<=to){
			add+=val;
			mx+=val;
			return;
		}
		lf->addval(from,to,val);
		rg->addval(from,to,val);
		mx=max(lf->mx,rg->mx)+add;
		//cout<<"addval "<<from<<' '<<to<<' '<<val<<"  =  "<<l<<' '<<r<<' '<<add<<' '<<mx<<endl;
	}
};

Node* buildtree(int l,int r){
	Node* node = new Node();
	node->l = l;
	node->r = r;
	if(l!=r){
		node->lf = buildtree(l,(l+r)/2);
		node->rg = buildtree((l+r)/2+1,r);
	}
	return node;
}

const bool cmp2(const p3& p1, const p3& p2){
	return p1.second.first<p2.second.first;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>p;
	REP(i,n)scanf("%d %d",a+i,ca+i);
	REP(i,m)scanf("%d %d",b+i,cb+i);
	REP(i,p)scanf("%d %d %d",x+i,y+i,z+i);

	vector<pii> attack;
	REP(i,n)attack.pb(pii(a[i],ca[i]));
	SORT(attack);

	vector<pii> def;
	REP(i,m)def.pb(pii(b[i],cb[i]));
	SORT(def);

	vector<pii> deftmp;
	REP(i,m){
		if(!deftmp.empty() && deftmp.back().first==def[i].first)continue;
		deftmp.pb(def[i]);
	}
	def=deftmp;
	//REP(i,def.size())cost[i]=-def[i].second;
	Node* root = buildtree(0,def.size()-1);
	REP(i,def.size()) root->addval(i,i,-def[i].second);

	vector<p3> d;
	REP(i,p)d.pb(p3(x[i],pii(y[i],z[i])));
	SORT(d);

	int t1=1e9;
	int t2=1e9;
	REP(i,n)t1=min(t1,ca[i]);
	REP(i,m)t2=min(t2,cb[i]);
	ll best = -t1-t2;
	int az=0;
	for(int i=0;i<d.size() && az<attack.size();){
		//cout<<i<<' '<<d.size()<<' '<<d[0].first<<' '<<attack[az].first<<' '<<az<<endl;
		int j=i;
		while(j<d.size() && d[j].first<attack[az].first)++j;
		sort(d.begin()+i,d.begin()+j,cmp2);

		FOR(w,i,j){
			int pos = lower_bound(def.begin(),def.end(),pii(d[w].second.first+1,0))-def.begin();
			//cout<<pos<<' '<<cost[pos]<<' '<<attack[az].second<<' '<<d[w].second.second<<endl;
			if(pos<def.size()){
				root->addval(pos,def.size()-1,d[w].second.second);
				//cost[pos] += d[w].second.second;
				//best=max(best,root->mx-attack[az].second);
			}
		}
		best=max(best,root->mx-attack[az].second);
		i=j;
		az++;
	}

	cout<<best<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}