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


int a[1111111];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	REP(i,n){
		int x;
		scanf("%d",&x);
		a[x]=1;
	}
	const int s = 1000000;
	int num=0;
	vi res;
	for(int i=1;i<=1000000;i++)if(a[i]==1 && a[s-i+1]==0)a[s-i+1]=2;
	else if(a[i]==1 && a[s-i+1]==1)num++;
	num/=2;
	for(int i=1;i<=1000000;i++)if(a[i]==0 && a[s-i+1]==0 && num)a[i]=a[s-i+1]=2,num--;
	for(int i=1;i<=1000000;i++)if(a[i]==2)res.pb(i);
	cout<<res.size()<<endl;
	REP(i,res.size()){
		if(i) printf(" ");
		printf("%d",res[i]);
	}
	puts("");
#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}