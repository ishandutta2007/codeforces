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
int a[111111];
vector< pair<int, ll> > v;

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) scanf("%d",&a[i]),v.pb(make_pair(i,a[i]));
	reverse(v.begin(),v.end());

	int m;
	cin>>m;
	REP(i,m){
		int w,h;
		scanf("%d %d",&w,&h);

		ll mx = 0;
		while(v.size()){
			if(v.back().first >= w) break;
			mx = v.back().second;
			v.pop_back();
		}
		cout<<mx<<endl;
		while(v.size() && v.back().second<=mx+h) v.pop_back();
		v.pb(make_pair(0,mx+h));
	}

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}