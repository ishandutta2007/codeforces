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

int n;
int v[111111];
int t[111111];

ll  s[111111];

int ones[111111];
ll  cum[111111];

vector<ll> solve(){

	CL(ones,0);CL(cum,0);


	REP(i,n)s[i]=(i?s[i-1]:0)+t[i];
	s[n]=1e18;

	REP(i,n){
		ll currt = i?s[i-1]:0;
		int pos = lower_bound(s+i,s+n,currt + v[i]) - s;

		int from = i;
		int to = pos-1;
		if(from<=to){
			ones[from]++;
			ones[to+1]--;
		//	cout<<"add "<<from<<" "<<to+1<<endl;
		}

		v[i] -= ((pos-1>=0?s[pos-1]:0)-currt);
		cum[pos] += v[i];
		//cout<<"addc "<<pos<<' '<<v[i]<<' '<<i<<endl;
	}

	vector<ll> r;
	ll tones = 0;
	REP(i,n){
		tones += ones[i];
		r.pb(tones * t[i] + cum[i]);
	}
	return r;
}

int c[111111];
vector<ll> stupid(){
	vector<ll> w;
	REP(i,n){
		c[i]=v[i];
		ll sum=0;
		REP(j,i+1){
			int tt = min(c[j],t[i]);
			c[j]-=tt;
			sum+=tt;
		}
		w.pb(sum);
	}
	return w;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;REP(i,n)scanf("%d",v+i);REP(i,n)scanf("%d",t+i);

//start:
	//n=10;REP(i,n)v[i]=rand()%10;REP(i,n)t[i]=rand()%10;

	//cout<<n<<endl;
//	REP(i,n)cout<<v[i]<<' ';puts("");
//	REP(i,n)cout<<t[i]<<' ';puts("");

	//vector<ll> ws = stupid();
	vector<ll> w = solve();
	/*if(w!=ws){
		puts("FUCK");
		REP(i,w.size())cout<<w[i]<<' ';puts("");
		REP(i,ws.size())cout<<ws[i]<<' ';puts("");
		while(1);
	}
	else puts("OK");
	goto start;
	*/

	REP(i,w.size()){
		cout<<w[i]<<' ';;
	}
	puts("");


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}