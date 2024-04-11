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

string s;

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
	getline(cin,s);
	for(int i=int(s.size())-1;i>=0;i--)if(s[i]==' ' && (i+1==s.size() || s[i+1]==' '))
		s.erase(s.begin()+i+1);
	for(int i=int(s.size())-1;i>=0;i--)if(s[i]==' '){
		if(i && i+1<s.size() && isdigit(s[i-1]) && isdigit(s[i+1])) continue;
		s.erase(s.begin()+i);
	}
	while(s.size() && s[0]==' ') s.erase(s.begin());
	for(int i=int(s.size())-1;i>=0;i--)if(s[i]==',' && i+1!=s.size()){
		s.insert(s.begin()+i+1,' ');
	}
	for(int i=int(s.size())-1;i>=0;i--)if(i && i+2<s.size() && s[i]=='.' && s[i+1]=='.' && s[i+2]=='.' && s[i-1]!=' '){
		s.insert(s.begin()+i,' ');
	}
	
	cout<<s<<endl;
	return 0;
}