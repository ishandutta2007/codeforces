#include <bits/stdc++.h>
#define hash _riven_

using namespace std;

typedef long long llint;

const llint N = 5555, mod = 1e9 + 7;

string a;

int f[N][N], n, cur[N], s[N][N];

llint hash[N], lt[N], hash2[N];


llint get(int i, int j){
	return (hash[j] - hash[i - 1] * lt[j - i + 1] + mod * mod) % mod;
}

bool cmp(int i, int j){
	int low = 0, high = j - i - 1, ans = 0;
	while(low <= high){
		int val = (low + high) >> 1;

	//	cout << low << " " << high << " " << val << endl;

		if(get(i, i + val) == get(j, j + val)){
			ans = max(ans, val + 1);
			low = val + 1;
		}
		else{
			high = val - 1;
		}
	}

	
	if(i + ans == j) return 0;
	return a[j + ans] > a[i + ans];
}

void add(int &u, int v){
	u += v;
	if(u >= mod) u -= mod;
}

void sub(int &u, int v){
 	u -= v;
 	if(u <= mod) u += mod;
} 

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	cin >> n >> a;
	
	a = char('0' - 1) + a;
	
	lt[0] = 1;

	for(int i = 1; i <= n; ++i){
		hash[i] = ((hash[i - 1] * 26) + a[i] - '0') % mod;
		lt[i] = (lt[i - 1] * 26) % mod;
	}

//	cout << lt[2] << endl;
//	cout <<	cmp(1, 5);
//	return 0;

//	cout << cmp(1, 4) << endl;

//	cout << cmp(6, 7) << endl;
  //	return 0;
	s[0][0] = 1;

	for(int i = 1; i <= n; ++i){
		for(int j = i; j >= 1; --j){
		        	int len = i - j + 1;

			if(a[j] != '0'){

		
			add(f[i][len], s[j - 1][min(j - 1, len - 1)]);

			if(j > len){
				if(cmp(j - len, j)){
					add(f[i][len], f[j - 1][len]);
				//	cout << j - len << " " << j << " " << a.substr(j - len, len) << " " << a.substr(j, len) << endl;
				}
			} 
			}
			s[i][len] = s[i][len - 1];
			add(s[i][len], f[i][len]);
			
			
		}
	}

/*	for(int i = 1; i <= n; ++i){
		cout << i << " " << f[n][i] << endl;
	}         */
	cout << s[n][n];

//	cout << cmp(1, 5) << endl;
               //cout << s[n][n];
}