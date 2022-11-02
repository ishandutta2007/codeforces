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

const int mod = 1000000007;

int n,k;
string s;
int d[2002][2002][2];
int go(int pos,int k,bool num=0){
	if(k<0) return 0;
	//cout<<os<<' '<<k<<' '<<num<<' '<<mn<<endl;
	if(pos==s.size()) return k==0 ? 1 : 0;
	if(d[pos][k][num]!=-1) return d[pos][k][num];
	ll res = 0;
	res += ll(s[pos]-'a') * go(pos+1, k, 0);
	res += go(pos+1, k, 1);
	//if(s[pos]!='z') res += ll(26 - (s[pos]-'a') -1) * go(pos+1, k - (num+1) * (n-pos) ,0);
	if(num==0){
		int numeq=0;
		for(numeq=0;numeq<n-pos;numeq++)if(s[pos+numeq]!='z'){
			if((numeq+1)*(n-pos-numeq)>k) break;
			res += ll(26 - (s[pos+numeq]-'a') -1) * go(pos+numeq+1, k - (numeq+1)*(n-pos-numeq) ,0);
		}
		int x = numeq;
		for(numeq=n-pos-1;numeq>x;numeq--)if(s[pos+numeq]!='z'){
			if((numeq+1)*(n-pos-numeq)>k) break;
			res += ll(26 - (s[pos+numeq]-'a') -1) * go(pos+numeq+1, k - (numeq+1)*(n-pos-numeq) ,0);
		}
	}
	return d[pos][k][num]=res%mod;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	CL(d,-1);
	cin>>n>>k>>s;
	//n=2000;	k=2000;	s="";	REP(i,n)s.pb(char('x+rand()%2));
	cout<<go(0,k,0)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}