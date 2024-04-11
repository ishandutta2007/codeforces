#include <bits/stdc++.h>

using namespace std;

const int N = 123456;

typedef long long llint;

llint f[N][4][10], a[4][N], base = -1e18, sum[N][10];

int n, tv[N][4][10], tv2[N][4][10]; 


void dwn(int i, int mask, int pos){	

	int j = tv[i][pos][mask];
	int m = tv2[i][pos][mask];

	int newi = i - 1;


	if(j < 0){
		j = -j;
		m = -m;
		--newi;

	}
	if(i != 1) dwn(newi, m, j);

	cout << i << "  " << bitset<3>(mask) << " at " << pos << endl;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);
	for(int i = 1; i <= 3; ++i){
		for(int j = 1; j <= n; ++j){
			scanf("%lld", &a[i][j]);
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= 3; ++j){
			for(int mask = 0; mask <= 8; ++mask){
				f[i][j][mask] = base;
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int mask = 1; mask <= 7; ++mask){
			for(int j = 0; j < 3; ++j){
				if(mask & (1 << j)){
					sum[i][mask] += a[j + 1][i];
				}
			}
		}
	}


	for(int i = 1; i <= 7; ++i){
		if(i == 5) continue;
		if((i & 1) == 0) continue;
		
		bitset<5> x(i);
		
		int last = 0;
		while(x[last + 1] == 1){
			++last;
		}
		++last;

		f[1][last][i] = sum[1][i];
		//cout << bitset<3>(i) << " " << sum[1][i] << endl;
	}

	for(int i = 2; i <= n; ++i){
		for(int mask = 1; mask <= 7; ++mask){
			if(mask == 5) continue;

			for(int j = 1; j <= 3; ++j){
				if((mask & (1 << (j - 1))) == 0){
					continue;				
				}

				for(int premask = 1; premask <= 7; ++premask){
					if(j == 2 && mask == 7) continue;
					
					if((premask & (1 << (j - 1))) == 0){
						continue;
					}

					bitset<5> x(mask << 1);

					int last = j;
					if(x[last - 1] == 0){
						while(x[last + 1] == 1){
							++last;
						}
					}
					else{
						while(x[last - 1] == 1){
							--last;
						}
					}

				//	if(mask == 7 && last == 2) cout << "YESS" << endl;

			//		cout << "from " << bitset<3>(premask) << " at " << j << " to " << bitset<3>(mask) << " at " << last << " " << f[i - 1][j][premask] + sum[i][mask] << endl;
					
					f[i][last][mask] = max(f[i][last][mask], f[i - 1][j][premask] + sum[i][mask]);
					if(f[i][last][mask] == f[i - 1][j][premask] + sum[i][mask]){
						tv[i][last][mask] = j;
						tv2[i][last][mask] = premask;		
					}
			
				}
				
			}
			for(int premask = 1; premask <= 7; ++premask){
				for(int pos = 1; pos <= 3; ++pos){
					if(pos == 2) continue;
					if((mask & (1 << (pos - 1))) == 0) continue;
					f[i][4 - pos][7] = max(f[i][4 - pos][7], sum[i - 1][7] + sum[i][7] + f[i - 2][pos][premask]);
					if(f[i][4 - pos][7] == sum[i - 1][7] + sum[i][7] + f[i - 2][pos][premask]){
						tv[i][4 - pos][7] = -pos;
						tv2[i][4 - pos][7] = -premask;
					}
				}
			}
		}
	}

	long long ans = base, avail;

	
	for(int mask = 1; mask <= 7; ++mask){
		if(mask & 4){
			ans = max(ans, f[n][3][mask]);
			if(ans == f[n][3][mask]){
				avail = mask;
			}		
		}
	}

	//dwn(n, avail, 3);

	cout << ans;

	return 0;
}