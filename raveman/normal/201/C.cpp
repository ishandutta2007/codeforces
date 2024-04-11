#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <cassert>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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

int n;
int a[111111];
ll  s[111111];
ll e[111111];
ll e2[111111];
int c[111111];

ll ms[111111];
ll ms2[111111];

ll clever(){
	ll sum = 0;
	FOR(i,1,n){
		ms[i] = ms[i-1] + a[i-1];
		if(a[i-1]%2==0) ms[i]--;
		sum += a[i-1];
		if(a[i-1]%2) sum--;
		if(a[i-1]==1) sum = 0;
		ms[i] = max(ms[i], sum);
	}
	ms2[n-1]=0;
	sum = 0;
	for(int i=n-2;i>=0;i--){
		ms2[i] = ms2[i+1] + a[i];
		if(a[i]%2==0) ms2[i]--;
		sum += a[i];
		if(a[i]%2) sum--;
		if(a[i]==1) sum = 0;
		ms2[i] = max(ms2[i], sum);
	}
	ll best = 0;
	REP(i,n) best=max(best,ms[i]+ms2[i]);
	return best;
}

ll brute(){
	ll best = 0;
	REP(start,n)FOR(end,start,n){
		REP(i,n-1){
			c[i] = a[i];
			if(i<start){
				if(c[i]%2) c[i]--;
			}else if(i<end){
				if(c[i]%2==0) c[i]--;
			}else{
				if(c[i]%2) c[i]--;
			}
		}
		ll t = 0;
		FOR(i, start,end) t += c[i];
		FOR(i,end,n-1){
			t+=c[i];
			if(c[i]==0) break;
		}
		for(int i=start-1;i>=0;i--){
			t+=c[i];
			if(c[i]==0) break;
		}
		best=max(best,t);
	}
	return best;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n;
	REP(i,n-1) scanf("%d",&a[i]);
	cout<<clever()<<endl;

#ifdef LocalHost
	cerr<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}