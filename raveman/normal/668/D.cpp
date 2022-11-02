//#pragma comment(linker, "/STACK:60777216")  

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

int a[1111111];
int t[1111111];
int x[1111111];
int n;

vi  v[1111111];
vi  s[1111111];
int p[1111111];

void addValue(int x, int t,int val){
	vi& ss = s[x];
	t += p[x];
	while(t){
		ss[t] += val;
		t>>=1;
	}
}

int getSum(int x,int from,int to){
	int sum=0;
	vi& ss = s[x];
	from += p[x];
	to += p[x];
	while(from<=to){
		if(from&1) sum += ss[from];
		if(!(to&1)) sum += ss[to];
		from=(from+1)>>1;
		to=(to-1)>>1;
	}
	return sum;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	vi xx(n);
	REP(i,n)scanf("%d %d %d",a+i,t+i,x+i),xx[i]=x[i];
	UN(xx);

	REP(i,n)x[i]=lower_bound(xx.begin(),xx.end(),x[i])-xx.begin();

	REP(i,n)v[x[i]].pb(t[i]);

	REP(i,n)if(!v[i].empty()){
		UN(v[i]);
		p[i] = 1;
		while(p[i]<v[i].size())p[i]*=2;
		s[i].resize(2*p[i]);
	}


	REP(i,n){
		vi& t_ = v[x[i]]; 
		int tt = lower_bound(t_.begin(),t_.end(),t[i])-t_.begin();

		if(a[i]==1){
			addValue(x[i], tt, +1);
		}else if(a[i]==2){
			addValue(x[i], tt, -1);
		}else if(a[i]==3){
			printf("%d\n",getSum(x[i], 0, tt));
		}
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}