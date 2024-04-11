#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < int, int > pii;
typedef vector < int > vi;
typedef set < int > si;
typedef vector < ll > vl;
typedef pair < ll, ll > pll;

const int N = 1e6 + 500;
const ll INF = 1e11;
const int MOD = 1e9 + 7;
const int BS = 31337;
const int OFF  = (1 << 19);

ll tour[2 * OFF], prop[2 * OFF], a[N], p[N];
int n;

void refresh(int x){
	if(!prop[x]) return;
	tour[x] += prop[x];
	if(x < OFF){
		prop[2 * x] += prop[x];
		prop[2 * x + 1] += prop[x];
	}
	prop[x] = 0;
}

void update(int i,int a,int b,int lo,int hi, ll x){
	refresh(i);
	if(lo <= a && b <= hi){
		prop[i] += x;
		refresh(i); return;
	}
	if(lo > b || hi < a) return;
	//printf("%d %d %d %d %d\n", i, a, b, lo, hi);
	update(2 * i,      a, (a + b) / 2,   lo, hi, x);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
	tour[i] = min(tour[2 * i], tour[2 * i + 1]);
	//printf("tour[ %d ] = %d\n", i, tour[i]);
}

int query(int i){
	refresh(i);
	if(i >= OFF) return i - OFF;
	refresh(2 * i + 1);
	if(tour[2 * i + 1] == 0) return query(2 * i + 1);
	return query(2 * i);
}

int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%lld", a + i);
		update(1, 0, OFF - 1, i, i, a[i]);
	}
	update(1, 0, OFF - 1, n, OFF - 1, INF);
//	printf("tu sam\n"); return 0;
	for(int i = 1;i <= n;i++){
		int pos = query(1);
		p[pos] = i; //printf("pos = %d\n", pos);
		update(1, 0, OFF - 1, pos, n, -i);
		update(1, 0, OFF - 1, pos, pos, INF);
	}
	for(int i = 0;i < n;i++)
		printf("%d ", p[i]);
	printf("\n");
	return 0;
}