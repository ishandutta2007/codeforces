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

int n,q;
int a[111111];

typedef pair<pii, double> pid;

set<int> active;

struct Distribution{
	map<int,double> m;
	void add(double p){
		vector<int> v1;
		vector<double> v2;
		for(map<int,double>::iterator it = m.begin();it!=m.end();it++){
			v1.pb(it->first+1);
			v2.pb(it->second*p);
			it->second *= (1-p);
		}
		REP(i,v1.size()){
			m[v1[i]]+=v2[i];
		}
		cleanup();
	}
	void join(Distribution& other){
		if(other.m.size()>m.size()){
			swap(other.m,m);
		}

		map<int,double>::iterator it1,it2;
		
		it1 = m.begin();
		double sum = 0;
		vi v1;
		vector<double> v2;
		for(it2 = other.m.begin();it2!=other.m.end();it2++){
			while(it1!=m.end() && it2->first > it1->first){
				sum += it1->second;
				++it1;
			}
			v1.pb(it2->first);
			v2.pb(it2->second * sum);
		}
		

		it2 = other.m.begin();
		sum = 0;
		for(it1 = m.begin();it1!=m.end();it1++){
			while(it2!=other.m.end() && it1->first > it2->first){
				sum += it2->second;
				++it2;
			}
			it1->second *= (sum+((it2!=other.m.end() && it1->first == it2->first)?it2->second:0));
		}

		REP(i,v1.size()) m[v1[i]]+=v2[i];
		
		cleanup();
	}
	void cleanup(){
		vi v;
		for(map<int,double>::iterator it = m.begin();it!=m.end();it++){
			if(it->second < 1e-10) v.pb(it->first);
		}
		REP(i,v.size()) m.erase(v[i]);
	}
};

Distribution d[111111];

bool TEST=0;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	if(TEST){
		n=100000;
		q=5000;
	}else{
		cin>>n>>q;
	}
	REP(i,n){
		if(TEST){
			a[i]=1;
			if(i==0) a[i]=100000;
		}else{
			scanf("%d",a+i);
		}
		active.insert(i);
		d[i].m[a[i]]=1;
	}
	vector<pid> v(q);
	REP(i,q){
		if(TEST){
			v[i].first.first=1;
			v[i].first.second=1;
			v[i].second=0.5;
		}else{
			scanf("%d %d %lf",&v[i].first.first,&v[i].first.second,&v[i].second);
		}
		v[i].first.first--,v[i].first.second--,v[i].first.first*=(-1);
	}
	v.pb(pid(pii(0,n-1),0));
	sort(v.begin(),v.end());
	REP(i,v.size()){
		int from = -v[i].first.first;
		int to = v[i].first.second;
		set<int>::iterator it = active.lower_bound(from+1);
		while(it!=active.end() && *it <= to){
			d[from].join(d[*it]);
			active.erase(it);
			it=active.lower_bound(from+1);
		}
		d[from].add(v[i].second);
	}

	double res = 0;
	for(map<int,double>::iterator it = d[0].m.begin();it!=d[0].m.end();it++){
		res+=it->first*it->second;
	}
	printf("%.10lf\n",res);


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}