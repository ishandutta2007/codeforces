#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

typedef vector < int > vi;
typedef long long ll;

const int N = 2e5 + 500;
const int OFF = (1 << 17);
const int MOD = 1e9 + 7;

inline int add(int A, int B){
	if(A + B >= MOD)
		return A + B - MOD;
	return A + B;
}

inline int mul(int A, int B){
	return (ll)A * B % MOD;
}

inline int pot(int A, int B){
	int ret = 1, bs = A;
	for(; B ; B >>= 1){
		if(B & 1) ret = mul(ret, bs);
		bs = mul(bs, bs);
	}
	return ret;
}

struct node{
	node *L, *R;
	int umn;
	node(){
		L = 0, R = 0, umn = 0;
	}
	node(node* _L, node* _R, int _umn){
		L = _L, R = _R, umn = _umn;
	}
};

typedef node* pnode;

pnode L(pnode x) { return x ? x -> L : 0; }
pnode R(pnode x) { return x ? x -> R : 0; }
int umn(pnode x) { return x ? x -> umn : 1; }

void update(pnode &x, int a, int b, int i, int y){
	x = new node(L(x), R(x), umn(x));
	if(a == b){
		x -> umn = y;
		return;
	}
	if(i <= (a + b) / 2)
		update(x -> L, a, (a + b) / 2, i, y);
	else
		update(x -> R, (a + b) / 2 + 1, b, i, y);
	x -> umn = mul(umn(x -> L), umn(x -> R));
}

int query(pnode x, int a, int b, int ct){
	if(ct <= a) return umn(x);
	if(b < ct || !x) return 1;
	return mul(query(x -> L, a, (a + b) / 2, ct), query(x -> R, (a + b) / 2 + 1, b, ct));
}

vi T[2 * OFF], prosti;

int eval(const vi &v){
	int ret = 1;
	for(int i = 0;i < (int)prosti.size();i++)
		ret = mul(ret, pot(prosti[i], v[i]));
	return ret;
}

void mrg(vi &A, vi &B, vi &C){
	for(int i = 0;i < (int)A.size();i++)
		C[i] = max(A[i], B[i]);
}

bool prost(int x){
	if(x <= 2) return (x == 2);
	for(int i = 2;i * i <= x;i++)
		if(!(x % i)) return 0;
	return 1;
}

void precompute(){
	for(int i = 1;i * i <= N;i++)
		if(prost(i)) prosti.PB(i);
	for(int i = 0;i < 2 * OFF;i++)
		T[i].resize(prosti.size());
}

void query2(int i, int a, int b, int lo, int hi, vi &ret){
	if(lo <= a && b <= hi){
		mrg(T[i], ret, ret);
		return;
	}
	if(a > hi || b < lo) return;
	query2(2 * i, a, (a + b) / 2, lo, hi, ret);
	query2(2 * i + 1, (a + b) / 2 + 1, b, lo, hi, ret);
}

int A[N], lst[N], n;
pnode root[N];

int main(){
	precompute();
	memset(lst, -1, sizeof(lst));
	scanf("%d", &n);
	for(int i = 0;i < n;i++){
		scanf("%d", A + i);
		for(int j = 0;j < (int)prosti.size();j++){
			while(!(A[i] % prosti[j])){
				T[OFF + i][j]++;
				A[i] /= prosti[j];
			}
		}
		root[i] = (i ? root[i - 1] : NULL);
		if(A[i] != 1){
			if(lst[A[i]] != -1)
				update(root[i], 0, OFF - 1, lst[A[i]], 1);
			update(root[i], 0, OFF - 1, i, A[i]);
			lst[A[i]] = i;
		}
	}
	for(int i = OFF - 1; i ; i--)
		mrg(T[2 * i], T[2 * i + 1], T[i]);
	int last = 0;
	int q; scanf("%d", &q);
	for(;q--;){
		int l, r; scanf("%d%d", &l, &r);
		l = (l + last) % n, r = (r + last) % n;
		if(r < l) {l ^= r, r ^= l, l ^= r;}
		vi dio1; dio1.resize(prosti.size());
		query2(1, 0, OFF - 1, l, r, dio1);
		int dio2 = query(root[r], 0, OFF - 1, l);
		last = mul(eval(dio1), dio2);
		printf("%d\n", last);	
	}
}