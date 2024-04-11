#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
int n , s;
pair < pair < int , int > , pair < int , int > > arr[N];
long long sum[N];
long long suma[N];
long long sumb[N];
long long pre[N];
int main(){
	scanf("%d %d" , &n , &s);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d %d" , &arr[i].first.second , &arr[i].second.first , &arr[i].second.second);
		arr[i].first.first = arr[i].second.first - arr[i].second.second;
	}
	sort(arr + 1 , arr + 1 + n);
	sum[0] = 0;
	suma[0] = 0;
	sumb[0] = 0;
	pre[0] = 0;
	for(int i = 1 ; i <= n ; ++i){
		sum[i] = sum[i - 1] + arr[i].first.second;
		suma[i] = suma[i - 1] + arr[i].second.first;
		sumb[i] = sumb[i - 1] + arr[i].second.second;
		pre[i] = pre[i - 1] + 1LL * arr[i].first.second * arr[i].second.second;
	}
	long long tot = 0;
	long long ans = 0;
	long long how = 1LL << 60;
	long long acst = 0;
	for(int i = n ; i >= 1 ; --i){
		long long cst = 0;
		long long val = 0;
		cst += (tot + s - 1) / s;
		val += acst;
		cst += (sum[i - 1] + s - 1) / s;
		val += pre[i - 1];
		long long extraa = (s - (tot % s)) % s;
		long long extrab = (s - (sum[i - 1] % s)) % s;
		long long costa;
		long long vala;
		long long costb;
		long long valb;
		costa = cst;
		vala = val;
		extraa = min(extraa , 1LL * arr[i].first.second);
		if(extraa == arr[i].first.second){
			vala += 1LL * arr[i].second.first * extraa;
		}
		else{
			long long rem = arr[i].first.second - extraa;
			vala += 1LL * extraa * arr[i].second.first;
			extraa = 0;
			if(extrab >= rem){
				vala += 1LL * rem * arr[i].second.second;
			}
			else{
				long long buy = (rem - extrab + s - 1) / s;
				extraa += buy * s;
				costa += buy;
				if(extraa >= rem){
					vala += 1LL * rem * arr[i].second.first;
				}
				else{
					vala += 1LL * extraa * arr[i].second.first;
					rem -= extraa;
					vala += 1LL * rem * arr[i].second.second;
				}
			}
		}
		extraa = (s - (tot % s)) % s;
		extrab = (s - (sum[i - 1] % s)) % s;
		costb = cst;
		valb = val;
		extrab = min(extrab , 1LL * arr[i].first.second);
		if(extrab == arr[i].first.second){
			valb += 1LL * arr[i].second.second * extrab;
		}
		else{
			long long rem = arr[i].first.second - extrab;
			valb += 1LL * extrab * arr[i].second.second;
			extrab = 0;
			if(extraa >= rem){
				valb += 1LL * rem * arr[i].second.first;
			}
			else{
				long long buy = (rem - extraa + s - 1) / s;
				extrab += buy * s;
				costb += buy;
				if(extrab >= rem){
					valb += 1LL * rem * arr[i].second.second;
				}
				else{
					valb += 1LL * extrab * arr[i].second.second;
					rem -= extrab;
					valb += 1LL * rem * arr[i].second.first;
				}
			}
		}
		if(costa < how){
			how = costa;
			ans = vala;
		}
		else if(costa == how){
			ans = max(ans , vala);
		}
		if(costb < how){
			how = costb;
			ans = valb;
		}
		else if(costb == how){
			ans = max(ans , valb);
		}
		tot += arr[i].first.second;
		acst += 1LL * arr[i].first.second * arr[i].second.first;
	}
	long long cst = (tot + s - 1) / s;
	if(cst < how){
		how = cst;
		ans = acst;
	}
	else if(cst == how){
		ans = max(ans , acst);
	}
	printf("%lld\n" , ans);
}