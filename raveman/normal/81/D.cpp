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
int a[55];
int d[1111];

bool rec(int i){
	if(i==n) return 1;
	REP(j,m)if(d[(i+1)%n]!=j && d[(i+n-1)%n]!=j)if(a[j]){
		a[j]--;
		d[i]=j;
		if(rec(i+1)) return 1;
		d[i]=-1;
		a[j]++;
	}
	return 0;		
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	cin>>n>>m;
	int sum=0;
	REP(i,m) scanf("%d",a+i),sum+=a[i];
	if(sum<n){
		puts("-1");
		return 0;
	}
	CL(d,-1);
	REP(i,n){
		if(n-i==3) break;
		REP(j,m)if(d[(i+1)%n]!=j && d[(i+n-1)%n]!=j)if(a[j]){
			d[i] = j;a[j]--;

			int mx = 0;
			REP(k,m) if(a[k] > a[mx]) mx = k;
			
			int l = n - i - 1;

			int k = n - i - 1;
			if(d[i] == mx) k--;
			if(d[0] == mx) k--;
			k=(k+1)/2;

			l-=k;

			if(i==18 && j==0)
				i=i;

			if(sum-(i+1) - a[mx] < l){
				a[j]++;
				d[i] = -1;
			}else break;
		}
		if(d[i]==-1){
			puts("-1");
			return 0;
		}
		//cout<<d[i]+1<<' ';
	}
	if(!rec(n-3)){
		puts("-1");
		return 0;
	}
	//puts("");
	REP(i,n){
		if(i)printf(" ");
		printf("%d",d[i]+1);
	}
	puts("");
	return 0;
}