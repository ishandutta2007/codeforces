#pragma comment(linker, "/STACK:136777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
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

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	int n,m,k;
	cin>>n>>m>>k;
	if(n+k<m) puts("0");
	else if(k>=m) puts("1");
	else{
		double res =1 ;
		for(int i=n+1;i<=n+k+1;i++)
			res/=i;
		for(int i=m-k-1+1;i<=m;i++)
			res*=i;
		printf("%.4lf\n",1-res);
	}
	return 0;
}