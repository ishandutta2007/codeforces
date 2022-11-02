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

double a[20][20];
int n;
double r[1<<18][20];

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) REP(j,n) cin>>a[i][j];

	FOR(i,1,1<<n){
		if(i&(i-1)){
			int num = 0;
			REP(j,n)if(i&(1<<j)) num++;
			num *= (num-1); num /= 2;

			REP(j,n)if(i&(1<<j))
				FOR(k,j+1,n)if(i&(1<<k)){
					REP(q,n) r[i][q] += a[j][k] * r[i^(1<<k)][q], r[i][q] += a[k][j] * r[i^(1<<j)][q];
				}

			REP(j,n) r[i][j] /= num;
		}else{
			REP(j,n)if(i&(1<<j)) r[i][j]=1;
		}		
	}
	REP(i,n){
		if(i) printf(" ");
		printf("%.6lf",r[(1<<n)-1][i]);
	}
	puts("");
	return 0;
}