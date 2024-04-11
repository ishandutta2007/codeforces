#include "bits/stdc++.h"
using namespace std;
const int N = 1e5 + 5;
int n , k , m;
vector < pair < int , int > > v;
int tot;
long long ans;
int main(){
	scanf("%d %d %d" , &n , &k , &m);
	v.clear();
	tot = n;
	ans = 0;
	for(int i = 1 ; i <= n ; ++i){
		int val;
		scanf("%d" , &val);
		if(!v.empty() && v.back().first == val){
			++v.back().second;
			if(v.back().second == k){
				v.pop_back();
				tot -= k;
			}
		}
		else{
			v.push_back({val , 1});
		}
	}
	ans = 1LL * tot * m;
	if(v.size() <= 1 || m == 1){
		ans %= k;
		printf("%lld\n" , ans);
		return 0;
	}
	int l = 0;
	int r = v.size() - 1;
	while(l < r){
		if(v[l].first != v[r].first){
			printf("%lld\n" , ans);
			return 0;
		}
		if(v[l].second + v[r].second < k){
			printf("%lld\n" , ans);
			return 0;
		}
		ans -= 1LL * k * (m - 1LL);
		if(v[l].second + v[r].second > k){
			printf("%lld\n" , ans);
			return 0;
		}
		++l;
		--r;
	}
	if(l == r){
		long long tmp = 1LL * v[l].second * m;
		long long rem = tmp % k;
		ans -= tmp - rem;
		if(!rem){
			ans = 0;
		}
	}
	else{
		ans = 0;
	}
	printf("%lld\n" , ans);
}