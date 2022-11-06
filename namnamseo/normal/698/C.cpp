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

int n, k;
double p[30];

double dp[1<<20];
double ans[30];

int main()
{
	read(n, k);
	for(int i=0; i<n; ++i) scanf("%lf", p+i);
	
	if(n == k){
		for(int i=0; i<n; ++i){
			if(p[i] > 0) printf("1 ");
			else printf("0 ");
		}
		return 0;
	}
	
	int AM = (1<<n);
	dp[0] = 1;
	for(int i=1; i<AM; ++i){
		if(__builtin_popcount(i) > k) continue;
		double ps=0;
		for(int j=0; j<n; ++j) if(1&(i>>j)) ps += p[j];
		for(int j=0; j<n; ++j) if(1&(i>>j)){
			dp[i] += dp[i^(1<<j)] * p[j] / (1-(ps-p[j]));
		}
		if(__builtin_popcount(i) == k) for(int j=0; j<n; ++j) if(!(1&(i>>j))){
			ans[j] += dp[i];
		}
	}
	
	for(int i=0; i<n; ++i) printf("%.10f\n", (p[i]>0) ? 1-ans[i] : 0);
	return 0;
}