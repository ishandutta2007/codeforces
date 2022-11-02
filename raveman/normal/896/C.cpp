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

int n,m;
ll seed,vmax;

int rnd() {
	ll tmp = seed;
    seed = (seed * 7 + 13) % 1000000007;
    return tmp;
}

typedef pair<pii,ll> p3;

vector<p3> a;

void addVal(int l, int r,int x){
	vector<p3> na;
	REP(i,a.size()){
		if(a[i].first.second<l || a[i].first.first>r) na.pb(a[i]);
		else if(a[i].first.first<=l && r<=a[i].first.second){
			if(a[i].first.first<=l-1)na.pb(p3(pii(a[i].first.first,l-1),a[i].second));
			na.pb(p3(pii(l,r),a[i].second+x));
			if(r+1<=a[i].first.second)na.pb(p3(pii(r+1,a[i].first.second),a[i].second));
		}else if(l<=a[i].first.first && a[i].first.second<=r){
			na.pb(a[i]);
			na.back().second+=x;
		}else if(a[i].first.first<l){
			if(a[i].first.first<=l-1)na.pb(p3(pii(a[i].first.first,l-1),a[i].second));
			na.pb(p3(pii(l,a[i].first.second),a[i].second+x));
		}else{
			na.pb(p3(pii(a[i].first.first,r),a[i].second+x));
			na.pb(p3(pii(r+1,a[i].first.second),a[i].second));
		}
	}
	a=na;
}
void setVal(int l, int r,int x){
	vector<p3> na;
	na.pb(p3(pii(l,r),x));
	REP(i,a.size()){
		if(a[i].first.second<l || a[i].first.first>r) na.pb(a[i]);
		else if(a[i].first.first<=l && r<=a[i].first.second){
			if(a[i].first.first<=l-1)na.pb(p3(pii(a[i].first.first,l-1),a[i].second));
			if(r+1<=a[i].first.second)na.pb(p3(pii(r+1,a[i].first.second),a[i].second));
		}else if(l<=a[i].first.first && a[i].first.second<=r){
		}else if(a[i].first.first<l){
			if(a[i].first.first<=l-1)na.pb(p3(pii(a[i].first.first,l-1),a[i].second));
		}else{
			na.pb(p3(pii(r+1,a[i].first.second),a[i].second));
		}
	}
	a=na;
}

ll findMed(int l,int r,int x){
	vector<pl> z;
	REP(i,a.size()){
		int num = 0;
		int m1=max(l,a[i].first.first);
		int m2=min(r,a[i].first.second);
		if(m1<=m2)num=m2-m1+1;
		if(num>0){
			z.pb(pl(a[i].second,num));
		}
	}
	SORT(z);
	x--;
	REP(i,z.size()){
		if(x<z[i].second)return z[i].first;
		x-=z[i].second;
	}
	return -1;
}

ll qp(ll c,ll st,int mod){
	ll r=1;
	while(st){
		if(st&1)r*=c,r%=mod;
		c*=c,c%=mod;
		st>>=1;
	}
	return r;
}
ll getSum(int l,int r,int x,int y){
	ll sum=0;
	REP(i,a.size()){
		int num = 0;
		int m1=max(l,a[i].first.first);
		int m2=min(r,a[i].first.second);
		if(m1<=m2)num=m2-m1+1;
		if(num>0){
			sum=(sum+qp(a[i].second%y,x,y)*num)%y;
		}
	}
	return sum;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>seed>>vmax;
	a.resize(n);
	
	REP(i,n)a[i]=p3(pii(i,i),rnd()%vmax+1);
	REP(i,m){
		int  op = (rnd() % 4) + 1;
		int l = (rnd() % n) + 1;
		int r = (rnd() % n) + 1;

	   if (l > r)swap(l, r);

	  int x,y;
	  if (op == 3) x = (rnd() % (r - l + 1)) + 1;
      else x = (rnd() % vmax) + 1;

	  if (op == 4) y = (rnd() % vmax) + 1;
	

	  if(op==1)addVal(l-1,r-1,x);
	  if(op==2)setVal(l-1,r-1,x);
	  if(op==3)cout<<findMed(l-1,r-1,x)<<"\n";
	  if(op==4)cout<<getSum(l-1,r-1,x,y)<<"\n";
	
	}




#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}