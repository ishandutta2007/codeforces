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

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		ll x,y,p,q;
		cin>>x>>y>>p>>q;


		//(x + t1) / (y + t2)  = p / q
		//	t1<=t2 t2->min

		//xq + t1q = pt2+yp
		//t1q-t2p=yp-xq

		//ll e = y * p - x * q;

		//pk / qk

		//qk >= y

		//t2 = qk - y  + i * q

		//t1 = p * k - x + i * p

		ll k = (y + q - 1) / q;
		ll v1 = q * k - y;
		ll v2 = p * k - x;

		// t2 = v1 + i * q;
		// t1 = v2 + i * p;
		

		// t1 >=0 && t1 <= t2
		//i * p >= tv2
		ll tv2 = - v2;
		if (p==0 && tv2 > 0) {puts("-1");continue;}

		ll mini= 0;
		if(p==0){
		}else{
			mini=max(0ll,(tv2 + p - 1 ) / p);
		}

		// t1 <= t2
		// v2 + i * p <= v1 + i * q
		// i * (p - q) <= v1 - v2
		ll d1 = p - q;
		ll d2 = v1 - v2;
		// i * d1 <= d2
		d1 = -d1;
		d2 = -d2;
		// i * d1 >= d2;
		if (d1==0){
			if (d2>0) {puts("-1");continue;}

		}else {
			mini = max(mini, (d2 + d1 - 1)/d1);
		}
		cout<<(mini+k)*q-y<<endl;
	}

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}