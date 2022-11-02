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

char sss[333333];
int    p[111111];
string s[111111],t;
vi     v[111111];
int n;

int  kmp[111111];

void buildKMP(const string& s){
	CL(kmp,-1);
	int curr = -1;
	FOR(i,1,s.size()){
		while(curr>=0 && s[curr+1]!=s[i]) curr=kmp[curr];
		if(s[curr+1]==s[i]) curr++;
		kmp[i]=curr;
	}
}

int res;

void dfs(int ver, int curr=-1){
	int tcurr = curr;
	REP(i,v[ver].size()){
		const string& ss = s[v[ver][i]];
		curr = tcurr;
		REP(j,ss.size()){
			while(curr>=0 && t[curr+1]!=ss[j]) curr=kmp[curr];
			if(t[curr+1]==ss[j]) curr++;
			if(curr+1==t.size()){
				res++;
				//cout<<ver+1<<' '<<j<<endl;
				curr=kmp[curr];
			}
		}

		dfs(v[ver][i], curr);
	}
}
	
int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n-1){
		int x;
		scanf("%d %s",&x,&sss);
		x--;
		v[x].pb(i+1);
		p[i+1]=x;
		s[i+1]=string(sss);		
	}
	cin>>t;
	buildKMP(t);
	dfs(0);
	
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}