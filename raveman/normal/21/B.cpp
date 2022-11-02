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

double a[2][3];

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	REP(i,2)REP(j,3) cin>>a[i][j];
	if(a[0][1] || a[1][1]) swap(a[0][0],a[0][1]),swap(a[1][0],a[1][1]);
	if(!a[0][0] && !a[1][0]){
		if(a[0][2] || a[1][2]) puts("0");
		else puts("-1");
		return 0;
	}
	REP(i,2){
		int pos = -1;
		FOR(j,i,2) if(fabs(a[j][i])>1e-6) pos=i;
		if(pos==-1){
			if(fabs(a[1][2])>1e-6) puts("0");
			else puts("-1");
			return 0;
		}
		REP(j,3) swap(a[pos][j],a[i][j]);
		double k = a[i][i];
		REP(j,3) a[i][j]/=k;
		FOR(j,i+1,2){
			k = a[j][i];
			REP(q,3) a[j][q]-=k*a[i][q];
		}
	}
	puts("1");
	return 0;
}