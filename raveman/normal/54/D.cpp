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

int n,k;
string s;
string res;
string b;

int move[111][33];

bool u[111][111];

bool go(int beg,int pref){
	if(beg>=s.size()){
		if(b[beg-s.size()]=='1' && pref!=s.size()) return 0;
		if(b[beg-s.size()]=='0' && pref==s.size()) return 0;
	}
	if(beg == n) return 1;

	if(u[beg][pref]) return 0;
	REP(i,k){
		if(go(beg+1,move[pref][i])){
			res.pb(char('a'+i));
			return 1;
		}
	}
	return u[beg][pref]=1,0;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>n>>k>>s>>b;
	REP(i,s.size()+1)REP(j,k){
		string t = s.substr(0,i);
		t.pb(char('a'+j));
		while(t.size() > s.size()) t.erase(t.begin());
		while(t != s.substr(0, t.size())) t.erase(t.begin());
		move[i][j] = t.size();
	}
	if(go(0,0)) reverse(res.begin(),res.end()),cout<<res<<endl;
	else puts("No solution");
	return 0;
}