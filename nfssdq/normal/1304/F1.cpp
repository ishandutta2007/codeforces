#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define xx         first
#define yy         second
#define pb         push_back
#define mp         make_pair
#define LL         long long
#define inf        INT_MAX/3
#define mod        1000000007ll
#define PI         acos(-1.0)
#define linf       (1ll<<60)-1
#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     ((A).begin(), (A).end())
#define set0(ar)   memset(ar,0,sizeof ar)
#define vsort(v)   sort(v.begin(),v.end())
#define setinf(ar) memset(ar,126,sizeof ar)

//cout << fixed << setprecision(20) << p << endl;

template <class T> inline T bigmod(T p,T e,T M){
    LL ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    }
    return (T)ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

int dp[51][20001], ar[51][20001], sum[51][20001], tmp[20001], lft[20001], rgt[20011];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
	REP(i, n) FOR(j, 1, m+1) {
		cin >> ar[i][j];
		sum[i][j] = sum[i][j-1] + ar[i][j];
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = 1; j <= m-k+1; j++) {
			tmp[j] = sum[i][j+k-1] - sum[i][j-1] + dp[i+1][j];
			lft[j] = max(tmp[j], lft[j-1]);
		}
		for(int j = m-k+1; j >= 1; j--) rgt[j] = max(rgt[j+1], tmp[j]);
		for(int j = 1; j <= m-k+1; j++){
			int v = rgt[j+k];
			if(j > k) v = max(v, lft[j-k]);
			for(int l = j-k+1; l < j+k; l++) {
				if(l <= 0) continue;
				if(l < j) v = max(v, sum[i][j-1] - sum[i][l-1] + dp[i+1][l]);
				else v = max(v, sum[i][l+k-1] - sum[i][j+k-1] + dp[i+1][l]);
			}
			dp[i][j] = sum[i][j+k-1] - sum[i][j-1] + v;
		}
	}
	cout << rgt[1] << endl;
}