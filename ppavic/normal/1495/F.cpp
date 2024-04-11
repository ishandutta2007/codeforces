#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <algorithm>

#define PB push_back

using namespace std;

const int N = 2e5 + 500;
const int OFF = (1 << 18);

typedef long long ll;

ll T[2 * OFF][2]; 
int T_m[2 * OFF], P[N], A[N], B[N];

void update(int i, int a, int b, int lo, int hi, ll x, int k){
	if(lo <= a && b <= hi){
		T[i][k] += x; return;
	}
	if(a > hi || b < lo) return;
	update(2 * i, a, (a + b) / 2, lo, hi, x, k);
	update(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, x, k);
}

ll get(int x, int k){
	ll ret = 0;
	for(x = (x + OFF) ; x ; x /= 2)
		ret += T[x][k];
	return ret;
}

int mrg(int i, int j){
	if(P[i] > P[j])
		return i;
	return j;
}

int query(int i, int a, int b, int lo, int hi){
	if(lo <= a && b <= hi) return T_m[i];
	if(a > hi || b < lo) return N - 1;
	return mrg(query(2 * i, a, (a + b) / 2, lo, hi), query(2 * i + 1, (a + b) / 2 + 1, b, lo, hi));
}

vector < int > gdj[N];
vector < int > dod[N], odu[N];
int qL[3 * N], qR[3 * N];
int n, q, qq;
ll qS[3 * N];

void solve(int l, int r){
	if(l > r) return;
	int mid = query(1, 0, OFF - 1, l, r);
	solve(l, mid - 1); solve(mid + 1, r);
	update(1, 0, OFF - 1, mid + 1, r, A[mid], 0);
	for(int x : gdj[mid])
		qS[x] = get(qL[x], 1) + get(qR[x], 0);
	update(1, 0, OFF - 1, mid, r, (l != mid ? get(l, 1) : 0), 0);
	update(1, 0, OFF - 1, l, mid, min((r != mid ? get(mid + 1, 1) : 0LL) + A[mid], (ll)B[mid]), 1);
}

inline int dodaj_kverij(int l, int r){
	qL[qq] = l, qR[qq] = r; 
	gdj[query(1, 0, OFF - 1, l, r)].PB(qq);
	return qq++;
}

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 0;i < n;i++)	
		scanf("%d", P + i), T_m[OFF + i] = i;
	P[n] = n; T_m[OFF + n] = n;
	for(int i = OFF - 1 ; i ; i--)
		T_m[i] = mrg(T_m[2 * i], T_m[2 * i + 1]);
	for(int i = 0;i < n;i++)
		scanf("%d", A + i);
	for(int i = 0;i < n;i++)
		scanf("%d", B + i);
	set < int > S; S.insert(0); S.insert(n);
	int st = dodaj_kverij(0, n);	
	for(int i = 0;i < q;i++){
		int x; scanf("%d", &x); x--;
		if(!x) continue;
		if(S.count(x)){
			S.erase(x);
			int pos = *S.lower_bound(x), pri = *(--S.lower_bound(x));
			odu[i].PB(dodaj_kverij(pri, x));
			odu[i].PB(dodaj_kverij(x, pos));
			dod[i].PB(dodaj_kverij(pri, pos));
		}
		else{
			int pos = *S.lower_bound(x), pri = *(--S.lower_bound(x));
			S.insert(x);
			odu[i].PB(dodaj_kverij(pri, pos));
			dod[i].PB(dodaj_kverij(pri, x));
			dod[i].PB(dodaj_kverij(x, pos));
		}
	}
	solve(0, n);
	ll cur = qS[st];
	for(int i = 0;i < q;i++){
		for(int x : odu[i]) cur -= qS[x];
		for(int x : dod[i]) cur += qS[x];
		printf("%lld\n", cur);
	}
	return 0;
}