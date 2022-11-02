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

string s[333];
bool u[333][333];
int a[333][333];
int n;
set<pii> w;

void recalc(int i,int j){
	if(i<0 || j<0 || i>=n || j>=n)return;
	if(s[i][j]=='.')return;
	if(u[i][j] && w.count(pii(-a[i][j], 1000*i+j)))w.erase(pii(-a[i][j], 1000*i+j));
	int rt=0;
	bool need=0;
	REP(r,2){
		int t =0;
		char c = "XO"[r];
		if(i>=2 && s[i-1][j]==c && s[i-2][j]==c)t++;
		if(i>=1 && i+1<n && s[i-1][j]==c && s[i+1][j]==c)t++;
		if(i+2<n && s[i+1][j]==c && s[i+2][j]==c)t++;
		if(j>=2 && s[i][j-1]==c && s[i][j-2]==c)t++;
		if(j>=1 && j+1<n && s[i][j-1]==c && s[i][j+1]==c)t++;
		if(j+2<n && s[i][j+1]==c && s[i][j+2]==c)t++;
		if(c==s[i][j]){
			rt+=t;
			if(t>0)need=1;
		}
		else rt-=t;
	}
	if(need){
		u[i][j]=1;
		a[i][j]=rt;
		w.insert(pii(-rt,1000*i+j));
	}else{
		u[i][j]=0;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n;
		REP(i,n)cin>>s[i];
		vector<pii> v0,v1,v2;
		REP(i,n)REP(j,n)if(s[i][j]=='X'){
			if((i+j)%3==0)v0.pb(pii(i,j));
			if((i+j)%3==1)v1.pb(pii(i,j));
			if((i+j)%3==2)v2.pb(pii(i,j));
		}
		if(v0.size()<=v1.size() && v0.size()<=v2.size()){
			REP(i,v0.size())s[v0[i].first][v0[i].second]='O';
		}else if(v1.size()<=v2.size() && v1.size()<=v0.size()){
			REP(i,v1.size())s[v1[i].first][v1[i].second]='O';
		}else{
			REP(i,v2.size())s[v2[i].first][v2[i].second]='O';
		}
		REP(i,n)cout<<s[i]<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}