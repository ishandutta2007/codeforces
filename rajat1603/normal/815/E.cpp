#include "bits/stdc++.h"
using namespace std;
long long n , k;
vector < pair < long long , long long > > v;
long long get(long long len , long long k){
	map < long long , long long > mp;
	mp.clear();
	++mp[len];
	v.clear();
	while(!mp.empty()){
		auto itt = prev(mp.end());
		auto it = *itt;
		mp.erase(itt);
		v.emplace_back(make_pair(it.first - 1LL >> 1 , it.second));
		if(it.first > 1){
			mp[it.first >> 1] += it.second;
		}
		if(it.first > 2){
			mp[it.first - 1 >> 1] += it.second;
		}
	}
	for(auto it : v){
		if(it.second >= k){
			return it.first;
		}
		k -= it.second;
	}
}
int main(){
	cin >> n >> k;
	if(k == 1){
		cout << 1 << endl;
		return 0;
	}
	if(k == 2){
		cout << n << endl;
		return 0;
	}
	k -= 2;
	long long ans = get(n - 2 , k);
	long long l = 2;
	long long r = n - 1;
	for(auto it : v){
		if(it.first > ans){
			k -= it.second;
		}
	}
	while(l < r){
		long long mid = l + r >> 1;
		if(k == 1 && (r - l >> 1) == ans){
			l = r = mid;
			break;
		}
		long long tmp = get(mid - l , k);
		long long cnt = 0;
		for(auto it : v){
			cnt += it.first == ans ? it.second : 0;
		}
		if(cnt >= k){
			r = mid - 1;
		}
		else{
			l = mid + 1;
			k -= cnt;
		}
	}
	printf("%lld\n" , l);
}