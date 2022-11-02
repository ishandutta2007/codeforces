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

int a,b;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>a>>b;
	while(1){
		bool f = 0;
		for(int i=2;i>=0;i--)if(a>=i && b>=(220-100*i)/10){
			a-=i;
			b-=(220-100*i)/10;
			f=1;
			break;
		}
		if(!f){
			puts("Hanako");
			return 0;
		}
		f = 0;
		for(int i=0;i<=2;i++)if(a>=i && b>=(220-100*i)/10){
			a-=i;
			b-=(220-100*i)/10;
			f=1;
			break;
		}
		if(!f){
			puts("Ciel");
			return 0;
		}
	}

	return 0;
}