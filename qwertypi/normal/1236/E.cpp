#include <bits/stdc++.h>
#define int long long
typedef long long ll;
using namespace std;
int A[200000];
 
map<int, int> cnt;
int32_t main(){
	cnt.clear();
	int n, k;
	cin >> n >> k;
	if(n == 1){
	    cout << 0;
	    return 0;
	}
	for(int i = 0; i < k; i++){
		cin >> A[i];
	}
	int dx = 0;
	for(int i = 0; i < n; i++){
		cnt[i+1] = 1;
	}
	for(int i = 0; i < k; i++){
		if(A[i] == n){
			int temp = 0;
			if(cnt.find(A[i] - dx) != cnt.end()){
				temp += cnt[A[i] - dx];
				cnt.erase(A[i] - dx);
			}
			if(cnt.find(A[i] - dx - 1) != cnt.end()){
				temp += cnt[A[i] - dx - 1];
				cnt.erase(A[i] - dx - 1);
			}
			cnt[A[i] - dx - 2] += temp;
			dx++;
		}else{
			if(cnt.find(A[i] - dx - 1) != cnt.end()){
				int temp = cnt[A[i] - dx - 1];
				cnt.erase(A[i] - dx - 1);
				cnt[A[i] - dx - 2] += temp;
			}
			int temp = cnt[n - dx];
			cnt.erase(n - dx);
			cnt[n - dx - 1] += temp;
			dx++;
		}
	}
	int _temp = cnt[n - dx];
	cnt.erase(n - dx);
	cnt[n - dx - 1] += _temp;
	dx++;
	ll res = 0;
	for(auto i : cnt){
		res += (ll)i.second * i.first;
	}
	ll ans = res;
	dx = 0;
	cnt.clear();
	for(int i = 0; i < n; i++){
		cnt[i+1] = 1;
	}
	for(int i = 0; i < k; i++){
		if(A[i] == 1){
			int temp = 0;
			if(cnt.find(A[i] + dx) != cnt.end()){
				temp += cnt[A[i] + dx];
				cnt.erase(A[i] + dx);
			}
			if(cnt.find(A[i] + dx + 1) != cnt.end()){
				temp += cnt[A[i] + dx + 1];
				cnt.erase(A[i] + dx + 1);
			}
			cnt[A[i] + dx + 2] += temp;
			dx++;
		}else{
			if(cnt.find(A[i] + dx + 1) != cnt.end()){
				int temp = cnt[A[i] + dx + 1];
				cnt.erase(A[i] + dx + 1);
				cnt[A[i] + dx + 2] += temp;
			}
			int temp = cnt[1 + dx];
			cnt.erase(1 + dx);
			cnt[1 + dx + 1] += temp;
			dx++;
		}
	}
	_temp = cnt[dx + 1];
	cnt.erase(dx + 1);
	cnt[dx + 2] += _temp;
	dx++;
	res = 0;
	for(auto i : cnt){
		res += (ll)i.second * i.first;
	}
	cout << ans + n * 2 * (k + 1) - res + n << endl;
}