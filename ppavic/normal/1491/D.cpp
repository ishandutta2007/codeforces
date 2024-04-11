#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef vector < int > vi;

const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

int q;

vi pretvori(int x){
	vi ret;
	for(int i = 0;i < 30;i++)
		if(x & (1 << i))
			ret.PB(i);
	return ret;
}

int main(){
	scanf("%d", &q);
	for(;q--;){
		int x, y; scanf("%d%d", &x, &y);
		if(x > y) {
			printf("NO\n"); continue;
		}
		vi xx = pretvori(x), yy = pretvori(y);
		if((int)xx.size() < (int)yy.size()){
			printf("NO\n"); continue;		
		}
		bool got = 0;
		for(int i = 0;i < (int)yy.size();i++)
			if(xx[i] > yy[i]){
				got = 1; break;
			}
		if(got){
			printf("NO\n"); continue;
		}
		printf("YES\n");
	}
	return 0;
}