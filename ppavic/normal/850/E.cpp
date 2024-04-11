#include <cstdio>
#include <cstdlib>

using namespace std;

typedef long long ll;

const int N = (1 << 20) + 500;
const int MOD = 1e9 + 7;

int pod_2 = 1;

inline int add(int A, int B){
	if(A + B >= MOD) return A + B - MOD;
	return A + B;
}

inline int sub(int A,int B){
	if(A - B < 0) return A - B + MOD;
	return A - B;
}

inline int mul(int A,int B){
	return (ll)A * B % MOD;
}

int a[N], n;

void FWT(int l,int r){
	if(l == r) return;
	int mid = (l + r) / 2;
	FWT(l, mid); FWT(mid + 1, r);
	for(int i = l;i <= mid;i++){
		int x = a[i], y = a[i + (mid - l + 1)];
		a[i] = mul(add(x, y), pod_2);
		a[i + (mid - l + 1)] = mul(sub(x, y), pod_2);
	}
}


int main(){
	scanf("%d", &n);
	for(int i = 0;i < (1 << n);i++){
		char c; scanf(" %c", &c);
		a[i] = c - '0';
	}
	FWT(0, (1 << n) - 1);
	pod_2 = (MOD + 1) / 2;
	for(int i = 0;i < (1 << n);i++) a[i] = mul(a[i], a[i]);
	FWT(0, (1 << n) - 1);
	int sol = 0;
	for(int i = 0;i < (1 << n);i++){
		int kol = __builtin_popcount(i);
		sol = add(sol, mul((1 << (n - kol)), a[i]));
	}
	printf("%d\n", mul(sol, 3));
	return 0;
}