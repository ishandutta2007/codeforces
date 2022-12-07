#include <bits/stdc++.h>

using namespace std;

const int N = 550;

struct Broken{
	int x;
	int y;
	int t;

	void read(){
		scanf("%d%d%d", &x, &y, &t);
	}
}a[N * N];

bool cmp(Broken u, Broken v){
	return u.t < v.t;
}

int n, m, k, q;
int arr[N][N];
int sum[N][N];



int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d%d", &n, &m, &k, &q);

	for(int i = 1; i <= q; ++i){
		a[i].read();
	}

	sort(a + 1, a + q + 1, cmp);

	int low = 1, high = q, ans = q + 1;

	while(low <= high){
		int val = (low + high) >> 1;
		memset(arr, 0, sizeof arr);
		memset(sum, 0, sizeof sum);
		for(int i = 1; i <= val; ++i){
			arr[a[i].x][a[i].y] = 1;
		}

		bool able = false;

		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + arr[i][j];
				if(min(i, j) >= k){
					int calc = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
					if(calc == k * k){
					
						able = true;
					} 
				}
			}
		}
		if(able){
			ans = val;
			high = val - 1;
		}
		else{
			low = val + 1;
		}
	}
	if(ans == q + 1){
		cout << -1;
	}
	else{
		cout << a[ans].t;
	}

	return 0;
}