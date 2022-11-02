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
string s[111];
string t;
char c;

bool u[111];

bool comp(string s1,string s2){
	REP(i,s1.size()) if(tolower(s1[i])!=tolower(s2[i])) return 0;
	return 1;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
//	freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n) cin>>s[i];
	cin>>t;
	cin>>c;

	REP(i,n) REP(j,int(t.size()) - int(s[i].size())+1)
		if(comp(t.substr(j,s[i].size()),s[i]))
			REP(k,s[i].size()) u[j+k] = true;

	REP(i,t.size()) if(u[i]){
		char cc = tolower(t[i]);
		if(cc!=c) cc = c;
		else{
			if(cc=='a') cc='b';
			else cc='a';
		}
		t[i] = isupper(t[i]) ? toupper(cc) : cc;
	}

	cout<<t<<endl;

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}