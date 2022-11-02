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

char s[1<<20],a[1<<20],b[1<<20];
int n,k;

bool u[1<<20][2][2];
int mp[26];

bool go(int pos,int mask,bool eqa, bool eqb){
	if(u[pos][eqa][eqb]) return 0;
	u[pos][eqa][eqb]=1;
	if(pos==n){
		REP(i,k)if(mp[i]==-1){
			REP(j,k)if(!(mask&(1<<j))){
				mask|=(1<<j);
				mp[i]=j;
				break;
			}
		}
		puts("YES");
		REP(i,k)printf("%c",'a'+mp[i]);
		puts("");
		return true;
	}
	int l = s[pos]-'a';
	if(mp[l]==-1){
		int l1 = (eqa?a[pos]-'a':0);
		int l2 = (eqb?b[pos]-'a':k-1);
		if(l1>l2) return 0;
		FOR(w,l1,l2+1){
			if(mask&(1<<w)) continue;
			mp[l]=w;
			if(go(pos+1,mask|(1<<w),eqa&(w==a[pos]-'a'),eqb&(w==b[pos]-'a'))) return true;
		}
		mp[l]=-1;
		return 0;
	}else{
		int l1 = (eqa?a[pos]-'a':0);
		int l2 = (eqb?b[pos]-'a':k-1);
		if(eqa && mp[l]<a[pos]-'a') return 0;
		if(eqb && mp[l]>b[pos]-'a') return 0;
		if(go(pos+1,mask,eqa&(mp[l]==a[pos]-'a'),eqb&(mp[l]==b[pos]-'a'))) return true;
		return 0;
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		scanf("%d %s %s %s",&k,s,a,b);
		n=strlen(s);
		REP(i,n+1)REP(j1,2)REP(j2,2)u[i][j1][j2]=0;
		REP(i,k)mp[i]=-1;
		if(!go(0,0,1,1)) puts("NO");
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}