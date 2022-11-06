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

int n, rn;

vector<int> dp[1000];
int dpc[1000];
int dpn;
int narabi[300010];

int main()
{
	read(n);
	
	if(n <= 100){
		vector<int> dp(n+1, int(2e9));
		dp[0] = 0;
		for(int i=1; i<=n; ++i){
			int xl, xr; read(xl, xr);
			dp.erase(lower_bound(all(dp), xr));
			for(int& x:dp) if(xl <= x && x < xr) ++x;
			dp.insert(lower_bound(all(dp), xl), xl);
		}
		for(int i=0; i<=n; ++i) if(dp[i] == int(2e9)){
			printf("%d\n", i-1);
			return 0;
		}
		printf("%d\n", n);
		return 0;
	}
	
	rn = int(sqrt(n)) + 2;
	
	for(int i=0, tick=rn+1; i<=n; ++i){
		dp[dpn].pb(i ? int(2e9) : 0);
		if(!--tick) tick=rn+1, ++dpn;
	}
	if(dp[dpn].size()) ++dpn;
	
	int tick = rn;
	for(int i=1; i<=n; ++i){
		int xl, xr; read(xl, xr);
		{
			int l=-1, r=dpn-1;
			while(l+1 < r){
				int mid = (l+r)/2;
				if(xr <= dp[mid].back()+dpc[mid]) r = mid;
				else l = mid;
			}
			dp[r].erase(lower_bound(all(dp[r]), xr-dpc[r]));
			
			for(;r>=0;r--){
				if(dp[r].back()+dpc[r] < xl) break;
				if(xl <= dp[r][0]+dpc[r] && dp[r].back()+dpc[r] < xr){
					++dpc[r];
					continue;
				}
				for(int& x:dp[r]){
					if(xl <= x+dpc[r] && x+dpc[r] < xr) ++x;
				}
			}
			
			if(r<0) ++r;
			while(true){
				if(r+1 == dpn || xl < dp[r+1][0] + dpc[r+1]){
					dp[r].insert(lower_bound(all(dp[r]), xl-dpc[r]), xl-dpc[r]);
					break;
				}
				++r;
			}
		}
		
		if(!--tick){
			int nn = 0;
			for(int i=0; i<dpn; ++i){
				for(int x:dp[i]) narabi[nn++] = x + dpc[i];
				dp[i].clear();
			}
			
			int pt = 0;
			for(int i=0; i<nn; i += rn+1){
				dp[pt].insert(dp[pt].end(), narabi + i, narabi + min(i+rn+1, nn));
				dpc[pt] = 0;
				++pt;
			}
			dpn = pt;
			
			tick = rn;
		}
	}
	
	for(int i=0, c=-1; i<dpn; ++i){
		for(int x:dp[i]){
			if(x == int(2e9)){
				printf("%d\n", c);
				return 0;
			}
			++c;
		}
	}
	printf("%d\n", n);
	return 0;
}