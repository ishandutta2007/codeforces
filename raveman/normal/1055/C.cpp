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

ll gcd(ll a, ll b){
	while(a&&b)
		if(a>b)a%=b;
		else b%=a;
	return a+b;
}

ll inter(pl t, ll la,ll ra){
	if(t.first==-1)return 0;
	if(t.first>ra || t.second<la) return 0;
	return min(t.second,ra)-max(t.first,la)+1;
}
ll test(ll lb,ll len,ll la,ll ra,ll ta){
	if(len>=ta)return ra-la+1;

	pl t1(lb,lb+len-1);
	pl t2(-1,-1);
	if(t1.second>=ta){
		t2=pl(0,t1.second%ta);
		t1.second=ta-1;
	}
	return inter(t1,la,ra)+inter(t2,la,ra);
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	ll la,ra,ta,lb,rb,tb;
	cin>>la>>ra>>ta>>lb>>rb>>tb;

	ll g = gcd(ta,tb);

	ll res = 0;

	ll len = rb-lb+1;
	lb %= ta;

	//[la,ra]
	//lb
	
	if(lb<la){
		ll t = (la-lb)/g;
		lb += t * g;
		res=max(res, test(lb,len,la,ra,ta));
		lb += g; lb%=ta;
		res=max(res, test(lb,len,la,ra,ta));
		lb += g; lb%=ta;
		res=max(res, test(lb,len,la,ra,ta));
	}else{
		ll t = (lb-la)/g;
		lb -= t*g;
		res=max(res, test(lb,len,la,ra,ta));
		lb -= g; if(lb<0)lb+=ta;
		res=max(res, test(lb,len,la,ra,ta));
	}

	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}