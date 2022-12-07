#include <bits/stdc++.h>

using namespace std;

const int N = 80, mod = 1e9 + 7, M = 1 << 20;

int f[N][(1 << 20) + 10], n, a[N], fine[(1 << 20) + 10];
char s[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d%s", &n, s + 1);
	for(int i = 1; i <= n; ++i){
		a[i] = s[i] - '0';
		f[i][0] = 1;
	}

//	cout << a[1] << endl;

	f[0][0] = 1;

	for(int i = 0; i < n; ++i){
		for(int mask = 0; mask < (1 << 20); ++mask){
			if(f[i][mask] == 0) continue;
			
//			cout << i << " " << bitset<5>(mask) << " " << f[i][mask] << " : " << endl;

			int val = 0;
			for(int k = i + 1; k <= n; ++k){
	
				val = (val << 1) + a[k];
			//	cout << i << " " << k << " " << val << endl;
				if(val > 20) break;

				if(val == 0 || val > 20) continue;

				int newmask = mask | (1 << (val - 1));
			     //   if(newmask > M) cerr << val; 
			        //cout << k << " " << newmask << " " << val << endl;
				f[k][newmask] += f[i][mask];
				if(f[k][newmask] >= mod) f[k][newmask] -= mod;
			}
		}	
	}

//	cout << f[1][1] << endl;

//	return 0;

	fine[1] = 1;
	for(int i = 2; i < (1 << 20); ++i){
		fine[i] = (fine[i >> 1] && (i & 1));
	}

	int ans = 0;

	for(int j = 1; j <= n; ++j){
		for(int i = 0; i < (1 << 20); ++i){
			if(fine[i]){
		        	//cout << bitset<20>(i) << endl;
				ans += f[j][i];	
				if(ans >= mod) ans -= mod;
			}
		}
	}

	cout << ans;

	return 0;
}