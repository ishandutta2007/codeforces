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

int k,n,m;
int a[111111];
int t[111111];
int w[111111];
int b[111111];
bool u[111111];

pii v[111111];

struct A{
	int index;
	ll val;
	ll base;
	bool operator<(const A&s)const{
		return val * s.base > s.val * base;
	}
};

vector<A> ad[111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>k>>n>>m;
	REP(i,k)scanf("%d",a+i);
	REP(i,n)scanf("%d %d %d",t+i,w+i,b+i),w[i]--;

	REP(i,n)if(t[i]==1){
		if(v[w[i]].first<b[i]){
			v[w[i]]=pii(b[i],i);
		}
	}

	REP(i,k)if(v[i].first>0){
		A op;
		op.index=v[i].second;
		op.val=v[i].first-a[i];
		op.base=1;
		if(op.val>0){
			ad[i].pb(op);
		}
	}

	REP(i,n)if(t[i]==2){
		A op;
		op.index = i;
		op.val = b[i];
		op.base = 1;
		ad[w[i]].pb(op);
	}

	vector<A> add;
	REP(i,k){
		SORT(ad[i]);
		for(int j=0;j<ad[i].size();j++){
			ad[i][j].base = a[i];
			if(j){
				ad[i][j].base = ad[i][j-1].base + ad[i][j-1].val;
			}
			add.pb(ad[i][j]);
		}
	}
	
	REP(i,n)if(t[i]==3){
		A t;
		t.index=i;
		t.val=b[i]-1;
		t.base=1;
		add.pb(t);
	}
	SORT(add);
	int num = add.size();
	if(num>m) num = m;
	cout<<num<<endl;
	REP(i,num)u[add[i].index]=true;
	REP(tp,4)REP(i,n)if(t[i]==tp && u[i]){
		printf("%d ",i+1);
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}