#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

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

typedef pair<int,pii> p3;

int n;
int a[111111];
int b[111111];
int c[111111];
ll  r[111111];
vector<pii> e;

int p[111111];
int P(int x){return x==p[x] ? x : p[x] = P(p[x]);}
int q[111111];

vector<pii> v[111111];

void join(int v1,int v2){
	int p1 = P(v1);
	int p2 = P(v2);
	if(q[p1]<q[p2]){
		q[p2] += q[p1];
		p[p1] = p2;
	}else{
		q[p1] += q[p2];
		p[p2] = p1;
	}
}

int now;
int u[111111];

int dfs1(int ver,int par=-1){
	int res = q[ver];
	REP(i,v[ver].size()){
		if(v[ver][i].first!=par)
			res += dfs1(v[ver][i].first,ver);
	}
	return res;
}

int dfs2(int ver,int par,int total){
	u[ver]=now;
	int t = q[ver];
	REP(i,v[ver].size()){
		if(v[ver][i].first!=par){
			int res = dfs2(v[ver][i].first,ver,total);
			r[v[ver][i].second] = res * ll(total-res);
			t += res;
		}
	}
	return t;
}


int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	//n=100000;
	REP(i,n) p[i]=i,q[i]=1;

	REP(i,n-1){
		scanf("%d %d %d",a+i,b+i,c+i);
		//a[i] = 1+i;
	//	b[i] = a[i]+1;
		//c[i] = 1;

		a[i]--,b[i]--;
		e.pb(pii(c[i],i));
	}
	SORT(e);

	for(int i=0;i<e.size();){
		int j = i;
		while(j<e.size() && e[j].first == e[i].first) j++;

		FOR(k,i,j){
			int v1 = P(a[e[k].second]);
			int v2 = P(b[e[k].second]);
			
			v[v1].clear();
			v[v2].clear();
		}

		FOR(k,i,j){
			int v1 = P(a[e[k].second]);
			int v2 = P(b[e[k].second]);
			
			v[v1].pb(pii(v2,e[k].second));
			v[v2].pb(pii(v1,e[k].second));
		}


		now++;
		FOR(k,i,j){
			int v1 = P(a[e[k].second]);
			int v2 = P(b[e[k].second]);

			if(u[v1]!=now){
				int num = dfs1(v1);

				dfs2(v1,-1,num);
			}
		}


		FOR(k,i,j){
			int v1 = P(a[e[k].second]);
			int v2 = P(b[e[k].second]);
			join(v1,v2);
		}


		i = j;
	}

	ll best = -1;
	vi w;
	REP(i,n-1){
		if(r[i]>best) best = r[i],w.clear();
		if(r[i]==best) w.pb(i);
	}
	cout<<best*2<<' '<<w.size()<<endl;
	REP(i,w.size()){
		if(i)printf(" ");
		printf("%d",1+w[i]);
	}
	puts("");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}