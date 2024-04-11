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
typedef pair<double,double>	pdd;
typedef vector<int> vi;
typedef vector<ld> vd;
typedef pair<ll,int> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

string s;
int q;
int sum[26][222222];

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>s>>q;
	REP(i,s.size())sum[s[i]-'a'][i]++;
	REP(i,26){
		REP(j,s.size()){
			sum[i][j]=sum[i][j]+(j-1>=0?sum[i][j-1]:0);
		}
	}
	REP(i,q){
		int l,r;
		scanf("%d %d",&l,&r);
		l--,r--;
		int nl=0;
		REP(j,26){
			if(sum[j][r]-(l-1>=0?sum[j][l-1]:0)>0)nl++;
		}
		if(l==r)puts("Yes");
		else if(nl==1) puts("No");
		else if(nl>=3) puts("Yes");
		else if(s[l]==s[r])puts("No");
		else puts("Yes");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}