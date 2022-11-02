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

ll solve(string s,ll x,ll y){
	string t=s;
	ll res = 0;
	ll n0=0,n1=0;
	REP(i,t.size()){
		if(t[i]=='?')t[i]='0';
		if(t[i]=='0'){
			res += n1 * y;
			n0++;
		}else if(t[i]=='1'){
			res += n0 * x;
			n1++;
		}
	}

	ll n0e=0,n1e=0;
	ll c = res;
	for(int i=t.size()-1;i>=0;i--){
		if(t[i]=='0'){
			n0--;
		}else n1--;

		if(s[i]=='?'){
			t[i]='1';
			
			//0
			c-=n1e * x;
			c-=n1 * y;

			c+=n0e * y;
			c+=n0 * x;
		}

		if(t[i]=='0')n0e++;
		else n1e++;

		res=min(res,c);
	}
	
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	string s;
	cin>>s;
	ll x,y;
	cin>>x>>y;

	ll res = 1e18;
	res=min(res,solve(s,x,y));
	reverse(s.begin(),s.end());
	res=min(res,solve(s,y,x));

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}