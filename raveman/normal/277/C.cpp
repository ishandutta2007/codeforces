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

int n,m,k;

map< int , vector<pii> > v,h;

vi parse(map<int, vector<pii> > &mp, int n, int m,int tpp){
	int full = n - 1;
	vi sz;
	for(map<int, vector<pii> > ::iterator it = mp.begin();it!=mp.end();it++){
		int x = it->first;
		if(x>0 && x<n){
			full--;
			vector<pii> t = it->second;
			SORT(t);
			int c = 0;
			int to = 0;
			REP(i,t.size()){
				if(t[i].first>to) c+= t[i].first - to;
				to = max(to, t[i].second);
			}
			c+= m - to;
			sz.pb(c);
		}
	}
	if(full>2){
		int x= (full-2)/2;
		full-=x*2;
	}
	REP(i,full)sz.pb(m);
	return sz;
}

bool dohorstep(int len,int x,int n,int m){
	if(v.count(x)){
		vector<pii> t = v[x];
		SORT(t);
		int to = 0, c = 0;
		REP(i,t.size()){
			if(t[i].first>to)
				c+= t[i].first - to;
			to = max(to, t[i].second);
		}
		c+= m - to;

		int a = c - (c^len);
		if(a>0 && a<=c){
			to = 0, c = 0;
			REP(i,t.size()){
				if(t[i].first>to){
					c+= t[i].first - to;
					if(c>=a){
						cout<<x<<' '<<0<<' '<<x<<' '<<t[i].first-(c-a)<<endl;
						return 1;
					}
				}
				to = max(to, t[i].second);
			}
			c+= m - to;

			if(c>=a){
				cout<<x<<' '<<0<<' '<<x<<' '<<m-(c-a)<<endl;
				return 1;
			}
		}
	}else{
		int a = m-(m^len);
		if(a>0 && a<=m){
			cout<<x<<' '<<0<<' '<<x<<' '<<a<<endl;
			return 1;
		}
	}
	return 0;
}

bool doverstep(int len,int x,int n,int m){
	if(h.count(x)){
		vector<pii> t = h[x];
		SORT(t);
		int to = 0, c = 0;
		REP(i,t.size()){
			if(t[i].first>to)
				c+= t[i].first - to;
			to = max(to, t[i].second);
		}
		c+= m - to;

		int a = c - (c^len);
		if(a>0 && a<=c){
			to = 0, c = 0;
			REP(i,t.size()){
				if(t[i].first>to){
					c+= t[i].first - to;
					if(c>=a){
						cout<<0<<' '<<x<<' '<<t[i].first-(c-a)<<' '<<x<<endl;
						return 1;
					}
				}
				to = max(to, t[i].second);
			}
			c+= m - to;

			if(c>=a){
				cout<<0<<' '<<x<<' '<<m-(c-a)<<' '<<x<<endl;
				return 1;
			}
		}
	}else{
		int a = m-(m^len);
		if(a>0 && a<=m){
			cout<<0<<' '<<x<<' '<<a<<' '<<x<<endl;
			return 1;
		}
	}
	return 0;
}
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>k;
	REP(i,k){
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		if(x1==x2) v[x1].pb(pii(min(y1,y2),max(y1,y2)));
		else h[y1].pb(pii(min(x1,x2),max(x1,x2)));
	}

	vi v1 = parse(v, n, m,0);
	vi v2 = parse(h, m, n,1);

	int xr = 0;
	REP(i,v1.size()) xr^=v1[i];
	REP(i,v2.size()) xr^=v2[i];
	//REP(i,v1.size()) cout<<v1[i]<<' ';puts("");
	//REP(i,v2.size()) cout<<v2[i]<<' ';puts("");
	if(xr==0) puts("SECOND");
	else{
		puts("FIRST");
		for(int i=1;i<min(n,100111);i++)
			if(dohorstep(xr,i,n,m))
				return 0;
		for(int i=1;i<min(m,100111);i++)
			if(doverstep(xr,i,m,n))
				return 0;
		puts("FUCK");
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}