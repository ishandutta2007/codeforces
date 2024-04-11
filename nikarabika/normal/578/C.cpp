#include <bits/stdc++.h>

using namespace std;

typedef long double LD;

const int maxn = 2e5 + 85 - 69;
int n;
LD a[maxn];

LD get(LD d){
	LD max_poor = a[0] - d, min_poor = a[0] - d;
	LD max_sum = 0, min_sum = 0;
	LD cur_sum = 0;
	for(int i = 0; i < n; i++){
		cur_sum += a[i] - d;
		min_poor = min(min_poor, cur_sum - max_sum);
		max_poor = max(max_poor, cur_sum - min_sum);
		max_sum = max(max_sum, cur_sum);
		min_sum = min(min_sum, cur_sum);
	}
	return max(abs(min_poor), abs(max_poor));
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	LD lo = -2e4, hi = +2e4;
	for(int i = 0; i < 110; i++){
		LD mid1 = lo + (hi - lo) / 3.;
		LD mid2 = mid1 + (hi - lo) / 3.;
		LD an1 = get(mid1), an2 = get(mid2);
		if(an1 < an2)
			hi = mid2;
		else
			lo = mid1;
	}
	cout.precision(12);
	cout << fixed << get(lo) << endl;
	return 0;
}