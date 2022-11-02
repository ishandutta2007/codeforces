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
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,k;
vi v[222222];
ll res;

vi shift(vi z){
	vi r(k+1);
	REP(i,k){
		r[i]=z[(i-1+k)%k];
	}
	r[k]=z[k]+z[k-1];
	return r;
}

vi merge(vi v1,vi v2){
	vi r(k+1);
	ll s1=0,s2=0;
	REP(i,k)s1+=v1[i];
	REP(i,k)s2+=v2[i];
	REP(i1,k)REP(i2,k){
		res += ll(v1[i1])*v2[i2]*((i1+i2+k-1)/k);
	//	cout<<v1[i1]<<' '<<i1<<" : " <<v2[i2]<<' '<<i2<<" =  "<<res<<endl;
	}
	res += ll(v1[k])*s2+ll(v2[k])*s1;
	//cout<<v1[k] <<' '<<s2<<' '<<v2[k]<<' '<<s1<<endl;
	REP(i,k+1)r[i]=v1[i]+v2[i];
	return r;
}

vi solve(int ver,int par=-1){
	vi w(k+1);
	w[0]=1;
	REP(i,v[ver].size()){
		if(v[ver][i]==par)continue;
		vi t = solve(v[ver][i],ver);
		t=shift(t);
		//cout<<"process "<<ver<<' '<<v[ver][i]<<endl;
		w=merge(w,t);

		//REP(j,w.size())cout<<w[j]<<' ';cout<<" = "<<res<<endl;
	}
	return w;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n-1){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	solve(0);
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}