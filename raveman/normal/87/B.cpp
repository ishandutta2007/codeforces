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

map<string,string> m;

string get(string s){
	int a = 0,z=0;
	while(a<s.size() && s[a]=='&') a++;
	s.erase(s.begin(),s.begin()+a);
	while(s.size() && s[s.size()-1]=='*')z++,s.erase(s.end()-1);
	if(!m.count(s)) return "errtype";
	s = m[s];
	if(s=="errtype") return s;
	while(z) s+="*",z--;
	while(a){
		if(s.size()==0 || s[s.size()-1]!='*') return "errtype";
		a--;
		s.erase(s.end()-1);
	}
	return s;
}

int main(){ 
#ifdef LocalHost
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif

	m["void"] = "void";

	int n;
	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		if(s=="typeof"){
			cin>>s;
			cout<<get(s)<<endl;
		}else if(s=="typedef"){
			string a,b;
			cin>>a>>b;
			m[b]  = get(a);
		}
	}

#ifdef LocalHost
	cout<<endl<<endl<<"TIME: "<<clock()<<endl;
#endif
	return 0;
}