#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
using namespace std;

int mod = 1e9 + 7;
int powmod(int a, int b){
	int res = 1;
	while(b){
		if(a % 2){
			res = (res * a) % mod;
		}
		b /= 2;
		a = (a * a) % mod;
	}
	return res;
}

int A[200001], B[200001];
vector<pair<int, int>> vp;
	
int n, t;
	
bool okay(int x){
	// cout << "test" << ' ' << x << endl;
	vector<int> time;
	for(int i = 0; i < n; i++){
		if(vp[i].first >= x){
			time.push_back(vp[i].second);
		}
	}
	sort(time.begin(), time.end());
	if(time.size() < x) return false;
	int T = 0;
	for(int i = 0; i < x; i++){
		T += time[i];
	}
	// cout << T << ' ' << t << endl;
	return T <= t;
}

void gen(int x){
	// cout << x << endl;
	vector<pair<int, int>> vp;
	for(int i = 0; i < n; i++){
		if(A[i] >= x){
			vp.push_back({B[i], i});
		}
	}
	sort(vp.begin(), vp.end());
	cout << x << endl;
	cout << x << endl;
	for(int i = 0; i < x; i++){
		cout << vp[i].second + 1 << ' ';
	}
	cout << endl;
}

void sub(){
	cin >> n >> t;
	for(int i = 0; i < n; i++){
		cin >> A[i] >> B[i];
	}
	for(int i = 0; i < n; i++){
		vp.push_back({A[i], B[i]});
	}
	sort(vp.begin(), vp.end());
	int l = 0, r = n + 1;
	while(l != r){
		int mid = (l + r + 1) / 2;
		if(okay(mid)){
			l = mid;
		}else{
			r = mid - 1;
		}
	}
	gen(l);
}

int32_t main(){
	int t = 1;
	// cin >> t;
	while(t--){
		sub();
	}
}