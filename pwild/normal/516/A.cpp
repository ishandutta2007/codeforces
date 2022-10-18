#include <list>
#include <map>
#include <stack>
#include <set>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <functional>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <bitset>
#include <tuple>
using namespace std;

typedef long long ll;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
typedef pair<ll,ll> pii;

const ll oo = 0x3f3f3f3f3f3f3f3f;
const double eps = 1e-9;

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (ll i = (a); i < (b); i++)
#define FORD(i,a,b) for (ll i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })
#define xx first
#define yy second


int main() {
	ios_base::sync_with_stdio(false);

	ll f[10][4] = {
		{0,0,0,0},
		{0,0,0,0},
		{1,0,0,0},
		{0,1,0,0},
		{2,1,0,0},
		{0,0,1,0},
		{0,1,1,0},
		{0,0,0,1},
		{3,0,0,1},
		{1,2,0,1}};

	ll n, a;
	cin >> n >> a;
	ll c[4] = {};
	while (a) {
		ll d = a % 10;
		FOR(k,0,4) c[k] += f[d][k];
		a /= 10;
	}
	FOR(i,0,c[3]) cout << "7";
	FOR(i,0,c[2]) cout << "5";
	FOR(i,0,c[1]) cout << "3";
	FOR(i,0,c[0]) cout << "2";
	cout << endl;
	
}