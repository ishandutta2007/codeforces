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

string s;
int sum[1111111];
int n1[1111111];
int w[1<<21];

void setVal(int pos,int val){
	pos += (1<<20);
	while(pos){
		w[pos] = min(w[pos], val);
		pos>>=1;
	}
}

int getMin(int p1,int p2){
	int res = 1e9;
	p1 += (1<<20);
	p2 += (1<<20);
	while(p1<=p2){
		res=min(res,w[p1]);
		res=min(res,w[p2]);
		p1=(p1+1)/2;
		p2=(p2-1)/2;
	}
	return res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	getline(cin,s);
	REP(i,s.size()){
		sum[i+1]=sum[i] + (s[i]=='('?1:-1);
		n1[i+1]=n1[i] + (s[i]==')'?1:0);
	}
	REP(i,1<<21) w[i]=1e9;
	REP(i,s.size()+1) setVal(i,sum[i]);
	int n;
	cin>>n;
	REP(i,n){
		int l,r;
		scanf("%d %d",&l,&r);
		int c = n1[r] - n1[l-1];
		int val = getMin(l,r);
		c-=max(0,sum[l-1]-val);
		c=max(c,0);
		
		printf("%d\n",c*2);
	}
#ifdef LocalHost
	//printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}