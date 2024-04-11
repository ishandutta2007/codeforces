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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

int d[11][55][55];
int f[11][55][55];

int n,a,b;
int h[11];

int go(int n,int num,int num2){
	if(n==0 && (num || h[0] >= num2*b)) return 1000000000;
	if(n==0) return 0;
	
	if(d[n][num][num2]!=-1) return d[n][num][num2];
	int res = 1000000000;
	REP(i,17){
		int t =  ((i+num2) * b + num * a >  h[n] ? go(n-1, i, num) : 1000000000) + num;
		if(t<res)res=t,f[n][num][num2]=i;
	}
	return d[n][num][num2]=res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	CL(d,-1);
	cin>>n>>a>>b;
	REP(i,n) cin>>h[i];
	cout<<go(n-1,0, 0)<<endl;
	n--; b=0;a=0;
	bool ff = 1;
	while(n){
		REP(i,f[n][b][a]){
			
			if(!ff) cout<<' ';
			ff=0;
			cout<<n;

		}
		int t = f[n][b][a];
		a=b;
		b=t;
		n--;
	}
	puts("");
	return 0;
}