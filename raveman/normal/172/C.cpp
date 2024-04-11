#pragma comment(linker, "/STACK:65777216")
 
#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <complex>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<list>

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
pii s[111111];
int res[111111];

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	cin>>n>>m;
	REP(i,n) scanf("%d %d",&s[i].first,&s[i].second);
	sort(s,s+n);

	int pos = 0;
	int start=0;
	for(;pos<n;){
		vector<pii> t;
		while(pos<n && t.size()<m) t.pb(pii(s[pos].second,pos)),start=max(start,s[pos].first),pos++;
		SORT(t);
		for(int i=0;i<t.size();){
			start += t[i].first - (i?t[i-1].first:0);
			int j=i;
			while(j<t.size() && t[i].first==t[j].first) res[t[j].second]=start,j++;
			start += 1 + (j-i)/2;
			i=j;
		}
		start += t.back().first;
	}
	REP(i,n){
		if(i) printf(" ");
		printf("%d",res[i]);
	}
	puts("");

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
    return 0;
}