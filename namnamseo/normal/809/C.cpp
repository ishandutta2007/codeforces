#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
typedef pair<ll,ll> pll;
void read(int& x){ scanf("%d",&x); }
void read(ll& x){ scanf("%lld",&x); }
template<typename T,typename... Args>
void read(T& a,Args&... b){ read(a); read(b...); }
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define eb emplace_back
#define x first
#define y second

const ll mod = int(1e9)+7;

ll k;

bitset<32> N, M, K;

ll cnt[2][2][2];
ll sum[2][2][2];
ll tc[2][2][2];
ll ts[2][2][2];

ll f(ll n, ll m){
	if(n<0 || m<0) return 0;
	N = bitset<32>(n);
	M = bitset<32>(m);
	K = bitset<32>(k);
	memset(cnt, 0, sizeof(cnt));
	memset(sum, 0, sizeof(sum));
	cnt[0][0][0] = 1;
	for(int i=0; i<=30; ++i){
		memset(tc, 0, sizeof(tc));
		memset(ts, 0, sizeof(ts));
		for(int B=0; B<8; ++B){
			int bk=B/4, bn=B%4/2, bm=B&1;
			for(int C=0; C<4; ++C){
				int cn=C/2, cm=C&1, x=cn^cm;
				
				int nk=(K[i] == x && bk) || (!K[i] && x);
				int nn=(N[i] == cn && bn) || (!N[i] && cn);
				int nm=(M[i] == cm && bm) || (!M[i] && cm);
				
				(tc[nk][nn][nm] += cnt[bk][bn][bm]) %= mod;
				(ts[nk][nn][nm] += sum[bk][bn][bm]) %= mod;
				(ts[nk][nn][nm] += x * cnt[bk][bn][bm] * (1ll<<i) % mod) %= mod;
			}
		}
		memcpy(cnt, tc, sizeof(cnt));
		memcpy(sum, ts, sizeof(sum));
	}
	return (sum[0][0][0] + cnt[0][0][0]) % mod;
}

int main()
{
	int q;
	read(q);
for(;q--;){
	int x1,x2, y1,y2;
	read(x1, y1, x2, y2, k);
	--x1; --x2; --y1; --y2; --k;
	ll ans = f(x2, y2) - f(x1-1, y2) - f(x2, y1-1) + f(x1-1, y1-1);
	printf("%lld\n", ((ans %= mod) += mod) % mod);
}
	return 0;
}