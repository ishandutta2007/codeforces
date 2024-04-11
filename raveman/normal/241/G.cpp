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

vi s;
vector<double> r;
void relax(int i,int j,vi x){
	int t = s[j];
	r[i]=min(r[i],(x[i]-x[j])*double(x[i]-x[j])/4/r[t]);
}
double solve(int n,vi x,vi p){
	r.clear();s.clear();
	double sum = 0;
	REP(i,n){
		r.pb(p[i]);
		cout<<s.size()<<endl;
		for(int j=1;j<=min((int)s.size(),300);j++)
			relax(i,s.size()-j,x);

		while(!s.empty() &&	r[s.back()]<=r.back()) s.pop_back();
		s.pb(i);
		sum += r.back();
		//cout<<! "<<r.back()<<endl;
	}
	return sum;
}


int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cout<<"302"<<endl;
	cout<<"0 1000000"<<endl;
	int x = 50000;
	vi xx,pp;
	xx.pb(0);pp.pb(1000000);
	REP(i,300){
		cout<<x<<" "<<300-i<<endl;
		xx.pb(x);
		pp.pb(300-i);

		x += 600;
	}
	xx.pb(1000000);pp.pb(1000000);
	cout<<"1000000 1000000"<<endl;
	
	//printf("%.10lf\n",solve(302,xx,pp));

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}