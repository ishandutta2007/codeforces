#include "bits/stdc++.h"
using namespace std;
const int N = 2005;
int n;
int x[N];
int y[N];
map < long long , int > hori , verti;
map < pair < long long , pair < int , int > > , int > mp;
long long ans;
long long sqr(int num){
	return 1LL * num * num;
}
long long c2(int c22){
	return 1LL * c22 * (c22 - 1LL) / 2LL;
}
int main(){
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; ++i){
		scanf("%d %d" , x + i , y + i);
	}
	for(int i = 1 ; i < n ; ++i){
		for(int j = i + 1 ; j <= n ; ++j){
			int num = y[j] - y[i];
			int den = x[j] - x[i];
			long long dist = sqr(num) + sqr(den);
			if(num == 0){
				++hori[dist];
			}
			else if(den == 0){
				++verti[dist];
			}
			else{
				int tmp = __gcd(abs(num) , abs(den));
				num /= tmp;
				den /= tmp;
				if(num < 0){
					num *= -1;
					den *= -1;
				}
				++mp[make_pair(dist , make_pair(num , den))];
			}
		}
	}
	for(auto it : hori){
		ans += c2(it.second);
	}
	for(auto it : verti){
		ans += c2(it.second);
	}
	for(auto it : mp){
		ans += c2(it.second);
	}
	ans >>= 1;
	printf("%lld\n" , ans);
}