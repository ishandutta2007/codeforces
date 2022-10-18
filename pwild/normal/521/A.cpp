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
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })
#define xx first
#define yy second


int main() {
	ios_base::sync_with_stdio(false);
	
	ll n; cin >> n;

	string s;
	cin >> s;
	ll cnt[4] = {0,0,0,0};
	FOR(i,0,n) {
		switch(s[i]) {
			case 'A': cnt[0]++; break;
			case 'C': cnt[1]++; break;
			case 'G': cnt[2]++; break;
			case 'T': cnt[3]++; break;
		}
	}

	sort(cnt,cnt+4);

	//FOR(i,0,4) cerr << cnt[i] << endl;

	ll j = 0;
	while (j <= 3 && cnt[4-j-1] == cnt[3]) j++;
	
	ll res = 1;
	FOR(i,0,n) res = (res*j) % 1000000007;
	cout << res << endl;






}