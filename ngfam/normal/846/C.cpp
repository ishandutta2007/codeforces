#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N];

long long f[N];
long long sum[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i); 
		sum[i] = sum[i - 1] + a[i];
	}

	int x, y, z;

	long long ans = -1e18;

	int curr = 1;
	f[1] = 1;
	for(int i = 2; i <= n + 1; ++i){
		
		f[i] = curr;	
		if(sum[i - 1] > sum[curr - 1]){
			curr = i;
		}
	}

	for(int i = 1; i <= n + 1; ++i){
		for(int j =	i; j <= n + 1; ++j){
			int c = f[i];

			long long calc = sum[c - 1] - (sum[i - 1] - sum[c - 1]) + sum[j - 1] - sum[i - 1] - (sum[n] - sum[j - 1]);
			if(calc > ans){
				ans = calc;
				x = c;
				y = i;
				z = j;
			}
		}
	}


	cout << x - 1 << " " << y - 1 << " " << z - 1;

	return 0;
}