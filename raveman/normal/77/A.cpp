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

int n;
bool a[11][11];

map<string,int> Q;
int id(string s){
	if(Q.count(s)) return Q[s];
	int x = Q.size();
	return Q[s]=x;
}

int add(vi v){
	int r = 0;
	REP(i,v.size()) REP(j,v.size()) 
		r+=a[v[i]][v[j]];
	return r;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif
	cin>>n;
	REP(i,n){
		string s1,s2,s3;
		cin>>s1>>s2>>s3;
		a[id(s1)][id(s3)]=1;
	}
	int a,b,c;
	cin>>a>>b>>c;
	int best = -1;
	int sm = -1;
	REP(mask,3*3*3*3*3*3*3){
		vi v[3];
		int t = mask;
		REP(j,7){
			v[t%3].pb(j);
			t/=3;
		}
		if(v[0].size() && v[1].size() && v[2].size()){
			int c1 = a / v[0].size();
			int c2 = b / v[1].size();
			int c3 = c / v[2].size();

			int m = min(min(c1,c2),c3);
			int M = max(max(c1,c2),c3);

			int total=add(v[0])+add(v[1])+add(v[2]);

			if(best==-1 || M-m < best || M-m==best && sm < total)
				best = M-m,sm = total;
		}
	}
	cout<<best<<' '<<sm<<endl;
	return 0;
}