#include <bits/stdc++.h>
#define int long long
#define Max(a, b, c) max(max(a, b), c)
#define Min(a, b, c) min(min(a, b), c)
using namespace std;
typedef long long ll;

int ex[32];

int A[100000];
int32_t main(){
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> A[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 30; j++){
			if(A[i] & (1 << j)){
				ex[j]++;
			}
		}
	}
	int x = 0;
	for(int i = 0; i <= 30; i++){
		if(ex[i] <= 1){
			x += (1 << i);
		}
	}
	int _max = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		if((A[i] & x) >= _max){
			_max = A[i] & x;
			ans = i;
		}
	}
	swap(A[ans], A[0]);
	for(int i = 0; i < n; i++){
		cout << A[i] << ' ';
	}
}