//DS includes
#include<bitset>
#include<complex>
#include<deque>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>



//Other Includes
#include<algorithm>
#include<cassert>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<fstream>
#include<iostream>
#include<sstream>




#define oo 				0xBADC0DE
#define s(n)			scanf("%d",&n)
#define sl(n) 			scanf("%lld",&n)
#define sf(n) 			scanf("%lf",&n)
#define fill(a,v) 		memset(a, v, sizeof a)
#define ull 			unsigned long long
#define ll 				long long
#define bitcount 		__builtin_popcount
#define all(x) 			x.begin(), x.end()
#define pb( z ) 		push_back( z )
#define gcd				__gcd
using namespace std;



char a[32];
ll dp[20][2][2][2];
int vis[20][2][2][2], vid;
char s[20];

ll solve(int digit, bool less, bool f1, bool allz) {
	
	if (a[digit]==0) {
		s[digit] = 0;
		//cout << s << " " << less << " " << f1 << " " << allz << endl;
		return f1 ? 1LL : 0LL;
	}
	
	ll &d = dp[digit][less][f1][allz];
	int &v = vis[digit][less][f1][allz];
	if (v==vid) return d;
	v = vid;
	d = 0;
	
	for (int nd='0'; nd <= '9'; nd++) {
		if (nd <= a[digit] || less) {
			int nallz = allz && nd == '0';
			bool nf1 = 0;
			if (allz && !nallz) {
				nf1 = nd=='1';
			}
			s[digit] = nd;
			d += solve(digit+1, less || (nd < a[digit]), f1 || nf1, nallz);
		}
	}
	
	return d;
}
ll calc(ll n) {
	int sz = 0;
	while (n > 0) { a[sz++] = (n%10) + '0'; n /= 10; }
	reverse(a, a+sz);
	a[sz] = 0;
	++vid;
	ll ret = solve(0,0,0,1);
	//cout << a << " " << ret << endl;
	return ret;
}


ll lo[1024], hi[1024];
double prob[1024];
int n;
double dpp[1024][1024];
bool visp[1024][1024];
double F(int p, int left) {
	if (left==0)
		return 1.0;
	if (p==n || left > (n-p) )
		return 0.0;
	double &ret = dpp[p][left];
	bool &vis = visp[p][left];
	if (vis)
		return ret;
	vis = 1;
	return ret = prob[p]*F(p+1, left-1) + (1.0-prob[p])*F(p+1, left);
}

int main(){
	
	cin>>n;
	for (int i=0; i < n; i++) {
		cin>>lo[i]>>hi[i];
	}
	
	for (int i=0; i < n; i++) {
		ll r = hi[i] - lo[i] + 1;
		ll o = calc(hi[i]) - calc(lo[i]-1);
		//cout << o << " / " << r << endl;
		prob[i] = o / ( r + 0. );
	}
	
	int k;
	cin>>k;
	
	int limit = (n*k + 99) / 100;
	
	//for (int i=0; i < n; i++)cout << prob[i] << endl;
	
	printf("%.12lf\n", F(0, limit) );
	
	return 0;
}