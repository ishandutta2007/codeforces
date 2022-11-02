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

ll solve(ll x,ll y, ll k){
	if(x>y) swap(x,y);

	ll a = (k+3)/2;
	ll b = k+2-a;

	a = min(a,x);
	b = min(b,y);

	ll m = k + 2 - a - b;
	a = min(x,a+m);
	b = min(y,b+m);

	return a*b;
}

int main() {
#ifdef LocalHost
        freopen("input.txt", "r", stdin);
#endif

		ll x,y,z,k;
		cin>>x>>y>>z>>k;

		ll res = min(x*z*y,k+1);

		for(int i=0;i<x;i++){
			if(i>k) break;

			res = max(res, solve(y,z,k-i)*(i+1));
		}

		cout<<res<<endl;
		return 0;
}