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

short xxx[1<<26];
char s[1111111];
int m,n;
char w[33];
int res[11111];
int mask[11111];

struct Res{
	vector<pii> beg;
	vector<pii> end;
	int all;
	int from;
	int to;
};

Res solve(int l, int r){
	Res rr;
	rr.from = l;
	rr.to = r;
	if(r==l){
		rr.all = 1<<(s[l]-'a');
	}else{
		int end = (l+r)/2;
		Res t1 = solve(l, end);
		Res t2 = solve(end+1,r);

		rr.all = t1.all | t2.all;

		rr.beg = t1.beg;
		rr.beg.pb(pii(t1.all, end));

		REP(i,t2.beg.size()){
			int nmask = t2.beg[i].first | t1.all;

			if(nmask != rr.all){
				if(rr.beg.back().first!=nmask)
					rr.beg.pb(pii(nmask,t2.beg[i].second));
				else rr.beg.back().second = t2.beg[i].second;
			}
		}
		while(rr.beg.size() && rr.beg.back().first == rr.all) rr.beg.pop_back();

		rr.end = t2.end;
		rr.end.pb(pii(t2.all, end+1));
		REP(i,t1.end.size()){//for(int i = int(t1.end.size()) -1 ;i>=0;i--){
			int nmask = t1.end[i].first | t2.all;

			if(nmask != rr.all){
				if(rr.end.back().first!=nmask)
					rr.end.pb(pii(nmask,t1.end[i].second));
				else rr.end.back().second = t1.end[i].second;
			}
		}
		while(rr.end.size() && rr.end.back().first == rr.all) rr.end.pop_back();

		vi v;
		REP(i,t1.end.size()+1) REP(j,t2.beg.size()+1){
			int nmask = (i==t1.end.size() ? 0 : t1.end[i].first) | (t2.beg.size()==j ? 0 : t2.beg[j].first);
			if(nmask!=rr.all && (nmask&t1.all)!=t1.all  && (nmask&t2.all) != t2.all){
				v.pb(nmask);
			}
		}
		UN(v);
		REP(i,v.size()) res[xxx[v[i]]]++;
	}
	int mask = 1<<(s[l]-'a');
	REP(i,rr.beg.size()){
		if(rr.beg[i].first!=mask) while(1);
		mask |= (1<<(s[rr.beg[i].second+1]-'a'));
	}
	while(mask!=rr.all);

	mask = 1<<(s[r]-'a');
	REP(i,rr.end.size()){
		//if(rr.end[i].first!=mask) while(1);
		mask |= (1<<(s[rr.end[i].second-1]-'a'));
	}
	while(mask!=rr.all);
	return rr;	
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	scanf(" %s",s);
	//n=1000000;	
	n = strlen(s);
	//REP(i,n) s[i]=char('A'+rand()%13);
	cin>>m;
	//m=10000;
	REP(i,m){
		scanf(" %s",w);
		int tt = strlen(w);
		int mm = 0;
		REP(j,tt) mm |= (1<<(w[j]-'a'));
		//mm = rand()%(1<<26)+ 1;
		mask[i] = mm;
		xxx[mm] = i + 1;
	}

	Res t = solve(0,n-1);
	res[xxx[t.all]]++;
	REP(i,t.beg.size()) res[xxx[t.beg[i].first]]++;
	REP(i,t.end.size()) res[xxx[t.end[i].first]]++;	
	REP(i,m) printf("%d\n",res[xxx[mask[i]]]);	
	
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",double(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}