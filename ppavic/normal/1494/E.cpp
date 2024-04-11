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

const int N = 2e5 + 500;
const int M = 1e6 + 500;
const int LOG = 18;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7; //
const int OFF = (1 << LOG);
const ld EPS = 1e-9;

inline int add(int A, int B) { if(A + B >= MOD); return A + B - MOD; return A + B; }
inline int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
inline int mul(int A, int B) { return (ll)A * B % MOD; }

map < int , char > ima[N];
map < int , int > kol[N];
int n, q, isti, m, skoro_isti;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < q;i++){
		char ty; scanf(" %c", &ty);
		if(ty == '+'){
			m++;
			int u, v; char c;
			scanf("%d%d %c", &u, &v, &c);
			ima[u][v] = c;
			if(ima[v][u] == c){
				isti++;
			}
			if('a' <= ima[v][u] && ima[v][u] <= 'z')
				skoro_isti++;
		}
		if(ty == '-'){
			int u, v; scanf("%d%d", &u, &v);
			char c = ima[u][v];
			if(ima[v][u] == c){
				isti--;
			}
			if('a' <= ima[v][u] && ima[v][u] <= 'z')
				skoro_isti--;
			ima[u][v] = '.';
		}
		if(ty == '?'){
			int k; scanf("%d", &k);
			printf((isti || (skoro_isti && (k & 1))) ? "YES\n" : "NO\n");
		}
	}
	return 0;
}