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

	ll n,l,r,k;
	cin>>n>>l>>r>>k;

	ll num = 0;
	if(r>=l)num=r-l+1;
	else num=n-l+1+r-1+1;

	ll ans = -1;

	// 0 circles
	if(k>=num && k<=2*num){
		k-=num;
		ans=n-num + min(k+1,num);
	}

	// >=1 circle

	// n - small
	if(n<=1000000){
		REP(res,n+1){
			ll rem_k = k % (n + res);
			if(rem_k==0)rem_k=n+res;
			if(rem_k>=num && rem_k<=2*num){
				rem_k-=num;

				//cout<<"start "<<res<<endl;
				//cout<<rem_k<<endl;
				// last s
				ll tmp= min(rem_k+1,num);
				if(tmp<=res && tmp + n-num>=res)ans=max(ans,(ll)res);
				// last ns
				tmp= min(rem_k,num);
				if(tmp<=res && tmp + n-num>=res)ans=max(ans,(ll)res);
			}
		}
	}else{
		FOR(c,1,k/n+1){
			ll remk = k - n * c - num;
			if(remk>=0){
				ll p_res = remk/c;

				// 0      remk/c     p_res==n-num+1         p_res==num
				/*
				ll from = max(0ll, p_res - (n-num)-1);
				ll to = min(p_res, num);

				if(p_res+to<k) continue;
				if(p_res+from<=k){
					ans=max(ans,p_res);
					continue;
				}

				//p_res * c + [max(0,p_res-(n-num)-1); min(p_res, num)] == k
				//find max p_res
				*/

				//cout<<c<<": "<<remk<<endl;

				ll bsfrom = 0;
				ll bsto = p_res;

				ll good = -1;
				while(bsfrom<=bsto){
					ll bsm=(bsfrom+bsto)/2;
					if(bsm*c + max(0ll, bsm-(n-num)-1)<=remk)good=bsm,bsfrom=bsm+1;
					else bsto=bsm-1;
				}
				//cout<<good<<endl;
				if(good!=-1){
					if(good*c+min(good,num)>=remk){
						ans=max(ans,good);
					}
				}
			}
		}
	}

	cout<<ans<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif

	return 0;
}