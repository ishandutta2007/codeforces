#include <bits/stdc++.h>
using namespace std;

set<int> S;
bool on[1001];
bool state[1001];
bool used[1001];
int32_t main(){
	int n;
	cin >> n;
	if(n <= 3){
		cout << 0 << endl;
		return 0;
	}
	int _max = 0, k = -1;
	for(int i = 2; i <= n; i++){
		int v = n / i * (i - 1) + max(0, n % i - 1) - (i - 1);
		if(v >= _max){
			_max = v;
			k = i;
		}
	}
	
	_max += k - 1;
	for(int i = 0; i < n / k; i++){
		for(int j = 0; j < k - 1; j++){
			on[i * k + j + 1] = 1;
		}
	}
	for(int i = n / k * k; i < n - 1; i++){
		on[i + 1] = 1;
	}
	
	int ttl = 0;
	for(int i = 1; i <= n; i++){
		if(on[i]){
			ttl++;
		}
	}
	
	int prev = 0;
	while(ttl >= n - _max){
		prev = ttl;
		fill(used, used + 1001, false);
		int cnt = 0;
		cout << k << ' ';
		for(int i = 1; i <= n && cnt < k; i++){
			if(!state[i] && on[i]){
				state[i] = true;
				used[i] = true;
				cout << i << ' ';
				ttl--;
				cnt++;
			}
		}
		
		for(int i = 1; i <= n && cnt < k; i++){
			if(!used[i]){
				cout << i << ' ';
				cnt++;
			}
		}
		cout << endl;
		int v;
		cin >> v;
		for(int i = 0; i < k; i++){
			int l = (v - 1 + i) % n + 1;
			ttl += state[l] && on[l];
			state[l] = 0;
		}
		if(prev == ttl){
			break;
		}
//		cout << prev << ' ' << ttl << endl;
	}
	cout << 0 << endl;
	return 0;
}