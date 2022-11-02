#include <iostream>
#include<string.h>
#include <cstdio>

using namespace std;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 

int n;
int m;
int r[21][1<<20];

const int inf = 1011111111;

char _s[22];

int getMax(int m1,int m2){
	for(int i=m;i>=0;i--){
		if(m1%(1<<i) == (m2>>(m-i)))
			return i;
	}
	return 0;
}

int main(){ 
	REP(i,21) REP(j,1<<20) r[i][j]=inf;
	cin>>n;
	gets(_s);
	r[0][0] = 0;
	int prev = 0, b = 0;
	REP(i,n){
		gets(_s);
		if(i==0) m = strlen(_s);
		int a = 0;
		REP(j,m) if(_s[j]=='1') a|=(1<<(m-1-j));

		int len = getMax(prev, a);
		if(i==0) len = 0;

		int q = inf;
		REP(j,m+1) q=min(q,b+r[j][a>>(m-j)]+(m-j));
		b += (m-len);

		if(i) REP(j,m+1) r[j][prev%(1<<j)]=min(r[j][prev%(1<<j)],q-b);
		prev = a;		
	}
	int res = inf;
	REP(i,m+1)REP(j,1<<i) res = min(res, r[i][j]);
	cout<<res+b<<endl;
	return 0;
}