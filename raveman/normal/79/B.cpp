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

int x[1111];
int y[1111];

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	int n,m,k,t;
	cin>>n>>m>>k>>t;
	REP(i,k) cin>>x[i]>>y[i];
	REP(i,t){
		int X,Y;
		cin>>X>>Y;
		int num = (X-1)*m + Y-1;
		REP(j,k) if(x[j] < X || x[j]==X && y[j]<Y) num--;
		else if(x[j]==X && y[j]==Y) num = -1;
		if(num<0) puts("Waste");
		else{
			num %=3;
			if(num==0) puts("Carrots");
			else if(num==1) puts("Kiwis");
			else puts("Grapes");
		}
	}
	return 0;
}