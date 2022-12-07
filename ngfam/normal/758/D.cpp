#include <bits/stdc++.h>

using namespace std;

const long long N = 100, base = 1e18;

long long pw[N], f[N][N], n;

string s;

long long mul(long long u, long long v){
	if(u > base / v) return base + 1;
	return u * v;
}

long long num(int fr, int to){
	long long ans = 0;
	for(int i = fr; i <= to; ++i){
		ans *= 10;
		ans += s[i] - '0';
		if(ans >= n) return -1;
	}
	return ans;
}

void upd(long long &a, long long b){
//	if(a == -1) a = b;
	if(a > b) a = b;
}

long long add(long long a, long long b){
	long long ans = a + b;
	if(ans > base) ans = base + 1;
	return ans;
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	cin >> n >> s;
	int sz = s.size(), lim = sz;

	pw[0] = 1;

	s = "0" + s;

	for(int i = 1; i <= sz; ++i){
		pw[i] = mul(pw[i - 1], n);
		if(pw[i] > base){
			lim = i - 1;
			break;
		}
	}

	//cout << pw[lim] << endl;


//	cout << mul(0, pw[4]);

//	return 0;
	


	for(int i = 0; i <= sz; ++i){
		for(int j = 0; j <= lim + 1; ++j){
			f[i][j] = base + 1;
		}
	}

	for(int i = 1; i <= lim + 1; ++i){
		f[0][i] = 0;
	}

	for(int i = 0; i < sz; ++i){
		for(int j = 1; j <= lim + 1; ++j){
			if(f[i][j] > base) continue;

			for(int k = i + 1; k <= sz; ++k){
				
				if(s[i + 1] == '0' && k > i + 1) break;

				long long curr = num(i + 1, k);
				if(curr == -1) break;
				long long calc = mul(curr, pw[j - 1]);
				if(calc > base) break;
				
				long long product = add(f[i][j], calc);
				if(product > base) break;

				//cout << i << " " << j << " " << f[i][j] << " " << i + 1 << " -> " << k << " " << curr << " " << calc << " " << product << " " << pw[j - 1] << " update for : " << k << " " << j - 1 << endl;

				upd(f[k][j - 1], product);
			}
		}	
	}

	cout << f[sz][0];

	return 0;
}