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
typedef pair<double,double>	pdd;
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
int p[222222];
int invp[222222];

struct NodeS{
	NodeS(){
		l=r=0;
		lf=rg=0;
		sum=0;
	}

	void add(int pos){
		if(pos<l || pos>r)return;
		sum++;
		if(l!=r){
			lf->add(pos);
			rg->add(pos);
		}
	}
	int getpos(int pos){
		if(l==r)return l;
		if(lf->sum>=pos)return lf->getpos(pos);
		return rg->getpos(pos-lf->sum);
	}
	int getSum(int from,int to){
		if(to<l || from>r) return 0;
		if(from<=l && r<=to) return sum;
		int sum=0;
		sum += lf->getSum(from,to);
		sum += rg->getSum(from,to);
		return sum;
	}
	int l,r;
	int sum;
	NodeS* lf;
	NodeS* rg;
};

struct NodeC{
	NodeC(){
		l=r=0;
		lf=rg=0;
		num=0;sum=0;
	}
	void addval(int pos){
		if(pos>r) return;
		if(pos<=l){
			num++;
			sum+=(l-pos);
			return;
		}
		lf->addval(pos);
		rg->addval(pos);
	}
	ll getval(int pos){
		if(l==r && l==pos)return sum;
		if(pos<l || pos>r) return 0;
		ll res = 0;
		res = sum + num * (pos-l);
		res += lf->getval(pos);
		res += rg->getval(pos);
		return res;
	}
	ll num;ll sum;
	int l,r;
	NodeC* lf;
	NodeC* rg;
};

NodeS* buildTreeS(int l,int r){
	NodeS* c = new NodeS();
	c->l=l;
	c->r=r;
	if(l!=r){
		c->lf=buildTreeS(l,(l+r)/2);
		c->rg=buildTreeS((l+r)/2+1,r);
	}
	return c;
}

NodeC* buildTreeC(int l,int r){
	NodeC* c = new NodeC();
	c->l=l;
	c->r=r;
	if(l!=r){
		c->lf=buildTreeC(l,(l+r)/2);
		c->rg=buildTreeC((l+r)/2+1,r);
	}
	return c;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",p+i),p[i]--,invp[p[i]]=i;

	NodeS* root1 = buildTreeS(0,n-1);
	NodeC* root2 = buildTreeC(0,n-1);
	NodeC* root3 = buildTreeC(0,n-1);

	ll invc=0;
	REP(i,n){
		//cout<<"start "<<i<<endl;

		int pos = invp[i];
		
		root2->addval(pos);
		root3->addval(n-1-pos);

		ll res = invc;
		
		int s1 = root1->getSum(0,pos-1);
		root1->add(pos);

		int midpos = root1->getpos(i/2+1);

		res += (i - s1);
		invc+=(i-s1);

		//cout<<"1: "<<res<<' '<<midpos<<endl;

		res += root2->getval(midpos);
		//cout<<"2: "<<res<<endl;

		res += root3->getval(n-1-midpos);
		//cout<<"3: "<<res<<endl;

		int w = i/2;
		res -= w * ll(w+1)/2;
		int w2 = i+1-(i/2+1);
		res -= w2 * ll(w2+1)/2;

		//cout<<"final: "<<res<<endl;
		cout<<res<<' ';
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}