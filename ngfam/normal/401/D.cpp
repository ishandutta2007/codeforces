#include <bits/stdc++.h>

using namespace std;

const int N = 1 << 18, M = 150;

long long f[N][M], cnt[M], ifx[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);	
		freopen("1.out", "w", stdout);
	#endif

	string number; int m;
	cin >> number >> m;
	
//	ok[0][0] = 1;
	
	int n = number.size();
	f[0][0] = 1;

//	cout << n << endl;
		
	for(int mask = 0; mask < (1 << n) - 1; ++mask){
		for(int mod = 0; mod < m; ++mod){
			if(f[mask][mod] > 0){
				for(int i = 0; i < n; ++i){
					if(mask & (1 << i)) continue;
					if(mask == 0 && number[i] == '0') continue;
					
					int newmask = mask | (1 << i);
					int newmod = (mod * 10 + (number[i] - '0')) % m; 

			//		cout << bitset<7>(mask) << " " << bitset<7>(newmask) << " " << mod << " " << newmod << " "  << i << " " << number[i] << endl;

					f[newmask][newmod] += f[mask][mod];
				}
			}
		}			        		
        }
       // cout << f[1 << 6][0] << endl;

       	ifx[0] = 1;                  
        for(int i = 1; i <= n; ++i){
        	ifx[i] = ifx[i - 1] * i;
        }


       	for(int i = 0; i < n; ++i){
       		++cnt[number[i] - '0'];
       	}

       	long long divide = 1;
	for(int i = 0; i <= 9; ++i){
		divide *= ifx[cnt[i]];	
	}
	                            
        cout << f[(1 << n) - 1][0] / divide;
}