#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

struct R{
	double s;
	int c;
	int len;

	bool operator<(const R& s)const{
		return len *ll(s.c)<s.len*ll(c);
	}
};

int n;
vector<pii> v[111111];

R solve(int ver,int par=-1){
	R res;
	
	res.c=1;
	res.len=0;
	res.s=0;

	vector<R> q;
	REP(i,v[ver].size()) if(v[ver][i].first != par){
		q.pb(solve(v[ver][i].first, ver));
		q.back().s += v[ver][i].second * q.back().c;
		q.back().len += 2 * v[ver][i].second;
	}
	sort(q.begin(),q.end());

	REP(i,q.size()){
		if(i==0){ res = q[i]; res.c++;}
		else{
			res.s += q[i].s;
			res.s += double(q[i].c) * res.len;
			
			res.c+=q[i].c;
			res.len += q[i].len;
		}
	}

	return res;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x,y,z;
		scanf("%d %d %d",&x,&y,&z);
		x--,y--;
		v[x].pb(pii(y,z));
		v[y].pb(pii(x,z));
	}

	R res = solve(0);
	printf("%.10lf\n",res.s / (n-1));

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}