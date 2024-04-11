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

int n,m;
int a[555],x[555],y[555];

map<int,int> c;
bool good(int s){
	vi need;
	for(int i=s;i<n;i+=2){
		int d = abs(x[i]-x[(i+n-1)%n])+abs(y[i]-y[(i+n-1)%n]) + abs(x[i]-x[i+1])+abs(y[i]-y[i+1]);
		need.pb(d);
	}
	c.clear();
	REP(i,m) c[a[i]]++;
	REP(i,need.size()){
		int d = need[i];
		if(c[d]==0) return 0;
		c[d]--;
	}
	puts("YES");
	REP(i,n){
		if(i) printf(" ");
		if((i-s)%2) printf("-1");
		else{
			int d = need[(i-s)/2];
			REP(j,m)if(a[j]==d){
				a[j]=-1;
				printf("%d",j+1);
				break;
			}
		}
	}
	puts("");
	return 1;
}

int main(){	
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif
	cin>>n>>m;
	REP(i,n) scanf("%d %d",x+i,y+i);
	x[n]=x[0];y[n]=y[0];
	REP(i,m) scanf("%d",a+i);
	REP(i,2){
		if(good(i)){
			return 0;
		}
	}
	puts("NO");
	return 0;
}