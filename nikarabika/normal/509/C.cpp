#include <bits/stdc++.h>

using namespace std;

typedef vector<int> Bignum;

const int maxn = 400 + 85 - 69;
int s[maxn], b[maxn];
int n;

Bignum next(Bignum x, int sod){
	for(int i = x.size() - 1; i >= 0; i--)
		s[i] = s[i + 1] + x[i];
	for(int i = 0; i < x.size(); i++){
		for(int d = x[i] + 1; d <= 9; d++){
			if(sod - (s[i + 1] + d) >= 0 and sod - (s[i + 1] + d) <= 9 * i){
				x[i] = d;
				int val = sod - (s[i + 1] + d);
				int p = 0;
				while(p < i){
					x[p] = min(val, 9);
					val = max(0, val - 9);
					p++;
				}
				return x;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> b[i];
	vector<int> a(400, 0);
	for(int i = 0; i < n; i++){
		a = next(a, b[i]);
		int p = a.size() - 1;
		while(p > 0 and a[p] == 0) p--;
		while(p >= 0) cout << a[p--];
		cout << '\n';
	}
	return 0;
}