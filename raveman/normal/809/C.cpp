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

const int mod = 1000000007;

ll solve(int x,int y, int k){
	if(x<0 || y<0) return 0;
	ll res = 0;
	ll add = 0;
	for(int st=(1<<29);st>=0;st>>=1){
		if(x>y) swap(x,y);
		//cout<<st<<' '<<x<<' '<<y<<' '<<add<<" = "<<res<<endl;
		if(st==0){
			if(k>=add+1)res=(res+add+1)%mod;
		 break;
		}
		if(x==st-1 && y==st-1){
			ll c = min((ll)k,st+add)-add;
			if(c>0)
			res = (res + c * ( c + 1 + add + add )/ 2 % mod * st)%mod;
			break;
		}
		if(x<st && y<st) {
			//q1
			continue;
		}
		if(x>=st && y>=st){
			//q4
			ll c = min((ll)k,st+add)-add;
			if(c>0)res = (res + c * (1 + c+add+add) / 2 % mod * st) % mod;
			if (k>st){
				ll c2 = min((ll)k, 2*st+add)-add - st;
				if(c2>0)res = (res + c2 * (st+1 + st + c2+add+add)/2 % mod * (x-st+1+y-st+1) ) % mod;
			}
			x-=st;
			y-=st;
			continue;
		}
		// q2
		ll c = min((ll)k,st+add)-add;
		if(c>0)res = (res + c * (1 + c+add+add) / 2 % mod * (x+1)) % mod;
		y-=st;
		add += st;
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int q;
	cin>>q;
	REP(TC,q){
		int x1,x2,y1,y2,k;
		cin>>x1>>y1>>x2>>y2>>k;
		x1--,x2--,y1--,y2--;
		ll sum = solve(x2,y2,k) - solve(x2,y1-1,k) - solve(x1-1,y2,k) + solve(x1-1,y1-1,k);
		while(sum>=mod)sum-=mod;
		while(sum<0)sum+=mod;
		cout<<sum<<"\n";
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}