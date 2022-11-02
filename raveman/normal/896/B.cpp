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

int a[1111];
int n,m,c;

bool good(){
	if(a[0]==-1)return 0;
	FOR(i,1,n)if(a[i-1]>a[i])return 0;
	return 1;	
}

void backInsert(int x){
	for(int i=n-1;i>=0;i--){
		if(a[i]==-1 || a[i]<x){
			a[i]=x;
			cout<<i+1<<endl;
			return;
		}
	}
}
void frontInsert(int x){
	REP(i,n){
		if(a[i]==-1 || a[i]>x){
			a[i]=x;
			cout<<i+1<<endl;
			return;
		}
	}
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>c;
	CL(a,-1);
	REP(i,m){
		if(good())break;
		int x;
		cin>>x;
		if(x>c/2)backInsert(x);
		else frontInsert(x);
	}

#ifdef LocalHost
	printf("TIME: %.3lf\n",ld(clock())/CLOCKS_PER_SEC);
#endif
	return 0;
}