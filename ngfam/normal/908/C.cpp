#include <bits/stdc++.h>

using namespace std;

const int N = 1001;

int n, r;
int x[N];
double ans[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n >> r;
	for(int i = 1; i <= n; ++i){
		cin >> x[i];
	}

	ans[1] = r;
	cout << fixed << setprecision(6);

	for(int i = 2; i <= n; ++i){
		ans[i] = r;
		for(int j = i - 1; j >= 1; --j){
			if(abs(x[i] - x[j]) > r + r) continue;
			
			ans[i] = max(ans[i], abs(ans[j] + sqrt(4 * r * r - (x[i] - x[j]) * (x[i] - x[j]))));
		}
	}


	for(int i = 1; i <= n; ++i){
		cout << ans[i] << " ";
	}

	return 0;
}