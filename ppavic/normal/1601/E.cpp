#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef vector < int > vi;
typedef pair < int, int > pii;

const int N = 3e5 + 500;
const int M = 1e6 + 500;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int LOG = 19;
const int OFF = (1 << LOG);

int n, q, k, A[N], Tmin[2 * OFF];
int L[N], R[N];
vector < int > gdje[N];

int querymin(int i, int a, int b, int lo, int hi){
	if(lo <= a && b <= hi) return Tmin[i];
	if(a > hi || b < lo) return INF;
	return min(querymin(2 * i, a, (a + b) / 2, lo, hi), querymin(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

ll T[2 * OFF], ans[N];
int Tmax[2 * OFF], prop[2 * OFF], OFF2;

void refresh(int x, int len){
	if(!prop[x]) return;
	Tmax[x] = prop[x]; T[x] = (ll)prop[x] * len;
	if(x < OFF2){
		prop[2 * x] = prop[x]; prop[2 * x + 1] = prop[x];
	}
	prop[x] = 0;
}


int nadi_veci(int i, int x, int len){
	refresh(i, len);
	if(i >= OFF2) return i - OFF2;
	refresh(2 * i + 1, len >> 1);
	if(Tmax[2 * i + 1] > x) 
		return nadi_veci(2 * i + 1, x, len >> 1);
	return nadi_veci(2 * i, x, len >> 1);
}

void update(int i, int a, int b, int lo, int hi, int x){
	if(lo <= a && b <= hi){
		prop[i] = x; refresh(i, b - a + 1); return;
	}
	refresh(i, b - a + 1);
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi, x);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x);
	T[i] = T[2 * i] + T[2 * i + 1]; Tmax[i] = max(Tmax[2 * i], Tmax[2 * i + 1]);
}

ll query(int i, int a, int b, int lo, int hi){
	refresh(i, b - a + 1);
	if(lo <= a && b <= hi) return T[i];
	if(a > hi || b < lo) return 0;
	return query(2 * i, a, (a + b) / 2, lo, hi) + query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi);
}


int main(){
	scanf("%d%d%d", &n, &q, &k);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		Tmin[OFF + i] = A[i];
	}
	for(int i = OFF - 1; i ; i--) Tmin[i] = min(Tmin[2 * i], Tmin[2 * i + 1]);
	for(int i = 0;i < q;i++){
		scanf("%d%d", L + i, R + i);
		L[i]--; R[i]--; R[i] += (k - (R[i] - L[i] + 1) % k) % k;
		gdje[L[i]].PB(i);
	}
	OFF2 = 1;
	while(OFF2 <= (n / k) + 1) OFF2 <<= 1;
	for(int p = 1;p <= k;p++){
		for(int i = 0;i < 2 * OFF2;i++) T[i] = 0, Tmax[i] = 0, prop[i] = 0;
		for(int i = 0;i <= (n - p) / k;i++) Tmax[OFF2 + i] = INF, T[OFF2 + i] = INF;
		for(int i = OFF2 - 1; i ; i--) Tmax[i] = max(Tmax[2 * i], Tmax[2 * i + 1]), T[i] = T[2 * i] + T[2 * i + 1];
		for(int i = n - p;i >= 0;i -= k){
			update(1, 0, OFF2 - 1, i / k, nadi_veci(1, A[i], OFF2), A[i]);
			for(int j : gdje[i]){
				ans[j] = query(1, 0, OFF2 - 1, L[j] / k, (R[j] + 1) / k - 1);
			}
			int miin = querymin(1, 0, OFF - 1, max(i - k + 1, 0), i);
			update(1, 0, OFF2 - 1, i / k, nadi_veci(1, miin, OFF2), miin);
		}
	}
	for(int i = 0;i < q;i++)
		printf("%lld\n", ans[i]);
	return 0;
}