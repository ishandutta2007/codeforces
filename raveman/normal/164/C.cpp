#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

using namespace std;
 
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;
 
#define FOR(i,a,b) for (int i(a); i < (b); i++)
#define REP(i,n) FOR(i,0,n)
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,k;
int s[1111];
int t[1111];
int c[1111];

vector<pii> f[2222];
const int inf = 10111111111;

int d[2222];
int from[2222];


struct mcnet {
	vector< vector< pair<int,pii> > > a;
	vector< pair<int,pii> >::iterator i;
	mcnet(int n):a(n){}
	void add(int x,int y,int w,int c=1){
		for(i=a[x].begin();i!=a[x].end();++i)
			if(i->first==y && i->second.second==w){
				if(!(i->second.first+=c))
					*i=a[x].back(),a[x].pop_back();
				return;
			}
		a[x].pb(make_pair(y,pii(c,w)));
	}

	bool hascycle(){
		int aa[4444];
		int n  = a.size();
		REP(i,n) aa[i]=0;
		REP(i,n)REP(j,n)REP(k,a[j].size())
			aa[a[j][k].first]=min(aa[a[j][k].first],aa[j] + a[j][k].second.second);
		REP(j,n)REP(k,a[j].size())
			if(aa[a[j][k].first] > aa[j] + a[j][k].second.second)
				return 1;
		if(n>2000){
			puts("FUCK");
			return 1;
		}
		return 0;
	}

	pii flow(int s,int t,int k){
		vi p(a.size());
		for(pii res;res.first<k;){
			priority_queue<pii> Q;
			vi f(a.size(),-1u/2),prev(a.size(),-1);
			f[s]=0,Q.push(pii(0,-s));
			//if(hascycle()) return pii(-1,-1);
			for(int x,d;Q.size();){
				pii cur=Q.top(); Q.pop();
				if(f[x=-cur.second]!=(d=-cur.first))continue;
				for(i=a[x].begin();i!=a[x].end();++i){
					int y=i->first,z=i->second.second;
					if(d+z+p[x]-p[y]<f[y])
						f[y]=d+z+p[x]-p[y],prev[y]=x,Q.push(pii(-f[y],-y));
				}
			}
			if(prev[t]<0) return res;
			int flow=1;
			for(int x,y=t;~(x=prev[y]);y=x)
				for(i=a[x].begin();i!=a[x].end();++i)
					if(i->first==y && f[x]+i->second.second+p[x]==f[y]+p[y])
						flow=min(flow,i->second.first);
				res.first+=flow,res.second+=(f[t]+p[t]-p[s])*flow;
				for(int x,y=t;~(x=prev[y]);y=x)
					add(x,y,f[y]+p[y]-f[x]-p[x],-flow),
					add(y,x,f[x]+p[x]-f[y]-p[y],+flow);
				REP(i,a.size())p[i]+=f[i];
		}
	}
};

void floww(){
	REP(i,2*n+2) d[i]=inf,from[i]=-1;
	d[2*n]=0;
	priority_queue<pii> q;
	q.push(pii(0,2*n));
	while(!q.empty()){
		pii x = q.top();q.pop();
		int ver = x.second;
		int cost = -x.first;
		//cout<<ver<<' '<<cost<<endl;
		if(d[ver]!=cost) continue;

		REP(i,f[ver].size()){
			int nw = f[ver][i].first;
			int ncost = cost + f[ver][i].second;
			if(d[nw] > ncost){
				d[nw] = ncost;
				from[nw] = ver;
				q.push(pii(-ncost,nw));
			}
		}
	}
	if(d[2*n+1]!=inf){
		int curr = 2*n + 1;
		while(curr!=2*n){			
			int prev = from[curr];
			
			REP(i,f[prev].size()) if(f[prev][i].first==curr){
				f[curr].pb(pii(prev,-f[prev][i].second));
				swap(f[prev][i],f[prev].back());
				f[prev].pop_back();
			}
			
			curr=prev;
		}
	}
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	
	REP(i,n) scanf("%d %d %d",s+i,t+i,c+i);
	vi xx;
	xx.pb(0);
	xx.pb(2000000000);
	REP(i,n) xx.pb(s[i]);
	REP(i,n) xx.pb(s[i]+t[i]);
	UN(xx);
	/*
	REP(i,n) f[i].pb(pii(i+n,-c[i]));
	REP(i,n)REP(j,n)if(s[i]+t[i]-1 < s[j]) f[i+n].pb(pii(j,0));
	REP(i,n) f[i+n].pb(pii(2*n+1,0));
	REP(i,n) f[2*n].pb(pii(i,0));
	*/

	
	mcnet fl(2*n+xx.size());
	REP(i,n) fl.add(i,i+n,-c[i]);
	REP(j,k) REP(i,xx.size()-1) fl.add(2*n+i,2*n+i+1,0);
	REP(i,n) fl.add(i+n,2*n+lower_bound(xx.begin(),xx.end(),s[i]+t[i])-xx.begin(),0);	
	REP(i,n) fl.add(2*n+lower_bound(xx.begin(),xx.end(),s[i])-xx.begin(),i,0);
	pii t = fl.flow(2*n,2*n+xx.size()-1,k);
	
	/*
	mcnet fl(xx.size());
	REP(j,k) REP(i,xx.size()-1) fl.add(i,i+1,0);
	REP(i,n) fl.add(lower_bound(xx.begin(),xx.end(),s[i])-xx.begin(),lower_bound(xx.begin(),xx.end(),s[i]+t[i])-xx.begin(),-c[i]);
	pii t = fl.flow(0,xx.size()-1,k);
	*/
	//cout<<t.first<<' '<<t.second<<endl;
	//cout<<t.first<<' '<<t.second<<endl;
	
	//REP(i,k) flow();
	REP(i,n){
		if(i) printf(" ");
		bool use = 0;
		REP(j,fl.a[i+n].size()) if(fl.a[i+n][j].first==i) use = 1;
		printf("%d",(use?1:0));
	}
	puts("");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}