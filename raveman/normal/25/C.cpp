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

int a[333][333];

int main(){
#ifdef LocalHost
	freopen("input.txt","r",stdin);
#endif

	int n;
	cin>>n;
	REP(i,n)REP(j,n)scanf("%d",&a[i][j]);
	int k;
	cin>>k;
	REP(i,k){
		if(i) printf(" ");
		int x,y,z;
		cin>>x>>y>>z;x--,y--;

		if(a[x][y]>z){
			a[x][y]=a[y][x]=z;
			REP(c,n)REP(b,n)
				a[c][b]=min(a[c][b],a[c][x]+z+a[y][b]),
				a[c][b]=min(a[c][b],a[c][y]+z+a[x][b]);
		}
		ll sum=0;
		REP(c,n)REP(b,n)
			sum+=a[c][b];
		cout<<sum/2;
	}
	puts("");
	return 0;
}