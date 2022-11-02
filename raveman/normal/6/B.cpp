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

int n,m;
char c;
string s[111];

set<char> w;

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	cin>>n>>m>>c;
	REP(i,n) cin>>s[i];
	REP(i,n){
		REP(j,m) if(s[i][j]==c){
			if(j && s[i][j-1]!='.' && s[i][j-1]!=c) w.insert(s[i][j-1]);
			if(j+1<m && s[i][j+1]!='.' && s[i][j+1]!=c) w.insert(s[i][j+1]);
			if(i && s[i-1][j]!='.' && s[i-1][j]!=c) w.insert(s[i-1][j]);
			if(i+1<n && s[i+1][j]!='.' && s[i+1][j]!=c) w.insert(s[i+1][j]);
		}
	}
	cout<<w.size()<<endl;
	return 0;
}