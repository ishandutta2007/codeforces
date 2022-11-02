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

int n;
int r[1<<20];

int sm[20][1<<20];
int sM[20][1<<20];

void setMinVal(int* s,int pos, int val){
	pos+=(1<<19);
	while(pos){
		s[pos]=min(s[pos],val);
		pos>>=1;
	}
}

void setMaxVal(int* s,int pos, int val){
	pos+=(1<<19);
	while(pos){
		s[pos]=max(s[pos],val);
		pos>>=1;
	}
}

int getMinVal(int* s,int p1,int p2){
	p1+=(1<<19);
	p2+=(1<<19);
	int mv = 1e9;
	while(p1<=p2){
		mv=min(mv,s[p1]);
		mv=min(mv,s[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return mv;
}

int getMaxVal(int* s,int p1,int p2){
	p1+=(1<<19);
	p2+=(1<<19);
	int mv = 0;
	while(p1<=p2){
		mv=max(mv,s[p1]);
		mv=max(mv,s[p2]);
		p1=(p1+1)>>1;
		p2=(p2-1)>>1;
	}
	return mv;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n;
	if(n==1){
		puts("0");
		return 0;
	}
	REP(i,n)scanf("%d",r+i),r[i+n]=r[i+2*n]=r[i+3*n]=r[i+4*n]=r[i];
	//[2n...3n)
	REP(i,20)REP(j,1<<20)sm[i][j]=1<<20;
	REP(i,5*n)setMinVal(sm[0],i,i-r[i]);
	REP(i,5*n)setMaxVal(sM[0],i,i+r[i]);
	FOR(i,1,20){
		REP(j,5*n){
			int from = sm[i-1][j+(1<<19)];
			int to = sM[i-1][j+(1<<19)];
			from=max(from,0);
			to=min(to,5*n-1);
			int mv = getMinVal(sm[i-1],from,to);
			int MV = getMaxVal(sM[i-1],from,to);

			setMinVal(sm[i],j,mv);
			setMaxVal(sM[i],j,MV);
		}
	}
	REP(i,n){
		if(i)printf(" ");

		int from = 2*n+i;
		int to = 2*n+i;
		int res = 0;
		for(int j=19;j>=0;j--){
			int mv = getMinVal(sm[j],from,to);
			int MV = getMaxVal(sM[j],from,to);
			if(MV-mv+1<n){
				res += (1<<j);
				from=mv;
				to=MV;
			}
		}
		printf("%d",res+1);
	}
	puts("");

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}