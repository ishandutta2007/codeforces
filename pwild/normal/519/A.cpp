#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
#include <cassert>
#include <unordered_set>
#include <unordered_map>
#include <tuple>
#include <bitset>
#include <iterator>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<bool> vb;
const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
#define sz(c) int((c).size())
#define all(c) begin(c), end(c)
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = (b)-1; i >= (a); i--)
#define FORIT(i,c) for (auto i = begin(c); i != end(c); ++i)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

int main() {
	ios_base::sync_with_stdio(false);
	
	ll score[2] = {};
	FOR(i,0,8) {
		string s; cin >> s;
		FOR(j,0,8) {
			if (s[j] == '.') continue;
			ll p = (s[j] >='a') && (s[j] <= 'z');
			if (p) s[j] += 'A'-'a';
			switch(s[j]) {
				case 'Q': score[p] += 9; break;
				case 'R': score[p] += 5; break;
				case 'B': score[p] += 3; break;
				case 'N': score[p] += 3; break;
				case 'P': score[p] += 1; break;
			}

		}
	}
		if (score[0] > score[1]) cout << "White" << endl;
		if (score[0] == score[1]) cout << "Draw" << endl;
		if (score[0] < score[1]) cout << "Black" << endl;


}