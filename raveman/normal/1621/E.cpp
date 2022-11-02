#pragma comment(linker, "/STACK:60777216")  

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
typedef vector<ll> vl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

bool DEBUG=0;

int n,m;
int a[111111];
int k[111111];
vi  b[111111];
ll  s[111111];
int s0[111111];
int s1[111111];
int sm1[111111];

bool cmp(const pl& p1, const pl& p2){
	return p1.first*p2.second>p2.first*p1.second;
}

bool good(int pos, int newpos){
	if(pos==newpos){
		if(pos>0 && s0[pos-1]!=pos) return 0;
		if(s0[m-1]-s0[pos]!=(m-1-pos))return 0;
		return 1;
	}
	if(newpos<pos){
		if(newpos>0 && s0[newpos-1]!=newpos) return 0;
		if(s0[m-1]-s0[pos]!=(m-1-pos))return 0;
		if(sm1[pos-1]-(newpos-1>=0?sm1[newpos-1]:0) != (pos-newpos)) return 0;
		return 1;
	}
	if(newpos>pos){
		if(pos>0 && s0[pos-1]!=pos) return 0;
		if(s0[m-1]-s0[newpos]!=(m-1-newpos))return 0;
		if(s1[newpos-1]-(pos-1>=0?s1[pos-1]:0) != (newpos-pos)) return 0;
		return 1;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		REP(i,n)scanf("%d",a+i);
		REP(i,m){
			scanf("%d",k+i);
			b[i].resize(k[i]);
			s[i]=0;
			REP(j,k[i])scanf("%d",&b[i][j]),s[i]+=b[i][j];
		}
		vi A;
		REP(i,n)A.pb(a[i]);
		SORT(A);
		reverse(A.begin(),A.end());
		A.resize(m);

		vector<pl> B;
		REP(i,m)B.pb(pl(s[i],b[i].size()));
		sort(B.begin(),B.end(),cmp);

		// 0
		REP(i,m){
			s0[i] = (A[i]*B[i].second>=B[i].first) ? 1 : 0;
			if(i)s0[i]+=s0[i-1];
		}
		// +1
		REP(i,m-1){
			s1[i] = (A[i]*B[i+1].second>=B[i+1].first) ? 1 : 0;
			if(i)s1[i]+=s1[i-1];
		}
		// -1
		REP(i,m-1){
			sm1[i] = (A[i+1]*B[i].second>=B[i].first) ? 1 : 0;
			if(i)sm1[i]+=sm1[i-1];
		}

		if(DEBUG){
			cout<<"s0"<<endl;
			REP(i,m)cout<<s0[i];puts("");
			cout<<"B"<<endl;
			REP(i,B.size())cout<<B[i].first<<'/'<<B[i].second<<' ';puts("");
			cout<<"A"<<endl;
			REP(i,A.size())cout<<A[i]<<' ';puts("");
			puts("done");
		}
		if(DEBUG)cout<<"test "<<good(1,1)<<endl;
		REP(i,m){
			pl t(s[i],b[i].size());
			int pos = lower_bound(B.begin(),B.end(),t,cmp) - B.begin();
			int from = 0;
			int to = m-1;
			int best=-1;
			while(from<=to){
				int mid = (from+to)/2;
				if(good(pos,mid)){
					best=mid;
					to=mid-1;
				}else{
					from=mid+1;
				}
			}
			if(DEBUG)cout<<i<<": "<<best<<' '<<pos<<endl;
			if(best==-1){
				REP(j,b[i].size())printf("0");
			}else{
				REP(j,b[i].size()){
					if((s[i] - b[i][j]) > ll(A[best])*(b[i].size()-1)) printf("0");
					else printf("1");
					
				}
			}
		}
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}