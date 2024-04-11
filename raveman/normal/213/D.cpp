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

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

vector<pdd> p;
vector<int> stars[111];
int n;

typedef complex<double> V;
const double pi = acos(-1.);

void buildStar(int p1,int p2, int star){
	if(star==n) return;
	stars[star].pb(p1);
	stars[star].pb(p2);

	V v(p[p2].first - p[p1].first, p[p2].second - p[p1].second);
	pdd last = p[p2];
	REP(i,3){
		v *= polar(1., pi - pi * 3 / 5 );
		pdd next(last.first + v.real(), last.second + v.imag());
		p.pb(next);
		stars[star].pb(p.size()-1);
		last = next;
	}

	if(star%2==0)
		buildStar(stars[star][3],stars[star][2],star+1);
	else buildStar(stars[star][4], stars[star][3], star+1);
}

vi res;

void buildPath(int star){
	if(star==n) return;
	if(star%2==0){
		res.pb(stars[star][3]);
		res.pb(stars[star][1]);
		res.pb(stars[star][4]);
		res.pb(stars[star][2]);
		buildPath(star+1);
		res.pb(stars[star][0]);
	}else{
		res.pb(stars[star][3]);
		res.pb(stars[star][0]);
		res.pb(stars[star][2]);
		res.pb(stars[star][4]);
		buildPath(star+1);
		res.pb(stars[star][1]);
	}
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;

	p.pb(pdd(0,0));
	p.pb(pdd(10,0));

	buildStar(0, 1, 0);

	cout<<p.size()<<endl;
	REP(i,p.size())
		printf("%.15lf %.15lf\n",p[i].first,p[i].second);

	REP(i,n){
		REP(j,5){
			if(j) printf(" ");
			printf("%d",stars[i][j]+1);
		}
		puts("");
	}
	res.pb(0);
	buildPath(0);
	REP(i,res.size()){
		if(i) printf(" ");
		printf("%d",res[i]+1);
	}

	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}