#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define X first
#define Y second
#define PB push_back

using namespace std;

typedef long long ll;
typedef pair < ll, ll > pt;

const int N = 1e5 + 500;
const int OFF = (1 << 17);

ll ccw(pt A, pt B, pt C){
	return A.X * (B.Y - C.Y) + B.X * (C.Y - A.Y) + C.X * (A.Y - B.Y);
}

int A[N], qk[N], n, q;
ll P[N], sol[N];
vector < int > Q[N];

ll get(pt tmp, int x){
	return tmp.X * x + tmp.Y;
}

ll find(vector < pt > &v, int x){
	int lo = 0, hi = (int)v.size() - 1;
	ll ans = (ll)1e18;
	while(lo < hi){
		int mid = (lo + hi) / 2;
		ll r1 = get(v[mid], x), r2 = get(v[mid + 1], x);
		ans = min(ans, min(r1, r2));
		if(r1 < r2)
			hi = mid - 1;
		else
			lo = mid + 2;
	}
	if(lo >= 0 && lo < (int)v.size())
		ans = min(ans, get(v[lo], x));
	return ans;
}

vector < pt > build_hull(vector < pt > &sve){
	vector < pt > hull;
	sort(sve.rbegin(), sve.rend());
	for(pt nw : sve){
		while((int)hull.size() >= 2 && ccw(hull[(int)hull.size() - 2], hull.back(), nw) >= 0)
			hull.pop_back();
		hull.PB(nw);
	}
	return hull;
}

vector < pt > T[2 * OFF];

void build_T(){
	for(int i = 0;i < n;i++){
		for(int j = (OFF + i); j ; j /= 2)
			T[j].PB({A[i], (ll)A[i] * i - P[i]});
	}
	for(int i = OFF - 1; i ; i--)
		T[i] = build_hull(T[i]);
}

ll query(int i, int a, int b, int lo, int hi, int x){
	if(lo <= a && b <= hi) 
		return find(T[i], x);
	if(a > hi || b < lo) 
		return (ll)1e18;
	return min(query(2 * i, a, (a + b) / 2, lo, hi, x), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x));
		
}


int main(){
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		P[i] = (i ? P[i - 1] : 0LL) + A[i];
	}
	build_T();
	scanf("%d", &q);
	for(int i = 0;i < q;i++){
		int x, y; scanf("%d%d", &x, &y); y--;
		printf("%lld\n", P[y] + query(1, 0, OFF - 1, y - x + 1, y, x - y));
	}
	return 0;
}