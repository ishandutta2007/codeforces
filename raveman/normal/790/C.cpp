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
#include<unordered_set>

using namespace std;

typedef long double ld;

typedef long long ll;
typedef pair<int,int>	pii;
typedef pair<ld,ld>	pdd;
typedef vector<ll> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

string s;
vi v,k,o;

int d[111][111][111][3];

int calc(int pos,int nv,int nk,int no){
	int r = 0;
	FOR(i,nv,v.size())if(v[i]<pos)r++;else break;
	FOR(i,nk,k.size())if(k[i]<pos)r++;else break;
	FOR(i,no,o.size())if(o[i]<pos)r++;else break;
	return r;
}

int solve(int nv,int nk,int no,int prev){
	if(nv+nk+no==s.size()) return 0;
	if(d[nv][nk][no][prev]!=-1)return d[nv][nk][no][prev];
	int res = 1e9;
	int pos = nv + nk + no;
	if(nv<v.size()){
		res = min(res, solve(nv+1,nk,no,0)+calc(v[nv],nv,nk,no));
	}
	if(nk<k.size() && prev!=0){
		res = min(res, solve(nv,nk+1,no,1)+calc(k[nk],nv,nk,no));
	}
	if(no<o.size()){
		res = min(res, solve(nv,nk,no+1,2)+calc(o[no],nv,nk,no));
	}
	//cout<<res<<endl;
	//cout<<nv<<' '<<nk<<' '<<no<<' '<<prev<<" =  "<<res<<endl;
	return d[nv][nk][no][prev]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n;cin>>n;
	cin>>s;
	REP(i,s.size()){
		if(s[i]=='V')v.pb(i);
		else if(s[i]=='K')k.pb(i);
		else o.pb(i);
	}
	CL(d,-1);
	cout<<solve(0,0,0,2)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}