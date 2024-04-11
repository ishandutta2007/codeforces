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

int r[1111111];
vi  p;

map<vi,int> v;
vector<vi> d;
int id[1<<20];

int dp[300][1000];

void go(int id, const vi& d,int pos=0,int currp=1,int currsum=0,int prevval=20){
	//cout<<id<<' '<<pos<<' '<<currp<<' '<<currsum<<' '<<prevval<<endl;
	if(currsum>10 || currp>=1000) return;
	if(pos>=d.size()) if(dp[id][currp]==-1 || dp[id][currp]>currsum)dp[id][currp]=currsum;
	if(prevval==0) return;
	if(pos<d.size()){
		REP(i,prevval+1){
			go(id,d,pos+1,currp*(i+1),currsum+abs(i-d[pos]),i);
		}
	}else{
		REP(i,prevval+1){
			go(id,d,pos+1,currp*(i+1),currsum+i,i);
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	FOR(i,2,1111111)if(!r[i]){
		p.pb(i);
		for(ll j=i*ll(i);j<1111111;j+=i) r[j]=i;
	}
	FOR(i,1,1000000+1){
		vi w;
		int t = i;
		while(r[t]!=0){
			int d = r[t];
			int c = 0;
			while(t%d==0)t/=d,c++;
			w.pb(c);
		}
		if(t>1)w.pb(1);
		SORT(w);
		reverse(w.begin(),w.end());
		if(v.count(w)) id[i]=v[w];
		else{
			int sz = v.size();
			id[i]=v[w]=sz;
			d.pb(w);
		}
	}

	CL(dp,-1);
	REP(i,d.size()){
		go(i,d[i]);
	}

	/*int mans = 0;
	REP(i,d.size()){
		REP(j,d.size()){
			int ans = 100;
			REP(k,1000)if(dp[i][k]!=-1 && dp[j][k]!=-1)ans=min(ans,dp[i][k]+dp[j][k]);
			//cout<<i<<' '<<j<<"= " <<ans<<endl;
			if(ans==34){
				REP(ii,d[i].size()) cout<<d[i][ii]<<' ';puts("");
				REP(ii,d[j].size()) cout<<d[j][ii]<<' ';puts("");
			}
			mans = max(mans,ans);
		}
	}
	cout<<mans<<endl;
	*/
	int tc;
	cin>>tc;
	REP(TC,tc){
		int a,b;
		scanf("%d %d",&a,&b);
		int t1 = id[a];
		int t2 = id[b];
		int res = 100;
		REP(i,1000)if(dp[t1][i]!=-1 && dp[t2][i]!=-1) res=min(res,dp[t1][i]+dp[t2][i]);

		printf("%d\n",res);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}