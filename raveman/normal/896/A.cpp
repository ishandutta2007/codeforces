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
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back	

string s="What are you doing at the end of the world? Are you busy? Will you save us?";
string t1="What are you doing while sending \"";
string t2="\"? Are you busy? Will you send \"";
string t3="\"?";

ll m[111111];
double d[111111];

char solve(int n,ll c){
	if(c>d[n]*2)return '.';
	if(c>=m[n])return '.';
	if(n==0)return s[c];
	if(c<t1.size()) return t1[c];
	c-=t1.size();
	if(c<m[n-1])return solve(n-1,c);
	c-=m[n-1];
	if(c<t2.size())return t2[c];
	c-=t2.size();
	if(c<m[n-1])return solve(n-1,c);
	c-=m[n-1];
	return t3[c];
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	m[0]=s.size();
	FOR(i,1,111111)m[i]=m[i-1]*2+t1.size()+t2.size()+t3.size(),m[i]=max(m[i],m[i-1]);
	d[0]=s.size();
	FOR(i,1,111111)d[i]=d[i-1]*2+t1.size()+t2.size()+t3.size(),d[i]=min(d[i],1e30);


	int tc;
	cin>>tc;
	REP(TC,tc){
		int n;
		ll  c;
		cin>>n>>c;c--;

		cout<<solve(n,c);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}