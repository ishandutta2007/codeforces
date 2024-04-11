//#pragma comment(linker, "/STACK:60777216")  

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
typedef pair<ll,ll> pl;
typedef pair<int,pl>	p3l;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int a[6];
int b[111111];
int n;

int p;
int c[111111];
map<int,int> m;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	REP(i,6)cin>>a[i];
	cin>>n;
	REP(i,n)scanf("%d",b+i);

	vector<p3> v;
	REP(i,6)REP(j,n)v.pb(p3(b[j]-a[i],pii(j,i)));
	SORT(v);
	CL(c,-1);
	int res = 2e9+10;
	for(int i=v.size()-1;i>=0;i--){
		int note = v[i].second.first;
		int string = v[i].second.second;
		if(c[note]==-1){
			p++;
		}else{
			m[c[note]]--;
			if(m[c[note]]==0)m.erase(c[note]);
		}
		c[note]=v[i].first;
		m[c[note]]++;

		if(p==n){
			res=min(res,m.rbegin()->first-v[i].first);
		}
	}
	//cout<<p<<' '<<n<<endl;
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}