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
#define CL(a,b)				memset(a,b,sizeof a)
#define pb				push_back

int r[4000][100][100][2];
int a[4444];
int s[4444];
int n;

int solve(int from,int num_more,int step,int type){
	int to = n - 1 - from - num_more + (type?step:0);
	int num = to - from + 1;
	if(num < step) return 0;
	if(r[from][num_more][step][type]!=-1)return r[from][num_more][step][type];
	int ans;
	if (type == 0){
		ans = s[from+step-1] - (from-1>=0?s[from-1]:0) + solve(from+step,num_more,step,1);
		if(num >= step + 1){
			ans = max(ans, s[from+step+1-1]-(from-1>=0?s[from-1]:0) + solve(from+step+1,num_more,step+1,1));
		}
	}else{
		ans = -(s[to] - (to-step>=0?s[to-step]:0)) + solve(from,num_more,step,0);
		if(num >= step + 1){
			ans = min(ans, -(s[to]-(to-step-1>=0?s[to-step-1]:0)) + solve(from,num_more+1,step+1,0));
		}
	}
	return r[from][num_more][step][type]=ans;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;REP(i,n)scanf("%d",a+i);
	CL(r,-1);

	//n=4000;REP(i,n)a[i]=rand()%100;

	REP(i,n){
		s[i]=a[i];
		if(i)s[i]+=s[i-1];
	}
	cout<<solve(0,0,1,0)<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}