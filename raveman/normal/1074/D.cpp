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

unordered_map<int,int> c;

int  p[444444];
int  s[444444];

int getcode(int l){
	if(c.count(l)) return c[l];
	int sz = c.size();

	p[sz]=sz;
	s[sz]=0;
	
	return c[l]=sz;
}

pii getparent(int c){
	if(p[c]==c) return pii(c,0);

	pii t = getparent(p[c]);
	t.second ^= s[c];
	p[c] = t.first;
	s[c] = t.second;
	return t;
}

void addedge(int l,int r,int x){
	r++;
	int lc = getcode(l);
	int rc = getcode(r);
	pii zl = getparent(lc);
	lc=zl.first;
	x^=zl.second;
	pii zr = getparent(rc);
	rc=zr.first;
	x^=zr.second;
	p[lc]=rc;
	s[lc]=x;
}

int getsum(int l,int r){
	r++;
	int lc = getcode(l);
	int rc = getcode(r);
	pii zl = getparent(lc);
	pii zr = getparent(rc);
	if(zl.first!=zr.first) return -1;
	return zl.second^zr.second;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int q;
	cin>>q;
	int last=0;
	REP(i,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int l,r,x;
			scanf("%d %d %d",&l,&r,&x);
			l^=(last==-1?1:last);
			r^=(last==-1?1:last);
			x^=(last==-1?1:last);
			if(l>r)swap(l,r);

			int tmp = getsum(l,r);
			if(tmp!=-1) continue;
			addedge(l,r,x);
		}else{
			int l,r;
			scanf("%d %d",&l,&r);
			l^=(last==-1?1:last);
			r^=(last==-1?1:last);
			if(l>r)swap(l,r);

			last = getsum(l,r);
			printf("%d\n",last);
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}