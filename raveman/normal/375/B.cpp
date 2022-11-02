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

int n,m;
char s[5555][5555];
int nx[5555][5555];
int a[5555];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	gets(s[0]);
	REP(i,n)gets(s[i]);
	REP(i,n){
		nx[i][m]=m;
		for(int j=m-1;j>=0;j--){
			if(s[i][j]=='0') nx[i][j]=j;
			else nx[i][j]=nx[i][j+1];
		}
	}
	int res=0;
	REP(i,m){
		CL(a,0);
		REP(j,n)a[nx[j][i]-i]++;
		int num = 0;
		for(int j=m;j>=0;j--){
			num+=a[j];
			res=max(res,num*j);
		}
	}
	cout<<res<<endl;
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}