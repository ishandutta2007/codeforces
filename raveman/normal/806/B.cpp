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
int a[222][5];

int getTaskCost(int task,ll total,ll add=0){
	ll num = 0;
	REP(j,n)if(a[j][task]!=-1)num++;
	num+=add;
	if(num*2>total) return 500;
	if(num*4>total) return 1000;
	if(num*8>total) return 1500;
	if(num*16>total) return 2000;
	if(num*32>total) return 2500;
	return 3000;
}

bool good(ll total){
	if(total<n) return 0;
	ll add = total - n;
	ll d = 0;
	REP(i,5){
		//cout<<i<<" : " <<d<<endl;
		if(a[0][i]==-1 && a[1][i]==-1)continue;
		else if(a[0][i]==-1){
			ll cost = getTaskCost(i,total);
			d += (cost - a[1][i]*cost/250);
		}else if(a[1][i]==-1){
			ll cost = getTaskCost(i,total);
			d -= (cost - a[0][i]*cost/250);
		}else if(a[0][i]<a[1][i]){
			ll cost = getTaskCost(i,total);
			d += (cost - a[1][i]*cost/250);
			d -= (cost - a[0][i]*cost/250);
		}else if(a[0][i]>a[1][i]){
			ll cost = getTaskCost(i,total,add);
			d += (cost - a[1][i]*cost/250);
			d -= (cost - a[0][i]*cost/250);
		}else continue;
	}
	//cout<<d<<endl;
	return d<0;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)REP(j,5)cin>>a[i][j];
	
	vector<ll> s;
	s.pb(n);
	s.pb(1000000007+n);
	REP(i,5){
		if(a[0][i]==-1 && a[1][i]!=-1){
			int num = 0;
			REP(j,n)if(a[j][i]!=-1)num++;
			for(int x = 2; x<= 32;x*=2){
				s.pb(num*x);
				s.pb(num*x+1);
				s.pb(num*x-1);
			}
		}
	}
	
	UN(s);
	ll best = -1;
	REP(i,s.size())if(good(s[i])){
		if(best==-1 || best>s[i])best=s[i];
	}
	FOR(i,1,s.size()){
		ll from = s[i-1]+1;
		ll to = s[i]-1;
		//cout<<"start " <<from<<' '<<to<<endl;
		while(from<=to){
			ll m = (from+to)/2;
			//cout<<m<<": "<<good(m)<<endl;
			if(good(m)){
				if(best==-1 || best>m)best=m;
				to=m-1;
			}else from=m+1;
		}
	}
	if(best!=-1)cout<<best-n<<endl;
	else cout<<best<<endl;

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}