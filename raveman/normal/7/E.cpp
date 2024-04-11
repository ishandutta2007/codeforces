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

int n;
string s;

map<string,string> d;
map<string,char>   f;
int pos;
string S;
bool good=1;

char expr(string &S,int &pos);
char parse(string s);

char fact(string &S,int &pos){
	if(S[pos]=='('){
		pos++;
		char v = expr(S, pos);
		pos++;
		return ' ';
	}
	string s = "";
	while(isalnum(S[pos])) s.pb(S[pos]),pos++;
	if(d.count(s)) return parse(d[s]);
	return ' ';
}

char term(string &S,int &pos){
	char r = fact(S,pos);
	while(S[pos]=='*' || S[pos]=='/'){
		char op = S[pos];

		pos++;
		
		string s1 = "";
		int p1 = pos - 2;
		while(p1>=0 && isalpha(S[p1])) s1.pb(S[p1]),p1--;
		reverse(s1.begin(),s1.end());

		string s2 = "";
		int p2 = pos;
		while(isalpha(S[p2])) s2.pb(S[p2]),p2++;


		if(d.count(s1) && d.count(s2)){
			char v1 = parse(d[s1]);
			char v2 = parse(d[s2]);	

			if(op=='*' && (v1=='+' || v2=='+')) good=0;
			if(op=='/' && (v1=='+' || v2!=' ')) good=0;
		}else if(d.count(s1)){
			char v1 = parse(d[s1]);
			
			if(op=='*' && v1=='+') good=0;
			if(op=='/' && v1=='+') good=0;
		}else if(d.count(s2)){
			char v2 = parse(d[s2]);

			if(op=='*' && v2=='+') good=0;
			if(op=='/' && v2!=' ') good=0;
		}
		
		char v = fact(S,pos);
		r='*';
		//if(v=='+') r= '+';
	}
	return r;
}

char expr(string &S,int &pos){
	char r = term(S,pos);
	while(S[pos]=='+' || S[pos]=='-'){
		char op = S[pos];

		pos++;
		
		string s2 = "";
		int p2 = pos;
		while(isalpha(S[p2])) s2.pb(S[p2]),p2++;

		if(d.count(s2)){
			char v2 = parse(d[s2]);
			if(op=='-' && v2=='+') good=0;
		}

		char v = term(S,pos);
		r='+';
	}
	return r;
}

char parse(string s){
	if(f.count(s)) return f[s];
	int pos=0;
	return f[s]=expr(s,pos);
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif
	cin>>n;
	getline(cin,s);
	REP(i,n){
		getline(cin,s);
		int pos = 0;
		while(s[pos]!='#') pos++;
		while(s[pos]!='e') pos++;
		pos++;
		while(s[pos]!='e') pos++;
		pos++;
		while(isspace(s[pos])) pos++;
		string name = "";
		while(!isspace(s[pos])) name.pb(s[pos]),pos++;
		string val = "";
		FOR(j,pos,s.size()) if(!isspace(s[j]))
			val.pb(s[j]);
		d[name] = val;
	}
	getline(cin,s);
	string t="";
	REP(i,s.size()) if(!isspace(s[i])) t.pb(s[i]);
	int pos = 0;
	expr(t, pos);
	puts(good?"OK":"Suspicious");
	return 0;
}