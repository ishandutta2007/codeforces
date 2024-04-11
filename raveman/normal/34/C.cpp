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
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())
 
string s;

int main(){
#ifdef LocalHost
    freopen("input.txt","r",stdin);
  //  freopen("output.txt","w",stdout);
#endif

	getline(cin,s);
	REP(i,s.size()) if(s[i]==',') s[i]=' ';
	stringstream ss(s);
	vi v;
	int x;
	while(ss>>x)v.pb(x);
	UN(v);
	int pos =0 ;
	bool f =1;
	for(;pos<v.size();){
		int j=pos;
		while(j<v.size() && v[j]-v[pos]==j-pos) j++;
		if(!f) cout<<',';
		f=0;
		if(j==pos+1) cout<<v[pos];
		else cout<<v[pos]<<'-'<<v[j-1];
		
		pos=j;
	}
	puts("");

	return 0;
}