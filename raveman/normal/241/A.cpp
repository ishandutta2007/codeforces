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

int m,k;
int d[1111];
int s[1111];

int l[1111];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>m>>k;
	int n = m + 1;
	REP(i,m) scanf("%d",d+i);
	REP(i,m) scanf("%d",s+i);

	for(int i=n;i>=0;i--)
		l[i] = l[i+1] + d[i];

	int curr_f = s[0];
	int curr_p = 0;
	int res = 0;
	int curr_b = s[0];
	while(1){
		if(curr_p == n-1) break;
		if(d[curr_p] <= curr_f) res+=d[curr_p],curr_f-=d[curr_p],curr_p++,curr_b=max(curr_b,s[curr_p]),curr_f+=s[curr_p];
		else res += k, curr_f += curr_b;
	}
	cout<<res<<endl;

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}