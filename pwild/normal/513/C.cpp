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
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= a; i--)
#define FORIT(i,c) for (auto i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

ll L[5],R[5];

double prob(ll i, ll minV, ll maxV) {
	minV = max(minV,L[i]);
	maxV = min(maxV,R[i]);
	if (minV > maxV) return 0;
	return double(maxV-minV+1)/double(R[i]-L[i]+1);
}

int main() {
	ios_base::sync_with_stdio(false);

	ll n; cin >> n;
	FOR(i,0,n) cin >> L[i] >> R[i];
	
	double res = 0;
	

	FOR(k,1,10001) {
		FOR(f,0,n) FOR(s,0,n) {
			if (f == s) continue;
			
			double p = prob(f,k+(f>s),10000);//double(R[f]-k+(f>s))/double(R[f]-L[f]+1);
			p *= prob(s,k,k);//double(R[s]-L[s]+1);

			FOR(i,0,n) if (i != f && i != s) {
				p *= prob(i,1,k-(i<s));//double(k-L[i]+(i<s))/double(R[i]-L[i]+1);
			}
			res += k*p;
		}
		//cerr << res << endl;
	}
	
	cout << fixed << setprecision(12) << res << endl;



}