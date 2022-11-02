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

int a[555];
int n,k;
vector<vi> r;

vi yo[555];

bool solve(int d){
	REP(i,555)yo[i].clear();
	REP(i,n)yo[a[i]].pb(i);
	r.clear();
	REP(i,d){
		r.pb(vi());
		vector<pii> ad;
		for(int j=500;j>=0;j--){
			REP(w,yo[j].size()){
				r.back().pb(yo[j][w]);
				if(j-1>0)ad.pb(pii(j-1,yo[j][w]));

				swap(yo[j][w],yo[j].back());
				yo[j].pop_back();
				w--;
				if(r.back().size()==k) goto end;
			}
		}
		return 0;
end:
		REP(i,ad.size())yo[ad[i].first].pb(ad[i].second);
	}
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	bool DEBUG=0;

	int res=0;
	cin>>n>>k;
	for(int d=1;d<=500;d++){
		if(d*k<n)continue;
		if(((d*k)-n)%2)continue;
		REP(i,n)a[i]=1;
		int t = (d*k-n)/2;
		REP(i,t)a[i%n]+=2;
		if(solve(d)){
			REP(i,r.size()){
				if(!DEBUG){
					cout<<"?";
					REP(j,r[i].size())cout<<" "<<r[i][j]+1;
					cout<<endl;
					cout.flush();
				}else{
					cout<<d<<endl;
				}
				int xx;
				scanf("%d",&xx);
				res^=xx;
			}
			cout<<"! "<<res<<endl;
			#ifdef LocalHost
				printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
			#endif
			return 0;
		}
	}
	puts("-1");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}