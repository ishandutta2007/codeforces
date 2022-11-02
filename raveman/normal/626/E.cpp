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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int n;
int a[222222];
ll  s[222222];

const bool DEBUG=0;

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	
	if(DEBUG){
		n=42;
		REP(i,n)a[i]=rand()%100;
	}

	sort(a,a+n);

	if(DEBUG){
		REP(i,n)cout<<a[i]<<' ';puts("");
	}

	REP(i,n)s[i]=(i?s[i-1]:0)+a[i];

	
	ll num = 0;
	ll denom = 1;
	pii s1(0,0),s2(0,0);

	// odd
	REP(i,n){

		if(DEBUG)cout<<"star "<<i<<endl;
		int f = 1;
		int t = min(i,n-1-i);
		int best = 0;
		while(f<=t){
			//cout<<f<<' '<<t<<endl;
			int rm = (f+t)/2;
			ll sum = s[i] - (i-rm>=0?s[i-rm]:0) + s[n-1]-s[n-rm];
			//cout<<rm<<' '<<2*sum<<' ' <<ll(rm*2-1)*(a[i-rm]+a[n-rm])<<endl;
			if (2*sum <= ll(rm*2-1)*(a[i-rm]+a[n-rm])){
				best = rm;
				f=rm+1;
			}else{
				t=rm-1;
			}
		}
		ll sum = s[i] - (i-best-1>=0?s[i-best-1]:0) + s[n-1]-s[n-best-1];
		ll denom2 = best * 2 + 1;
		sum -= a[i] * denom2;
		if(sum * denom > num * denom2) {
			num = sum;
			denom = denom2;
			s1 = pii(i-best,i);
			s2 = pii(n-best,n-1);
		}

		if(DEBUG){
			REP(j,best)printf("1");
			REP(j,min(i,n-1-i)-best)printf("0");
			puts("");

			{
				int s1 = a[i];
				double val = 0;
				int p1 = n-1;
				int p2 = i -1;
				int t = 1;
				while(p1>i && p2>=0){
					s1 += a[p1];
					s1 += a[p2];
					p1--;p2--;
					t+=2;
					double nval = (s1 - a[i] *t)/double(t);

					if(nval>=val) printf("1");
					else printf("0");
					val=nval;
				}
				puts("");
	
				puts("");
			}
		}
	}

	// even
	FOR(i,1,n){
		if(DEBUG){
			cout<<"star "<<i<<endl;
		}
		int f = 1;
		int t = min(i-1,n-1-i);
		int best = 0;
		while(f<=t){
			//cout<<f<<' '<<t<<endl;
			int rm = (f+t)/2;
			ll sum = s[i] - (i-rm-1>=0?s[i-rm-1]:0) + s[n-1]-s[n-rm];
			//cout<<rm<<' '<<2*sum<<' ' <<ll(rm*2)*(a[i-rm-1]+a[n-rm])<<endl;
			if (2*sum <= ll(rm*2)*(a[i-rm-1]+a[n-rm])){
				best = rm;
				f=rm+1;
			}else{
				t=rm-1;
			}
		}
		ll sum = s[i] - (i-best-2>=0?s[i-best-2]:0) + s[n-1]-s[n-best-1];
		ll denom2 = best * 2 + 2;
		sum -= (a[i]+a[i-1]) * denom2 / 2;
		if(sum * denom > num * denom2) {
			num = sum;
			denom = denom2;
			s1 = pii(i-best-1,i);
			s2 = pii(n-best,n-1);
		}

		if(DEBUG){
			REP(j,best)printf("1");
			REP(j,min(i-1,n-1-i)-best)printf("0");
			puts("");

			{
				int s1 = a[i]+a[i-1];
				double val = 0;
				int p1 = n - 1;
				int p2 = i - 2;
				int t = 2;
				while(p1>i && p2>=0){
					s1 += a[p1];
					s1 += a[p2];
					p1--;p2--;
					t+=2;
					double nval = (s1 - (a[i]+a[i-1])/2. *t)/double(t);

					if(nval>=val) printf("1");
					else printf("0");
					val=nval;
				}
				puts("");
	
				puts("");
			}
		}
	}

//	cout<<num <<' '<<denom<<endl;

	vi res;
	REP(i,n)if(i>=s1.first && i<=s1.second || i>=s2.first && i<=s2.second)res.pb(a[i]);

	cout<<res.size()<<endl;
	REP(i,res.size()){
		if(i)printf(" ");
		printf("%d",res[i]);
	}
	puts("");

#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}