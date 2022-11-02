#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include<complex>
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
typedef pair<pii,int> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

ll solve(vector<ll> v, vector<char> c){
	if(v.size()==1) return v[0];
	ll ans = 1000000000000000000ll;
	REP(i,v.size()) REP(j,i){
		vector<ll> t = v;
		t.erase(t.begin() + i);
		t.erase(t.begin() + j);

		if(c[0] == '+') t.pb(v[i] + v[j]);
		else t.pb(v[i] * v[j]);

		vector<char> cc=c;
		cc.erase(cc.begin());

		ans = min(ans, solve(t,cc));
	}
	return ans;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	vector<ll> v(4);
	REP(i,4)cin>>v[i];
	vector<char> c(3);
	REP(i,3) cin>>c[i];
	cout<<solve(v,c)<<endl;
    return 0;
}