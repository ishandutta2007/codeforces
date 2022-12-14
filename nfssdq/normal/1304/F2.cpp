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
deque < pair<int,int> > dq;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m, k; cin >> n >> m >> k;
	REP(i, n) FOR(j, 1, m+1) {
		cin >> ar[i][j];
		sum[i][j] = sum[i][j-1] + ar[i][j];
	}
	for(int i = n-1; i >= 0; i--){
		while(!dq.empty()) dq.pop_back();
		for(int j = 1; j <= m-k+1; j++) {
			tmp[j] = dp[i+1][j];
			lft[j] = max(lft[j-1], sum[i][j+k-1] - sum[i][j-1] + dp[i+1][j]);
			if(j > k) tmp[j] = max(tmp[j], lft[j-k]);
			
			while(dq.size() > 0 && dq.back().yy <= j-k) dq.pop_back();
			if(dq.size() > 0) tmp[j] = max(tmp[j], dq.back().xx + sum[i][j-1]);

			while(dq.size() > 0 && dq.front().xx < dp[i+1][j] - sum[i][j-1]) dq.pop_front();
			dq.push_front(mp(dp[i+1][j] - sum[i][j-1], j));
		}
		while(!dq.empty()) dq.pop_back();
		for(int j = m-k+1; j >= 1; j--) {
			rgt[j] = max(rgt[j+1], sum[i][j+k-1] - sum[i][j-1] + dp[i+1][j]);
			tmp[j] = max(tmp[j], rgt[j+k]);

			while(dq.size() > 0 && dq.back().yy >= j+k) dq.pop_back();
			if(dq.size() > 0) tmp[j] = max(tmp[j], dq.back().xx - sum[i][j+k-1]);

			while(dq.size() > 0 && dq.front().xx < dp[i+1][j] + sum[i][j+k-1]) dq.pop_front();
			dq.push_front(mp(dp[i+1][j] + sum[i][j+k-1], j));
		}
		for(int j = 1; j <= m-k+1; j++){
			dp[i][j] = sum[i][j+k-1] - sum[i][j-1] + tmp[j];
		}
	}
	cout << rgt[1] << endl;
}