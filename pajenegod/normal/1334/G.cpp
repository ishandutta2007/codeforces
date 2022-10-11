#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <array>
#include <immintrin.h>
 
using ll = long long;
using namespace std;
 
void re(int& x);
void pr(int x);
void pr(const char *x);
void ps();
 
typedef vector<int> vi;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#include <cstring>
 
const int P=998244353;
const int mod = P;
const int root = 3;
const int xx = 524288; 
int p[30];
char s[210000];
char t[210000];
 
ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}
 
void ntt(int* __restrict a, int* __restrict rt, int* __restrict rev, int n) {
    rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int k = 1; k < n; k *= 2)
        for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
            int ai = a[i + j];    
            if (ai >= mod) ai -= mod;

            int z = (ll) rt[j + k] * a[i + j + k] % mod;
            a[i + j + k] = ai + mod - z;
            a[i + j] = ai + z;
    }
    rep(i,0,n)
        if (a[i] >= mod) a[i] -= mod;
}
 
void solve()
{
    int N = 1 << 19;
    vi rt(N, 1), rev(N);
    rep(i,0,N) rev[i] = (rev[i / 2] | (i & 1) << 19) / 2;
	ll curL = mod / 2, inv = modpow(N, mod - 2);
    
    for (int k = 2; k < N; k *= 2) {
		ll z[] = {1, modpow(root, curL /= 2)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
       
    
    rep(i,0,26) re(p[i]);
 
    scanf("%s", s);
    scanf("%s", t);
 
    int sn = strlen(s);
    int tn = strlen(t);
 
    rep(i,0,sn) s[i]-='a';
    rep(i,0,tn) t[i]-='a';
    
 
    vi o(xx,0);
 
    rep(i,0,26) {
        vi ss(xx,0);
        vi tt(xx,0);
        for (int j = 0; j < sn; j++) {
            ss[sn-j-1] = (s[j]==i) || (p[s[j]] == i+1);
        } 
        for (int j = 0; j < tn; j++) {
            tt[j] = (t[j] == i);
        }
 
        ntt(tt.data(), rt.data(), rev.data(), N);
        ntt(ss.data(), rt.data(), rev.data(), N);
 
		rep(i,0,xx) o[i] = (o[i]+ss[i]*1ll*tt[i])%P;
    }
 
    vi out(N);
    rep(i,0,N) out[-i & (N-1)] = o[i] * inv % mod;
    ntt(out.data(), rt.data(), rev.data(), N);
    
    o = out;
    rep(i,0,tn-sn+1) pr((int)(o[i+(sn-1)] == sn));
    ps();
}
 
int main() {
 
    solve();
}
 
void re(int& x) { scanf("%d", &x); }
 
void pr(int x) { printf("%d", x); }
 
void pr(const char *x) { printf("%s", x); }
 
void ps() { pr("\n"); }