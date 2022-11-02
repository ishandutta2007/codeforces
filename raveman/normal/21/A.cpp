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

bool isV(char C){
	return isalnum(C) || C=='_';
}

bool isu(string s){
	if(s.size()<1 || s.size()>16) return 0;
	REP(i,s.size())
		if(!isV(s[i])) return 0;
	return 1;
}
bool isr(string s){return isu(s);}

bool ish(string s){
	if(s.size()<1 || s.size()>32) return 0;
	REP(i,s.size())
		if(s[i]!='.' && !isV(s[i])) return 0;
	if(s[0]=='.' || s[s.size()-1]=='.') return 0;
	FOR(i,1,s.size())
		if(s[i]==s[i-1] && s[i]=='.') return 0;
	REP(i,s.size()) if(s[i]=='.') s[i]=' ';
	stringstream ss(s);
	string t;
	while(ss>>t)
		if(!isu(t)) return 0;
	return 1;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	string s;
	getline(cin,s);
	string u,h,r;
	REP(i,s.size()) if(s[i]=='@'){
		u=s.substr(0,i);
		if(!isu(u)){puts("NO");return 0;}

		FOR(j,i,s.size()) if(s[j]=='/'){
			if(!ish(s.substr(i+1,j-i-1))
				|| 
				!isr(s.substr(j+1))){
					puts("NO");
					return 0;
			}else{
				puts("YES");
				return 0;
			}
		}
		if(ish(s.substr(i+1))) puts("YES");
		else puts("NO");
		return 0;
	}
	puts("NO");

	return 0;
}