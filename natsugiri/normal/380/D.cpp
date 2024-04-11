#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;

const LL MOD = 1000000007;

int N;
int A[100010];

const int MAX = 100010;
LL inv[MAX+1], fact[MAX], invFact[MAX];
void init() {
    inv[1] = 1;
    fact[0] = 1;
    invFact[0] = 1;
    for (int i=1; i<MAX;) {
	fact[i] = fact[i-1] * i % MOD;
	invFact[i] = invFact[i-1] * inv[i] % MOD;
	i++;
	inv[i] = inv[MOD % i] *(MOD - MOD / i) % MOD;
    }
}
	

LL powMod(LL x, LL y, LL m) {
    LL r=1;
    for (;y;y>>=1) {
	if (y&1) r = r*x%m;
	x = x*x%m;
    }
    return r;
}

LL nCk(int n, int k) {
    return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
}

LL calc(int l, int r, int num) {
    LL ans = 1;
    
    while (0<=l || r<N) {
	int next_l = l-1;
	for (; next_l >= 0 && A[next_l]==0; next_l--);
	next_l = max(next_l, -1);
	
	int next_r = r+1;
	for (; next_r < N && A[next_r]==0; next_r++);
	next_r = min(next_r, N);

// 	cout << l << ", " <<  r << ", " << num << ", " << ans << endl;
// 	cout << next_l << ' ' << next_r << endl;
	
	if (next_l == -1 && next_r == N) {
	    ans = ans * nCk(l-next_l + next_r-r -2, l-next_l-1) % MOD;
	    l = -1;
	    r = N;
	    num = N;
	} else {
	    if (next_r != N && A[next_r] < num + next_r-r) return 0;
	    if (next_l != -1 && A[next_l] < num + l-next_l) return 0;

	    if (next_l == -1 || (next_r != N && A[next_r] < A[next_l])) {
		ans = ans * nCk(A[next_r]-num-1, next_r-r-1) % MOD;
		l = l - (A[next_r]-num - (next_r-r));
		r = next_r;
		num = A[next_r];
	    } else {
		ans = ans * nCk(A[next_l]-num-1, l-next_l-1) % MOD;
		r = r + A[next_l]-num - (l-next_l);
		l = next_l;
		num = A[next_l];
	    }
	}
    }

    return ans;
}

int main() {
    init();

    scanf("%d", &N);

    for (int i=0; i<N; i++) scanf("%d", A+i);

    int p=-1;
    for (int i=0; i<N; i++) {
	if (A[i] && (p==-1 || A[p] > A[i])) p=i;
    }
    if (p==-1) {
	cout << powMod(2, N-1, MOD) << endl;
    } else {
	LL ans = 0;
	int cnt=0;
	for (int i=p+1; i<N && A[i]==0; i++) cnt++;
	if (cnt>=A[p]-1) ans += calc(p, p+A[p]-1, A[p]);


	cnt = 0;
	for (int i=p-1; i>=0 && A[i]==0; i--) cnt++;
	if (A[p]!=1 && cnt>=A[p]-1) ans += calc(p-A[p]+1, p, A[p]);

	ans %= MOD;
	if (A[p] > 1) ans = ans * powMod(2, A[p]-2, MOD) % MOD;
	cout << ans << endl;
    }
    

    return 0;
}