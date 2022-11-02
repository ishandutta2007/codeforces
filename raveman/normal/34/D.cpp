#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())
 
int p[111111];
int n,r1,r2;
vi s[111111];

void dfs(int ver,int par=-1){
	p[ver]=par;
	REP(i,s[ver].size())
		if(s[ver][i]!=par)
			dfs(s[ver][i],ver);
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
#endif

	cin>>n>>r1>>r2;r1--,r2--;
	REP(i,n){
		if(i==r1) continue;
		int x;
		scanf("%d",&x);x--;
		s[x].pb(i);
		s[i].pb(x);
	}
	dfs(r2);
	bool f =0;
	REP(i,n){
		if(i==r2) continue;
		if(f) printf(" ");
		f=1;
		printf("%d",p[i]+1);		
	}
	puts("");


	return 0;
}