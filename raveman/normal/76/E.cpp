#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
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
map<int,int> X,Y;

ll solve(map<int,int> &m){
	ll res = 0;
	vector<pii> v;
	for(map<int,int>::iterator it = m.begin();it!=m.end();it++)
		v.pb(*it);
	ll sum = 0;
	REP(i,v.size()){
		res += v[i].first * ll(v[i].first) * v[i].second * (n - v[i].second);
		res += (- 2) * v[i].first * sum * v[i].second;
		sum += v[i].first * ll(v[i].second);
	}
	
	return res;
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
#endif

	cin>>n;
	REP(i,n){
		int x,y;
		scanf("%d %d",&x,&y);
		X[x]++;
		Y[y]++;
	}
	ll res = solve(X)+ solve(Y);
	cout<<res<<endl;
	return 0;
}