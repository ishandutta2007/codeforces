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

int main() {
#ifdef LocalHost
	freopen("input.txt", "r", stdin);
#endif

	ll a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;

	
	if( b * d * f > a * c * e || c==0 && d!=0 || a==0 && b!=0 && c!=0 && d!=0) puts("Ron");
	else puts("Hermione");

	return 0;
}