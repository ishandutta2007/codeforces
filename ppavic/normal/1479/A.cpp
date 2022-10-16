#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <vector>
 
#define X first
#define Y second
#define PB push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;
typedef pair < int, int > pt;
typedef vector < int > vi;
typedef set < int > si;
 
const int N = 1e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 18;
const int OFF = (1 << 18);
 
ll ccw(pt A, pt B, pt C) { return (ll)A.X * (B.Y - C.Y) + (ll)B.X * (C.Y - A.Y) + (ll)C.X * (A.Y - B.Y); }
int add(int A, int B) { if(A + B >= MOD) return A + B - MOD; return A + B; }
int mul(int A, int B) { return (ll)A * B % MOD; }
int sub(int A, int B) { if(A - B < 0) return A - B + MOD; return A - B; }
 
int n, A[N];
 
int pitaj(int x){
	if(!x || x == n + 1) return INF;
	if(A[x]) return A[x];
	printf("? %d\n", x);
	fflush(stdout);
	scanf("%d", A + x);
	return A[x];
}
 
int main(){
	scanf("%d", &n);
	int lo = 1, hi = n;
	while(hi - lo > 30){
		int mid = (lo + hi) / 2;
		if(pitaj(mid) < pitaj(mid + 1))
			hi = mid;
		else
			lo = mid + 1;
		
	}
	for(int i = lo;i <= hi;i++){
		if(pitaj(i) < pitaj(i + 1) && pitaj(i) < pitaj(i - 1)){
			printf("! %d\n", i);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}