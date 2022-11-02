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

bool OUTPUT_TO_FILE = 0;

int n,m;
vi v[1111111];
ll p[1111111];
ll h[1111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	if(OUTPUT_TO_FILE) freopen("output.txt","w",stdout);
#endif

	p[0] = 1;
	FOR(i,1,1111111) p[i]=p[i-1]*3;
	cin>>n>>m;
	REP(i,m){
		int x,y;
		scanf("%d %d",&x,&y);
		x--,y--;
		//x=i;
		//y=(i+1)%n;
		h[x] += p[y];
		h[y] += p[x];
		v[x].pb(y);
		v[y].pb(x);
	}

	ll res = 0;
	REP(i,n) REP(j,v[i].size())if(i<v[i][j]){
		int v2 = v[i][j];
		int d1 = v[i].size();
		int d2 = v[v2].size();
		if(d1==d2) if( h[i] - p[v2] == h[v2] - p[i] ) res++;
	}


	vector< pair<int,ll> > t;
	REP(i,n) t.pb(make_pair(v[i].size(),h[i]));
	
	SORT(t);

	for(int i=0;i<n;){
		int j = i;
		while(j<n && t[i] == t[j]) j++;
		res += ll(j-i)*(j-i-1)/2;
		i=j;
	}
	
	cout<<res<<endl;

#ifdef LocalHost
	if(!OUTPUT_TO_FILE) cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}