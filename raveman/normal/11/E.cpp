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

char s[1111111];
int n;


double solve(string t){
	n = t.size();
	double res = 0;

	bool s = 0;
	int p=0,q=0;
	int x=0;
	REP(i,n){
		char need = (q%2 ? 'R' : 'L');
		if(t[i]=='X') q++;
		else if(t[i]==need) q++,p++,s=0;
		else{
			q++;p++;q++;
			if(s) x++;
			s=!s;
		}
	}

	if(q%2){
		q++;
		if(s) x++;
	}

	res = max(res, 100. * p / q);
	res = max(res, 100. * (p - x) / (q - x -x));
	return res;
}

int main(){
#ifdef LocalHost    
    freopen("input.txt","r",stdin);
 ///   freopen("output.txt","w",stdout);
#endif

	gets(s);
	n = strlen(s);
	string t;
	REP(i,n){
		if(i && s[i]==s[i-1] && s[i]!='X') t.pb('X');
		t.pb(s[i]);
	}

	double res = 0;
	if(t[0] == t[t.size()-1] && t[0]!='X') 
		res = max(solve("X"+t),solve(t+"X"));
	else res = solve(t);

	int val = res * 1000000 + 1e-9;
	res = val / 1000000.;
	printf("%.6lf\n",res);

    return 0;
}