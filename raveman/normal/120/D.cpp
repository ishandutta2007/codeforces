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

int n,m;
int a[55][55];
int s[55][55];
int c[3],b[3];

int main(){
	freopen("input.txt","r",stdin);
#ifndef LocalHost
	freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n)REP(j,m) cin>>a[i][j];
	REP(i,n)REP(j,m) s[i][j]=a[i][j]+(i?s[i-1][j]:0)+(j?s[i][j-1]:0)-(i&&j?s[i-1][j-1]:0);
	REP(i,3) cin>>c[i];
	sort(c,c+3);
	int res = 0;
	FOR(i,1,n)FOR(j,1,n)if(i+j<n){
		int k = n-i-j;
		b[0] = s[i-1][m-1];
		b[1] = s[i+j-1][m-1] - b[0];
		b[2] = s[n-1][m-1] - b[1]-b[0];
		sort(b,b+3);
		if(b[0]==c[0] && b[1]==c[1] && b[2]==c[2]) res++;
	}
	FOR(i,1,m)FOR(j,1,m)if(i+j<m){
		b[0] = s[n-1][i-1];//i-1][m-1];
		b[1] = s[n-1][i+j-1] - b[0];
		b[2] = s[n-1][m-1] - b[1]-b[0];
		sort(b,b+3);
		
		if(b[0]==c[0] && b[1]==c[1] && b[2]==c[2]) res++;
	}
	cout<<res<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}