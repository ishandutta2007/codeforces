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

int x[3],y[3];

bool good(){
	REP(i,3)REP(j,3)REP(k,3)if(i!=j && i!=k && j!=k){
		int a = (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
		int b = (x[k]-x[j])*(x[k]-x[j])+(y[k]-y[j])*(y[k]-y[j]);
		int c = (x[i]-x[k])*(x[i]-x[k])+(y[i]-y[k])*(y[i]-y[k]);
		if(a&&b&&c&&a==b+c) return 1;
	}
	return 0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	REP(i,3) cin>>x[i]>>y[i];
	if(good()){
		puts("RIGHT");
		return 0;
	}
	REP(i,3){
		FOR(dx,-1,2)FOR(dy,-1,2)if(abs(dx)+abs(dy)==1){
			x[i]+=dx,y[i]+=dy;
			if(good()){
				puts("ALMOST");
				return 0;
			}
			x[i]-=dx,y[i]-=dy;
		}
	}
	puts("NEITHER");

	return 0;
}