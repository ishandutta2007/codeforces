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

int n;
int a[222222];
int b[222222];
int ID[444444];
bool u[222222];
bool p[222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d %d",a+i,b+i),a[i]--,b[i]--,ID[a[i]]=i,ID[b[i]]=i;

	int res=0;

	vector<pii> q;

	for(int i=0;i<n;){
		vi c;
		for(int j=0;;j++){
			int p1 = ID[i+j];
			int p2 = ID[2*n-1-i-j];
			if(!u[p1])u[p1]=1,c.pb(p1);
			if(!u[p2])u[p2]=1,c.pb(p2);
			if(c.size()==j+1)break;
		}
		i+=c.size();

		vector<pair<pii,pii>> w;
		REP(j,c.size()){
			w.pb(make_pair(pii(a[c[j]],b[c[j]]),pii(0,c[j])));
			if(w.back().first.first>w.back().first.second)swap(w.back().first.first,w.back().first.second),w.back().second.first=1;
		}
		SORT(w);
		vector<pair<pii,pii>> w2;
		REP(j,w.size()){
			w2.pb(w[j]);
			swap(w2.back().first.first,w2.back().first.second);
			w2.back().second.first=1-w2.back().second.first;
		}
		SORT(w2);

		int cc=w[0].second.first;
		int uv=w[0].first.second;
		q.pb(w[0].first);
		p[w[0].second.second]=1;
		vector<pii> rq;
		FOR(j,1,w.size()){
			while(!w2.empty() && w2.back().first.first>uv){
				if(p[w2.back().second.second]){
					w2.pop_back();
					continue;
				}
				rq.pb(w2.back().first);
				cc+=w2.back().second.first;
				p[w2.back().second.second]=1;
				//cout<<"add back "<<w2.back().second.second<<endl;
				w2.pop_back();
			}

			if(p[w[j].second.second])continue;
			p[w[j].second.second]=1;
			cc+=w[j].second.first;
			q.pb(w[j].first);
			uv=w[j].first.second;
			//cout<<"add begin "<<" "<<w[j].second.second <<endl;
		}
		reverse(rq.begin(),rq.end());
		REP(j,rq.size())q.pb(rq[j]);
		res+=min(cc,int(w.size())-cc);
	}
	SORT(q);
	//REP(i,q.size())cout<<q[i].first+1<<' '<<q[i].second+1<<endl;
	FOR(i,1,q.size())if(q[i].second>q[i-1].second){
		puts("-1");
		return 0;
	}

	cout<<res<<endl;


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}