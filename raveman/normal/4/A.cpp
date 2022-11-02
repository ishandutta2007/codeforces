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

	int n;
	cin>>n;
	if(n>2 && (n%2)==0) puts("YES");
	else puts("NO");
	return 0;
}