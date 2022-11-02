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

ll r[1<<20];
int a[1<<20];
int nm[1<<20];
int n;
ll pw[1<<20];
ll Sum[1<<20];
ll Sq[1<<20];
ll S[1<<20];
ll Num[1<<20];
int d[6];
int st[10];

void add(ll& t, bool s, ll v){
	if(s){
		t += v;
		if(t>=mod)t-=mod;
	}else{
		t -= v;
		if(t<0)t+=mod;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	st[0]=1;
	FOR(i,1,10)st[i]=st[i-1]*10;
	pw[0]=1;
	FOR(i,1,1<<20)pw[i]=pw[i-1]*2%mod;
	cin>>n;
	REP(i,n)scanf("%d",a+i),nm[a[i]]++;
	for(int i=999999;i>=0;i--){
		int t = i;
		REP(j,6){
			d[j]=t%10;
			t/=10;
		}
		ll& sum = Sum[i];
		ll& num = Num[i];
		ll& s = S[i];
		ll& sq = Sq[i];
		REP(mask,1<<6){
			int nd = i;
			bool g = 1;
			bool c = 0;
			REP(j,6)if(mask&(1<<j)){
				nd+=st[j];
				c^=1;
				if(d[j]==9)g=0;
			}
			if(g){
				//if(i==11)cout<<"here "<<nd<<endl;
				add(num,c,Num[nd]);
				add(sum,c,Sum[nd]);
				add(s,c,S[nd]);
				add(sq,c,Sq[nd]);
			}
		}
		add(num,1,nm[i]);
		add(s,1,ll(i)*nm[i]%mod);
		add(sq,1,i * ll(i) * nm[i]%mod);
		//if(num)cout<<i<<endl;
		/*sum =...
		num += nm[i];
		s += ll(i) * nm[i];
		sq += i * ll(i) * nm[i];
		*/
		ll add = 0;
		if(num<=0);
		else if(num<=1)add=s*s%mod;
		else add=(((s%mod*s+sq)%mod)*pw[num-2])%mod;

		r[i] = add - sum;
		if(r[i]<0)r[i]+=mod;

		sum += r[i];
		if(sum>=mod)sum-=mod;

		//if(r[i])cout<<i<<": " <<r[i]<<endl;
	}

	ll res = 0;
	REP(i,1000000)res^=(i*r[i]);
	cout<<res<<endl;

	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}