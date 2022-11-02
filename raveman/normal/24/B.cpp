#pragma comment(linker, "/STACK:836777216")

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

int p(int c){
	int x[] = {25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
	if(c<10) return x[c];
	return 0;
}
map<string,int> a;
map<string,vi> m;


string solve1(){
	vector<pair<pair<int,vi>,string > > v;
	for(map<string,int>::iterator it = a.begin();it!=a.end();it++)
		v.pb(make_pair( make_pair(it->second,m[it->first]),it->first));
	SORT(v);
	return v.back().second;
}

string solve2(){
	vector<pair<pair<pii,vi>,string > > v;
	for(map<string,int>::iterator it = a.begin();it!=a.end();it++)
		v.pb(make_pair( make_pair(pii(m[it->first][0],it->second),m[it->first]),it->first));
	SORT(v);
	return v.back().second;
}

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	int t;
	cin>>t;
	REP(i,t){
		int n;
		cin>>n;
		REP(j,n){
			string s;
			cin>>s;
			a[s]+=p(j);
			if(m[s].size()<=j) m[s].resize(j+1);
			m[s][j]++;
		}
	}
		cout<<solve1()<<endl;
		cout<<solve2()<<endl;
	return 0;
}