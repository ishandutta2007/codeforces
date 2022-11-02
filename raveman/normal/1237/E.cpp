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
typedef pair<ll,ll> pl;

#define FOR(i,a,b)		for(int i=(a);i<(b);i++)	
#define REP(i,n)		FOR(i,0,n)
#define SORT(v)			sort((v).begin(),(v).end())
#define UN(v)			SORT(v),(v).erase(unique((v).begin(),(v).end()),(v).end())
#define CL(a,b)			memset(a,b,sizeof a)
#define pb				push_back

const int mod = 998244353;

ll d[1<<20][2][2];

int depth(int n){
	int res=0;
	while(n){
		res++;
		n>>=1;
	}
	return res;
}
ll go(int n,int p,int start){
	if(n<1)return 0;
	if(n==1){
		if(p!=start) return 0;
		return 1;
	}
	if(n==2){
		if(p==start) return 0;
		return 1;
	}
	if(d[n][p][start]!=-1)return d[n][p][start];
	ll res = 0;
	FOR(n1,1,n){
		if((start+n1)%2!=p)continue;
		if(n!=4 && n!=5 && depth(n1)!=depth(n-n1-1))continue;
		res = (res + 
		go(n1,((start+n1)%2)^1,start)*
		go(n-n1-1,(start+n1)%2,(start+n1+1)%2))%mod;
	}
	return d[n][p][start]=res;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	int n;
	cin>>n;
	int t = 1;
	while(t<=n){
		if(t==n || t+1==n){cout<<1<<endl;return 0;}
		t+=1;
		if(t%2==0)t*=2;
		else t=t*2-1;
	}
	cout<<0<<endl;
	return 0;
	CL(d,-1);
	for(int i=1;i<=100;i++){
		cout<<i<<": " <<(go(i,0,1)+go(i,1,1))%mod<<endl;
	}


#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}