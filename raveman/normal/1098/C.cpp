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

bool good(int n,ll s,int p){
	ll currsum=1;
	ll currval=1;
	int tn=n-1;
	FOR(i,2,n+1){
		currval*=p;
		currval=min(currval,ll(tn));
		currsum+=currval*i;
		tn-=currval;
		if(tn==0)break;
	}
	if(s>=currsum && s<=n*ll(n+1)/2) return true;
	return false;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	
	int n;ll s;
	cin>>n>>s;

	int best=-1;
	int a = 1, b = n-1;
	while(a<=b){
		int m = (a+b)/2;
		if(good(n,s,m))best=m,b=m-1;
		else a=m+1;
	}
	if(best==-1)puts("No");
	else{
		puts("Yes");

		vi v;
		v.pb(1);
		ll currsum=1;
		ll currval=1;
		int tn=n-1;
		FOR(i,2,n+1){
			currval*=best;
			currval=min(currval,ll(tn));
			currsum+=currval*i;
			v.pb(currval);
			tn-=currval;
			if(tn==0)break;
		}
		s-=currsum;
		for(int i=v.size()-1;i>=0;i--){
			while(v[i]>1 && s>0){
				v[i]--;
				ll x = v.size()-1 - i;
				if(x>s)x=s;
				s-=x;

				if(s==0){
					v[i+x]++;
					s=0;
				}else{
					s--;
					v.pb(1);
				}
			}
		}
		int prev = 1; 
		FOR(i,1,v.size()){
			REP(j,v[i]){
				printf("%d ",prev + j/best);
			}
			prev += v[i-1];
		}
		puts("");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}