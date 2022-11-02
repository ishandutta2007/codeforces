#pragma comment(linker, "/STACK:60777216")  

#include <algorithm>
#include <iostream>
#include <complex>
#include <cstring>
#include <vector>
#include <string>
#include <cstdio>
#include <ctime>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

#define sz(a)                   int(a.size())
#define all(a)                  (a).begin(), (a).end()
#define CL(a, b)                memset(a, b, sizeof a) 
#define FOR(i, a, b)			for (int i(a); i < (b); ++i)
#define REP(i, n)               FOR(i, 0, n)
#define UN(a)                   sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb                      push_back
#define SORT(a)                 sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int k,n;
string s;
int b[26][26];

int d[111][111][26];

int solve(int n,int k,int last){
	if(k<0) return -1000000000;

	if(n==0) return 0;

	int val = d[n][k][last];
	if(val!=-1000000000) return val;

	val = -1000000000;
	REP(i,26){
		val = max(val, b[i][last] + solve(n-1,k+(i!=s[n-1]-'a' ? -1 : 0),i));
	}
	return d[n][k][last] = val;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	REP(i,111)REP(j,111)REP(k,26)
		d[i][j][k]=-1000000000;
	
	cin>>s>>k>>n;
	REP(i,n){
		char x,y;
		int c;
		scanf(" %c %c %d",&x,&y,&c);
		b[x-'a'][y-'a']=c;
	}

	int res = -1000000000;
	REP(i,26)
		res = max(res, solve(s.size() - 1, k + (s[s.size()-1]-'a' != i ? -1 : 0),  i));
	cout<<res<<endl;


	return 0;
}