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
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

int n,k;
int a[333333];
int am[333333];
ll res = 0;
int u1[1111111];
int c1[1111111];
int u2[1111111];
int c2[1111111];
int now;

void solve(int from,int to){
	if(from>=to)return;

	int middle = (from+to)/2;

	solve(from,middle);
	solve(middle+1,to);

	int p1 = middle;
	int p2 = middle+1;


	now++;
	int sum1 = 0;
	int sum2 = 0;
	while(p1>=from || p2<=to){
		int mx = 1e9;
		if(p1>=from)mx=min(mx,a[p1]);
		if(p2<=to)mx=min(mx,a[p2]);
		int mxm = mx % k;

		while(p1>=from && a[p1]<=mx){
			sum1 += am[p1];
			if(sum1>=k)sum1-=k;

			int t = mxm-sum1;if(t<0)t+=k;

			if(u2[t]!=now){u2[t]=now;c2[t]=0;}
			res += c2[t];

			if(u1[sum1] != now){u1[sum1]=now;c1[sum1]=0;}
			c1[sum1]++;

			p1--;			
		}
		while(p2<=to && a[p2]<=mx){
			sum2 += am[p2];
			if(sum2>=k) sum2-=k;

			int t = mxm-sum2;if(t<0)t+=k;

			if(u1[t]!=now){u1[t]=now;c1[t]=0;}
			res += c1[t];

			if (u2[sum2]!=now){u2[sum2]=now;c2[sum2]=0;}
			c2[sum2]++;

			p2++;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>k;
	REP(i,n)scanf("%d",a+i),am[i]=a[i]%k;

	solve(0,n-1);

	cout<<res<<endl;
	
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}