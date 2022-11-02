#include <iostream>
#include <algorithm>
#define inf (1 << 30)
#define m 998244353
using namespace std;
typedef long long ll;

ll factors[300];
ll n_pf(ll n){
	ll res = 1;
	if(n % 2 == 0){
		int cnt_2 = 1;
		while(n % 2 == 0){
			cnt_2++;
			n /= 2;
		}
		res *= cnt_2;
	}
	int i = 3;
	while(i * i <= n){
		if(n % i == 0){
			int cnt = 1;
			while(n % i == 0){
				cnt++;
				n /= i;
			}
			res *= cnt;
		}
		i += 2;
	}
	if(n != 1){
		return res * 2;
	}else{
		return res;
	}
}

int main(){
	int t;
	cin >> t;
	for(int i=0;i<t;i++){
		int n;
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> factors[i];
		}
		sort(factors, factors+n);
		ll ans = factors[0] * factors[n-1];
		if(n_pf(ans) != n + 2){
			cout << -1 << endl;
		}else{
			bool End = false;
			for(int i = 0; i < n; i++){
				if(ans % factors[i] != 0){
					cout << -1 << endl;
					End = true;
					break;
				}
			}
			if(!End){
				cout << ans << endl;
			}
		}
	}
	return 0;
}