 // Problem : E. Neatness 
 // Contest : Codeforces - Codeforces Round #209 (Div. 2) 
 // URL : https://codeforces.com/contest/359/problem/E 
 // Memory Limit : 256 MB 
 // Time Limit : 2000 ms 
 // Powered by CP Editor (https://github.com/cpeditor/cpeditor)  
 /*  A Submission by $%U%$  
 at time: $%Y%$-$%M%$-$%D%$ $%h%$:$%m%$:$%s%$ 
 */ 
 #include <bits/stdc++.h> 
 using namespace std; 
 #include <ext/pb_ds/assoc_container.hpp> 
 #include <ext/pb_ds/tree_policy.hpp> 
 using namespace __gnu_pbds; 
 #define fef(i,a,b) for(ll i=a;i<=b;i++) 
 #define rer(i,a,b) for(ll i=b;i>=a;i--) 
 #define wew while(true) 
 #pragma comment(linker, "/stack:200000000") 
 #pragma GCC optimize("Ofast") 
 #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native") 
 #define FILE_IN "cseq.inp" 
 #define FILE_OUT "cseq.out" 
 #define ofile freopen(FILE_IN,"r",stdin);freopen(FILE_OUT,"w",stdout) 
 #define fio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0) 
 #define nfio cin.tie(0);cout.tie(0) 
 #define max(x,y) (((x)>(y))?(x):(y)) 
 #define min(x,y) (((x)<(y))?(x):(y)) 
 #define ord(a,b,c) ((a>=b)and(b>=c)) 
 #define MOD (ll(1000000007))
 #define MAX 300001 
 #define mag 320 
 #define p1 first 
 #define p2 second.first 
 #define p3 second.second 
 #define fi first
 #define se second
 #define pow2(x) (ll(1)<<x)
 #define pii pair<int,int> 
 #define piii pair<int,pii>
 #define For(i,__,___) for(int i=__;i<=___;i++) 
 #define Rep(i,__,___) for(int i=__;i>=___;i--)
 #define ordered_set tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update> 
 #define endl "\n" 
 #define bi BigInt 
 typedef long long ll; 
 //---------END-------//

#define mod 1000000007
long long ff[2005][2005];
typedef long long LL;
const int MX = 1000005;
const int M = 1000000007;
LL inv[MX], f[MX], g[MX];
void init() {
	int i;
	inv[1] = 1;
	for (i = 2; i < MX; i++) inv[i] = inv[M % i] * (M - M/ i) % M;
	f[0] = g[0] = 1;
	for (i = 1; i < MX; i++) {
		f[i] = f[i - 1] * i % M;
		g[i] = g[i - 1] * inv[i] % M;
	}
}
inline LL C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * g[k] % M * g[n - k] % M;
}
LL powmod(int n ,int m){
	LL tmp = n ,ans = 1;
	while(m){
		if(m & 1) ans = ans * tmp % mod;
		m >>= 1;
		tmp = tmp * tmp % mod;
	}
	return ans;
}
void calc() {
	init();
	ff[1][1] = 1;
	for(int i = 2 ; i < 2005 ; i ++) {
		for(int j = 1 ; j < 2005 ; j ++) {
		    
			ff[i][j] = j * ff[i - 1][j] + j * ff[i - 1][j - 1];
			ff[i][j] %= mod;
		}
	}
}
LL ans;
int main() {
    fio;
	calc();
	int n ,m ,k;
	cin >> n >> m >> k;
	if(m == 1){
		cout << powmod(k ,n) << endl;
		return 0;
	}
	for(int i = 1 ;i <= min(n ,k) ;i ++){
		for(int j = 0 ;j <= i ;j ++){
			LL tmp = 1;
			if(m - 2) {
				tmp =tmp * (C(k ,i) * ff[n][i] % mod) % mod;
				tmp = tmp * (powmod(j ,n * (m - 2)) * C(i ,j) % mod) % mod;
				tmp = tmp * (C(k - i,i - j) * ff[n][i] % mod) % mod;
				ans += tmp % mod;
			}
			else {
				tmp =tmp * (C(k ,i) * ff[n][i] % mod) % mod;
				tmp = tmp * C(i ,j) % mod;
				tmp = tmp * (C(k - i,i - j) * ff[n][i] % mod) % mod;
				ans += tmp % mod;
			}
		}
	}
	cout << ans % mod << endl;
}