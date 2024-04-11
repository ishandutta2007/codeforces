#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
 
int p[200000];
bool isBig[200000];
int32_t main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> p[i];
	}
	
	int _max = (n + n - k + 1) * (k) / 2;
	
	vector<int> A;
	for(int i = 0; i < n; i++){
		isBig[i] = p[i] >= n - k + 1;
		if(p[i] >= n - k + 1){
		    A.push_back(i);
		}
		
	}
	
	
	int cnt = 1;
	for(int i = 0; i < A.size() - 1; i++){
		cnt = (cnt * (A[i + 1] - A[i])) % 998244353;
	}
	
	cout << _max << ' ' << cnt << endl;
}