#pragma comment(linker, "/STACK:60777216")  

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

int n,q,t;
int a[333];
int d[333];
int ind[333];
int r[111111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>q>>t;
	REP(i,n) cin>>a[i];
	CL(d,-1);CL(ind,-1);
	REP(i,q){
		int x,y;
		cin>>x>>y;
		x--,y--;
		d[x]=y;
		ind[y]=x;
	}
	ll total = 0;
	vi tt;
	REP(i,n)if(ind[i]==-1){
		int curr = i;
		vi v;
		while(curr!=-1){
			v.pb(a[curr]);
			curr=d[curr];
		}
		curr = 0;
		REP(j,v.size()){
			curr += v[j];
			tt.pb(curr);
			total += v[j] * (v.size()-1-j);
		}
	}
	if(total>t || tt.size()!=n) puts("0");
	else{
		//REP(i,tt.size()) cout<<tt[i]<<' ';puts("");
		r[total] = 1;
		REP(i,tt.size()){
			int c = tt[i];
			for(int j=total;j<=t-c;j++){
				r[j+c] += r[j];
				if(r[j+c]>=mod) r[j+c]-=mod;
			}
		}
		cout<<r[t]<<endl;
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}