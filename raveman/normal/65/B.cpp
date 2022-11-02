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

#define sz(a)			int(a.size())
#define all(a)			(a).begin(), (a).end()
#define CL(a, b)		memset(a, b, sizeof a) 
#define FOR(i, a, b)	for (int i(a); i < (b); ++i)
#define REP(i, n)		FOR(i, 0, n)
#define UN(a)			sort(all(a)), (a).erase(unique(all(a)), (a).end())
#define pb				push_back
#define SORT(a)			sort(all(a))

typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;

int n;
bool v[2222][2222];

int p(string s){
	int v = 0;
	REP(i,4) v = 10 * v + s[i]-'0';
	return v;
}

int q[2222][2222];

bool go(int i,int j){
	if(i>=n) return 1;
	if(j>2011)return 0;
	if(q[i][j]!=0) return q[i][j]==1;
	bool can = go(i,j+1);
	if(v[i][j] && go(i+1,j))
		can = true;
	return q[i][j] = can?1:-1,can;
}

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	cin>>n;
	REP(i,n){
		string s;
		cin>>s;
		v[i][p(s)]=true;
		REP(j,4) REP(d,10){
			string t = s;
			t[j]=char('0'+d);
			int val = p(t);
			if(val<1000 || val>2011) continue;
			v[i][val]=true;
		}
	}
	int prev =  -1;
	FOR(i,1000,2012) if(v[0][i] && go(0,i)){
		prev = i;
	}
	if(prev==-1) puts("No solution");
	else{
		cout<<prev<<endl;
		FOR(i,1,n){
			for(;;prev++)if(v[i][prev] && go(i,prev)){
				cout<<prev<<endl;
				break;
			}
		}
	}
	return 0;
}