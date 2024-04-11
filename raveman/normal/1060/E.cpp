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

int n;
vi v[222222];

struct R{
	R(){
		sum=sp=sn=cntp=cntn=0;
	}
	ll sp;
	ll sn;
	ll cntp;
	ll cntn;
	ll sum;

	void out(){
	//	cout<<sp<<' '<<sn<<' '<<cntp<<' '<<cntn<<' '<<sum<<endl;
	}
};

R join(R t1, R t2){
	R res;
	res.sum = t1.sum + t2.sum;
	// p p 
	res.sum += (t1.sp * t2.cntp + t2.sp * t1.cntp);
	// n n 
	res.sum += (t1.sn * t2.cntn + t2.sn * t1.cntn) + t1.cntn * t2.cntn;
	// p n
	res.sum += (t1.sp * t2.cntn + t2.sn * t1.cntp) + t1.cntp * t2.cntn;
	// n p
	res.sum += (t1.sn * t2.cntp + t2.sp * t1.cntn) + t1.cntn * t2.cntp;

	res.cntn = t1.cntn + t2.cntn;
	res.cntp = t1.cntp + t2.cntp;
	res.sn = t1.sn + t2.sn;
	res.sp = t1.sp + t2.sp;
	return res;
}

R solve(int ver,int par=-1){
	R tmp;
	tmp.cntp = 1;

	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		R t = solve(v[ver][i],ver);

		swap(t.cntn,t.cntp);
		swap(t.sn,t.sp);
		//t.sn += t.cntn;
		t.sp += t.cntp;

		tmp.out();t.out();
		
		tmp = join(tmp,t);

		//cout<<"c s: "<<tmp.sum<<endl;
	}
	return tmp;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	cout<<solve(0).sum<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}