#include <bits/stdc++.h>
#define int long long
#define fi first
#define se second
#define inf (1LL << 60)
using namespace std;

int A[1000001];
bool exist[1000001];
int ps[1000001];
void solve(){
	cin.tie(0); cout.tie(0);
	int n, c;
	cin >> n >> c;
	for(int i = 1; i <= c; i++){
		exist[i] = false;
	}
	for(int i = 0; i <= c; i++){
		ps[i] = 0;
	}
	
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	sort(A, A + n);
	for(int i = 0; i < n; i++){
		exist[A[i]] = true;
	}
	
	for(int i = 1; i <= c; i++){
		ps[i] = ps[i - 1] + exist[i];
	}
	
	// int sq = min(1000, n);
	for(int k = 1; k <= c; k++){
		if(!exist[k]){
			for(int y = 1; y <= c / k; y++){
				if(exist[y] && ps[min(c, k * y - 1)] != ps[min(c, (k + 1) * y - 1)]){
					cout << "No" << endl;
					return;
				}
			}
		}
	}
	cout << "Yes" << endl;
}

int32_t main(){
	int t;
	cin >> t;
	// t = 1;
	while(t--){
		solve();
	}
}