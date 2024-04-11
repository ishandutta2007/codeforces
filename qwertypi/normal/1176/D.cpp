#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime[2750132];
int prime[199999];
void prime_prec(void){
	isPrime[0] = false;
	isPrime[1] = false;
	for(int i=2;i<2750132;i++){
		isPrime[i] = true;
	}
	int i = 2;
	while(i * i < 2750132){
		if(isPrime[i]){
			for(int j = i; i * j <= 2750131; j++){
				isPrime[i * j] = false;
			}
		}
		i++;
	}
	int pos = 0;
	for(int i=0;i<2750132;i++){
		if(isPrime[i]){
			prime[pos++] = i;
		}
	}
}

int f(int x){
	if(isPrime[x]){
		return lower_bound(prime, prime+199999, x) - begin(prime) + 1;
	}else{
		for(int i=0;i<199999;i++){
			if(x % prime[i] == 0){
				return x / prime[i];
			}
		}
	}
}

int cnt[2750132];
int main(){
	prime_prec();
	int n;
	cin >> n;
	fill(cnt, cnt+2750132, 0);
	for(int i=0;i<2*n;i++){
		int k;
		cin >> k;
		cnt[k]++;
	}
	for(int i=2750131;i>=2;i--){
		if(cnt[i]){
			int res = f(i);
			while(cnt[i] > 0){
				cnt[i]--;
				cnt[res]--;
				if(isPrime[i]){
					cout << res << ' ';
				}else{
					cout << i << ' ';
				}
			}
		}
	}
	return 0;
}