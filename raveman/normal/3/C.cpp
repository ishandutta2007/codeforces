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

string s[3];

bool won(char c){
	REP(i,3){
		bool w = 1;
		REP(j,3) if(s[i][j]!=c) w=0;
		if(w) return 1;
		w=1;
		REP(j,3) if(s[j][i]!=c) w=0;
		if(w) return 1;
	}
	bool w = 1;
	REP(i,3) if(s[i][i]!=c) w=0;
	if(w) return 1;
	w=1;
	REP(i,3) if(s[i][2-i]!=c) w=0;
	if(w) return 1;
	return 0;
}

int main(){
#ifdef LocalHost    
        freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
#endif
	REP(i,3) cin>>s[i];
	int c = 0 , o = 0;
	REP(i,3)REP(j,3) if(s[i][j]=='X') c++;
	else if(s[i][j]=='0') o++;
	if(o>c || c>o+1 || won('X') && won('0') || won('0') && c == o+1 || won('X') && c == o) puts("illegal");
	else{
		if(won('X')) puts("the first player won");
		else if(won('0')) puts("the second player won");
		else if(o+c==9) puts("draw");
		else if(o==c) puts("first");
		else puts("second");
	}

	return 0;
}