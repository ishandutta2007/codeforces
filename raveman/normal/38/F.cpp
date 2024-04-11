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

int n;
string s[33];

map<string,set<int> > m;

struct R{
	bool win;
	int a,b;
	R(){win=a=b=0;}
};

map<string,R> r;
R solve(string s,int ml=0,int sum=0){
	if(r.count(s)) return r[s];
	R res;
	s.pb(' ');
	REP(i,26){
		s[s.size()-1]=char('a'+i);
		if(m.count(s)){
			R temp = solve(s,max(ml,i+1),sum+i+1);
			int score = (sum+i+1)*max(ml,i+1)+m[s].size();
			temp.b += score;

			if(!temp.win){
				if(!res.win || res.a < temp.b || res.a == temp.b && res.b > temp.a)
					res.win = 1,res.a = temp.b,res.b=temp.a;
			}else if(!res.win){
				if(res.a < temp.b || res.a == temp.b && res.b > temp.a)
					res.a = temp.b, res.b = temp.a;
			}
		}
	}
	s.erase(s.end()-1);
	s=" "+s;
	REP(i,26){
		s[0]=char('a'+i);
		if(m.count(s)){
			R temp = solve(s,max(ml,i+1),sum+i+1);
			int score = (sum+i+1)*max(ml,i+1)+m[s].size();
			temp.b += score;

			if(!temp.win){
				if(!res.win || res.a < temp.b || res.a == temp.b && res.b > temp.a)
					res.win = 1,res.a = temp.b,res.b=temp.a;
			}else if(!res.win){
				if(res.a < temp.b || res.a == temp.b && res.b > temp.a)
					res.a = temp.b, res.b = temp.a;
			}
		}
	}
	s.erase(s.begin());
	return r[s]=res;
}

int main(){
#ifdef LocalHost    
	freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif

	cin>>n;
	REP(i,n){
		cin>>s[i];
		REP(j,s[i].size()){
			string t = "";
			FOR(k,j,s[i].size()){
				t.pb(s[i][k]);
				m[t].insert(i);
			}
		}
	}
	R res = solve("");
	if(res.win) puts("First");
	else puts("Second");
	cout<<res.a<<' '<<res.b<<endl;

	return 0;
}