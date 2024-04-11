#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,a,b,A,B;
int x[111111];
int s[6];

ll solve2(int a,int b,ll s1,ll s2,int A,int B){
	REP(i,6){
		int t = min(a,s[i]);
		s1 += t * i;
		s2 += (s[i] - t) * i;
		a -= t;
	}
	return s1 * B + s2 * A;
}

ll solve(int a,int b,ll s1=0,ll s2=0){
	if(a<0 || b<0) return -1;
	ll res = max(solve2(a,b,s1,s2,A,B),solve2(b,a,s2,s1,B,A));
	return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n>>a>>b;
	A=a;B=b;
	REP(i,n) scanf("%d",x+i),s[x[i]]++;
	ll best = solve(a,b);
	int s1=0,s2=0;
	REP(i,n){
		if(i)printf(" ");
		s1+=x[i];
		a--;s[x[i]]--;
		ll t = solve(a,b,s1,s2);
		if(t==best) printf("1");
		else{
			s1-=x[i];a++;s[x[i]]++;
			s2+=x[i];b--;s[x[i]]--;
			printf("2");
		}
	}
	puts("");
	return 0;
}