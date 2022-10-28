#include "bits/stdc++.h"
using namespace std;
const int N = 25;
long long a , b;
long long num;
long long who[N];
int cur[N];
int tot[N];
int n;
long long solve(){
	long long res = 0;
	while(b){
		for(int i = 1 ; i <= n ; ++i){
			while(cur[i] < tot[i] && b % (1LL * num * who[i]) == 0){
				num *= who[i];
				++cur[i];
			}
		}
		long long mx = 0;
		for(int i = 1 ; i <= n ; ++i){
			if(cur[i] < tot[i]){
				long long tmp = 1LL * num * who[i];
				tmp = (b / tmp) * tmp;
				if(tmp > mx){
					mx = tmp;
				}
			}
		}
		res += (b - mx) / num;
		b = mx;
	}
	return res;
}
int main(){
	scanf("%lld %lld" , &a , &b);
	if(a == 1){
		printf("%lld\n" , b);
		return 0;
	}
	long long tmp = a;
	n = 0;
	for(int i = 2 ; 1LL * i * i <= tmp ; ++i){
		if(tmp % i == 0){
			who[++n] = i;
			tot[n] = 0;
			while(tmp % i == 0){
				tmp /= i;
				++tot[n];
			}
		}
	}
	if(tmp > 1){
		who[++n] = tmp;
		tot[n] = 1;
	}
	num = 1;
	memset(cur , 0 , sizeof(cur));
	printf("%lld\n" , solve());
}