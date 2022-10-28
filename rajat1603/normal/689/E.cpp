#include "bits/stdc++.h"
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
int fact[N];
int ifact[N];
int add(int a , int b){
	int res = a + b;
	if(res >= mod){
		return res - mod;
	}
	return res;
}
int mult(int a , int b){
	long long res = a;
	res *= b;
	if(res >= mod){
		return res % mod;
	}
	return res;
}
int power(int a , int b){
	int res = 1;
	while(b){
		if(b & 1){
			res = mult(res , a);
		}
		a = mult(a , a);
		b >>= 1;
	}
	return res;
}
void pre(){
	fact[0] = 1;
	for(int i = 1 ; i < N ; ++i){
		fact[i] = mult(fact[i - 1] , i);
	}
	ifact[N - 1] = power(fact[N - 1] , mod - 2);
	for(int i = N - 2 ; i >= 0 ; --i){
		ifact[i] = mult(ifact[i + 1] , i + 1);
	}
}
int ncr(int n , int r){
	if(n < r){
		return 0;
	}
	return mult(fact[n] , mult(ifact[n - r] , ifact[r]));
}
int n , k;
pair < int , int > arr[N];
vector < int > v;
int ans;
multiset < int > ms;
void insert(pair < int , int > num){
	ms.insert(num.second);
}
int solve(int x){
	while(!ms.empty() && (*ms.begin()) < x){
		ms.erase(ms.begin());
	}
	return ncr(int(ms.size()) , k);
}
int main(){
	scanf("%d %d" , &n , &k);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , &arr[i].first , &arr[i].second);
	}
	pre();
	v.clear();
	for(int i = 1 ; i <= n ; ++i){
		v.emplace_back(arr[i].first);
		v.emplace_back(arr[i].second);
		v.emplace_back(arr[i].first + 1);
		v.emplace_back(arr[i].first - 1);
		v.emplace_back(arr[i].second + 1);
		v.emplace_back(arr[i].second - 1);
	}
	sort(v.begin() , v.end());
	v.resize(unique(v.begin() , v.end()) - v.begin());
	sort(arr + 1 , arr + 1 + n);
	int cur = 1;
	for(int i = 0 ; i + 1 < v.size() ; ++i){
		int st = v[i];
		int en = v[i + 1] - 1;
		while(cur <= n && arr[cur].first <= st){
			insert(arr[cur++]);
		}
		ans = add(ans , mult(solve(st) , (en - st + 1) % mod));
	}
	printf("%d\n" , ans);
}