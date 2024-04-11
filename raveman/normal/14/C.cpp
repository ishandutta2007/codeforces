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

int x[4],y[4],X[4],Y[4];

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	REP(i,4) cin>>x[i]>>y[i]>>X[i]>>Y[i];

	REP(i,4) if(x[i]==X[i] && y[i]!=Y[i])
		REP(j,4) if(j!=i && x[j]==X[j] && x[j] > x[i])
			REP(k,4) if(y[k]==Y[k])
				REP(z,4) if(z!=k && y[z]==Y[z] && y[z] > y[k]){
					if(min(y[i],Y[i])!=min(y[j],Y[j])) continue;
					if(max(y[i],Y[i])!=max(y[j],Y[j])) continue;

					if(min(x[k],X[k])!=min(x[k],X[k])) continue;
					if(max(x[k],X[k])!=max(x[k],X[k])) continue;

					if(x[i] != min(x[k], X[k])) continue;
					if(x[j] != max(x[k], X[k])) continue;

					if(y[k] != min(y[i], Y[i])) continue;
					if(y[z] != max(y[i], Y[i])) continue;

					puts("YES");
					return 0;
				}
	puts("NO");
	
	return 0;
}