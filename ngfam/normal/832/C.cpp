#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

int n, s;
int a[N];
double p[N];
double v[N];
int Left[N];
int Right[N];

void upd(int *x, int l, int r){
	++x[l];
	--x[r + 1];
}

bool check(double x){
	memset(Left, 0, sizeof Left);
	memset(Right, 0, sizeof Right);
	for(int i = 1; i <= n; ++i){
		if(a[i] == 1){
			if(p[i] / v[i] <= x){
				upd(Left, 1, N - 1);
			}
			else{
				int low = p[i], high = N - 2, ans = p[i] - 1;
				while(low <= high){
					double val = (low + high) >> 1;
					double timer = (val - p[i]) / (s - v[i]);
					//cout << val << " " << timer << " " << val - p[i] << " " << s - v[i] << endl;
					if(timer > x){
						high = val - 1;
						continue;
					}
					if(v[i] * timer + (s + v[i]) * (x - timer) >= p[i]){
						low = val + 1;
						ans = val;
						continue;
					}
					else{
						high = val - 1;
						continue;
					}
				}
				upd(Left, p[i], ans);
				//cout << ans << endl;
				//cout << double(ans - p[i]) / double(s - v[i]) << endl;
			}
		}
		else{
			if((N - p[i] - 2) / v[i] <= x){
				upd(Right, 1, N - 1);
			}
			else{
				int low = 1, high = p[i], ans = p[i] + 1;
				while(low <= high){
					double val = (low + high) >> 1;
					double timer = (p[i] - val) / (s - v[i]);
					if(timer > x){
						low = val + 1;
						continue;
					}
					if(p[i] + v[i] * timer + (s + v[i]) * (x - timer) >= N - 2){
						high = val - 1;
						ans = val;
					}
					else{
						low = val + 1;
					}
				}
				upd(Right, ans, p[i]);
				//cout << ans << endl;
			}
		}
	}
	for(int i = 1; i < N; ++i){
		Left[i] += Left[i - 1];
		Right[i] += Right[i - 1];
		if(Left[i] > 0 && Right[i] > 0){
			return true;
		}
	}
	return false;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
	#endif
	scanf("%d%d", &n, &s);
	for(int i = 1; i <= n; ++i){
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[i] = z;
		p[i] = x;
		v[i] = y;
	}
	//cout << check(400) << endl;
	//return 0;
	double low = 0, high = N - 2, ans = N - 2;
	for(int Bs = 1; Bs <= 45; ++Bs){
		double val = (low + high) / 2;
		if(check(val)){
			high = val;
			ans = val;
		}
		else{
			low = val;
		}
	}
	cout << fixed << setprecision(7) << ans;
	return 0;
}