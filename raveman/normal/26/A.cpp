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

	int n;

	cin>>n;
	vi p;
	int r=0;
	for(int i=2;i<=n;i++){
		bool pp = 1;
		for(int j=2;j*j<=i;j++)if(i%j==0) pp=0;
		if(pp) p.pb(i);
	}
	for(int i=2;i<=n;i++){
		int num=0;
		REP(j,p.size()) if(i%p[j]==0) num++;
		if(num==2) r++;
	}
	cout<<r<<endl;

	return 0;
}