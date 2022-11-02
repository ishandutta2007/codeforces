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

int n;
int a[555555];
bool u[555555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n)scanf("%d",a+i);
	u[0]=u[n-1]=1;
	FOR(i,1,n)if(a[i]==a[i-1])u[i]=u[i-1]=1;
	int res = 0;

	FOR(i,1,n)if(u[i] && !u[i-1]){
		int j = i - 1;
		while(!u[j]) j--;
		int len = i - j  - 1;
		if(len%2==0){
			res=max(res,len/2);
			FOR(k,j+1,j+1+len/2)a[k]=a[j];
			FOR(k,j+1+len/2,i)a[k]=a[i];
		}else{
			res=max(res,(len+1)/2);
			FOR(k,j,i)a[k]=a[i];
		}
	}

	cout<<res<<endl;
	REP(i,n){
		if(i)printf(" ");
		printf("%d",a[i]);
	}
	puts("");


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}