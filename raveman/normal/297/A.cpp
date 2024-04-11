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

int s[1111];
string a,b;
int numone = 0;
int getMaxLen(string a,string b){
	string t=a;
	while(t.size()>b.size()){
		if(t[0]=='1') numone++;
		t.erase(t.begin());
	}
	while(t.size()){
		if(b.substr(0,t.size())==t) return t.size();
		if(t[0]=='1') numone++;
		t.erase(t.begin());
	}
	return 0;
}

bool v[1111];
pii  r[1111];

pii parse(int len){
	if(v[len]) return r[len];
	v[len]=true;
	string x = b.substr(0,len);
	x.pb(b[len]=='0'?'1':'0');
	int x1 = 0, x2 = 0;
	while(x!=b.substr(0,x.size())){
		if(x[0]=='1') x1++;
		x.erase(x.begin());
	}
	return r[len]=pii(x1,x.size());
}

bool v2[1111];
pii  r2[1111];

pii parse2(int len){
	if(v2[len]) return r2[len];
	v2[len]=true;
	string x = b.substr(0,len);
	int x1 = 0, x2 = 0;
	if(x[0]=='1') x1++;
	x.erase(x.begin());
	while(x!=b.substr(0,x.size())){
		if(x[0]=='1') x1++;
		x.erase(x.begin());
	}
	return r2[len]=pii(x1,x.size());
}

bool u[1111][1111];

bool dfs(int numone, int len){
	if(numone > 1011 || len==b.size()) return 1;
	if(u[numone][len]) return 0;
	u[numone][len]=true;
	if(numone){
		if(dfs(numone-1,len)) return 1;
	}else{		
		if(len){
			pii x = parse2(len);
			if(dfs(x.first,x.second))
				return 1;
		}
	}

	int t = (numone + (len?s[len-1]:0))%2;
	if(b[len]-'0'==t){
		if(dfs(numone,len+1))
			return 1;
	}else{
		pii x = parse(len);
		if(dfs(numone+x.first,x.second))
			return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>a>>b;
	REP(i,b.size()){
		s[i]=(i?s[i-1]:0)+b[i]-'0';
	}
	int len = getMaxLen(a,b);

	if(len==b.size()) puts("YES");
	else puts(dfs(numone,len)?"YES":"NO");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}