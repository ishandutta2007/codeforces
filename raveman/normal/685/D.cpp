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
#define R(i,n)			REP(i,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n,k;
int x[111111];
int y[111111];

ll  r[111111];

typedef pair<pii,int> p3;

multiset<int> s;

void solve(ll mult){
	vi v1,v2;
	for(multiset<int>::iterator it = s.begin();it!=s.end();++it)v1.pb(*it),v2.pb((*it)+k);//,cout<<*it<<' ';;
	//puts("");

	vector<pii> m;
	int i1=0,i2=0;
	while(i1<v1.size() || i2<v2.size()){
		if(i1<v1.size() && (i2>=v2.size() || v1[i1]<v2[i2])) m.pb(pii(v1[i1],0)),i1++;
		else m.pb(pii(v2[i2],1)),i2++;
	}


	int cnt = 0;
	for(int i=0;i<m.size();){
		int j = i;
		while(j<m.size() && m[j].first==m[i].first){
			if(m[j].second==0) cnt++;
			else cnt--;
			j++;
		}
		if (j<m.size()){
			r[cnt] += mult * (m[j].first-m[i].first);
		}
		i=j;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)scanf("%d %d",x+i,y+i);

	vector<p3> e;
	REP(i,n) e.pb(make_pair(pii(x[i]-k+1,0),i));
	REP(i,n) e.pb(make_pair(pii(x[i]+1,1),i));
	SORT(e);

	for(int i = 0; i < e.size();){
		int j = i;
		while(j<e.size() && e[j].first.first == e[i].first.first){
			if (e[j].first.second==0) s.insert(y[e[j].second]);//,cout<<"add "<<y[e[j].second]<<endl;
			else s.erase(s.find(y[e[j].second]));//,cout<<"remove "<<y[e[j].second]<<endl;
			++j;
		}

		if (j < e.size()) {
			ll diff = e[j].first.first - e[i].first.first;
			solve(diff);
		}

		i = j;
	}

	FOR(i,1,n+1){
		if(i>1)printf(" ");
		printf("%I64d",r[i]);
	}
	puts("");
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}