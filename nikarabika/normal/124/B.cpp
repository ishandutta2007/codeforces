#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

const int maxn = 10;
LL a[maxn][maxn];
LL fact = 1;
LL n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= k; i++)
		fact *= i;
	int p[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for(int i = 0; i < n; i++){
		LL x;
		cin >> x;
		int p = k - 1;
		while(x){
			a[i][p--] = x % 10;
			x /= 10;
		}
	}
	LL ans = 1e9;
	for(int cnt = 0; cnt < fact; cnt++){
		LL Max = -10, Min = 1e9;
		for(int i = 0; i < n; i++){
			LL num = 0;
			for(int j = 0; j < k; j++)
				num = num * 10 + a[i][p[j]];
			if(num > Max)
				Max = num;
			if(num < Min)
				Min = num;
		}
		next_permutation(p, p + k);
		ans = min(ans, Max - Min);
	}
	cout << ans << endl;
	return 0;
}