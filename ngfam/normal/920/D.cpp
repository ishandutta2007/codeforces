#include <bits/stdc++.h>

using namespace std;

const int N = 5050;

int n, k, V;
int a[N];
bool use[N];
bool f[N][N];
bool trace[N][N];

int main(){

	cin >> n >> k >> V;

	int sum = 0;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum += a[i];
	}

	if(sum < V){
		cout << "NO";
		return 0;
	}

	f[0][0] = 1;
	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < k; ++j){
			if(f[i - 1][j] == 0) continue;

			f[i][ (j + a[i]) % k ] = 1;
			trace[i][ (j + a[i]) % k ] = 1;

			f[i][j] = 1;
			trace[i][j] = 0;

		}
	}


	if(!f[n][V % k]){
		cout << "NO";
		return 0;
	}



	int M = V % k;

	for(int i = n; i >= 1; --i){
		if(trace[i][M]) {
			use[i] = 1;
			M = (M - a[i] % k + k) % k;
		}
	}

	cout << "YES" << endl;

	if(!use[1] && a[1]){
		cout << (a[1] + k - 1) / k << " " << 1 << " " << 2 << endl;
		a[2] += a[1];
		a[1] = 0;
	}

	for(int i = 2; i <= n; ++i){
		if(use[i]){
			int take = (a[i] + k - 1) / k;
			if(!take) continue;

			cout << take << " " << i << " " << 1 << endl;
			a[1] += a[i];
			a[i] = 0;
		}
		else{
			if(i == 2) continue;

			int take = (a[i] + k - 1) / k;
			if(!take) continue;

			cout << take << " " << i << " " << 2 << endl;
			a[2] += a[i];
			a[i] = 0;
		}
	}

	if(a[1] > V){
		cout << (a[1] - V) / k << " " << 1 << " " << 2 << endl;
	}
	else if(a[1] < V){
		cout << (V - a[1]) / k << " " << 2 << " " << 1 << endl;
	}


	return 0;
}