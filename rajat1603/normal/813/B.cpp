#include "bits/stdc++.h"
using namespace std;
long long x , y , l , r;
vector < long long > v;
void get(long long x , vector < long long > &a){
	long long cur = 1;
	a.push_back(cur);
	while(1){
		if(cur > 2e18 / x){
			break;
		}
		cur *= x;
		if(cur <= r){
			a.push_back(cur);
		}
		else{
			break;
		}
	}
}
int main(){
	cin >> x >> y >> l >> r;
	v.clear();
	v.push_back(l - 1);
	v.push_back(r + 1);
	vector < long long > a , b;
	a.clear();
	b.clear();
	get(x , a);
	get(y , b);
	for(long long n : a){
		for(long long m : b){
			if(n + m <= r && n + m >= l){
				v.push_back(n + m);
			}
		}
	}
	sort(v.begin() , v.end());
	long long ans = 0;
	for(int i = 1 ; i < v.size() ; ++i){
		ans = max(ans , v[i] - v[i - 1] - 1);
	}
	printf("%lld\n" , ans);
}