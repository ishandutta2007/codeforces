#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <numeric>
typedef long long ll;
using namespace std;
int phi[1000001];
vector<int> prime;
 
template <class T>
T powmod(T a, ll b, ll _m){
	T res = 1;
	while(b){
		if(b % 2){
			res *= a;
			res %= _m;
		}
		a = (a * a) % _m;
		b /= 2;
	}
	return res;
}
 
bool MR(ll n){
    if(n == 1){
        return false;
    }
	ll d = n - 1;
	int ord = 0;
	while(d % 2 == 0){
		ord++;
		d /= 2;
	}
	for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
		if(n == a){
			return true;
		}
		ll x = powmod<ll>(a, d, n);
		if(x == 1){
			goto End;
		}
		for(int i=0;i<=ord;i++){
			if(x == n - 1){
				goto End;
			}
			x = (x * x) % n;
		}
		return false;
		End:;
	}
	return true;
}
 
pair<int, int> lp(int n){
	for(auto i:prime){
		if(n % i == 0){
			int cnt = 0;
			while(n % i == 0){
				n /= i;
				cnt++;
			}
			return pair<int, int> {i, cnt};
		}
	}
}
int main(){
	int n, k;
	cin >> n >> k;
	if(k == 1){
		cout << 3;
		return 0;
	}
	phi[1] = 1;
	for(int i=1;i<=ceil(sqrt(n));i++){
		if(MR(i)){
			prime.push_back(i);
		}
	}
	for(int i=2;i<=n;i++){
		if(MR(i)){
			phi[i] = i - 1;  
		}else{
			pair<int, int> power = lp(i);
			phi[i] = phi[i / (int)pow(power.first, power.second)] * (int)pow(power.first, power.second - 1) * (power.first - 1);
		}
	}
	sort(phi+2, phi+n+1);
	cout << 1 + accumulate(phi+2, phi+k+3, 0LL);
}