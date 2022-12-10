#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

LL a[2][2], mul[2], f2[2], f3[2];
LL G;

int get(LL x, LL q){
	int cnt = 0;
	while(x % q == 0)
		x /= q, cnt++;
	return cnt;
}

bool has(LL x){
	while(x % 2 == 0)
		x /= 2;
	while(x % 3 == 0)
		x /= 3;
	if(x == 1)
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin >> a[0][0] >> a[0][1]
		>> a[1][0] >> a[1][1];
	for(int i = 0; i < 2; i++)
		mul[i] = a[i][0] * a[i][1];
	G = __gcd(mul[0], mul[1]);
	if(has(mul[0] / G) or has(mul[1] / G)){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < 2; i++)
		f3[i] = get(mul[i], 3);
	int d = f3[0] - f3[1], ans = 0;
	ans += abs(d);
	if(d > 0){
		while(d and a[0][0] % 3 == 0)
			a[0][0] /= 3, a[0][0] *= 2, d--;
		while(d and a[0][1] % 3 == 0)
			a[0][1] /= 3, a[0][1] *= 2, d--;
	}
	else{
		d = -d;
		while(d and a[1][0] % 3 == 0)
			a[1][0] /= 3, a[1][0] *= 2, d--;
		while(d and a[1][1] % 3 == 0)
			a[1][1] /= 3, a[1][1] *= 2, d--;
	}
	for(int i = 0; i < 2; i++)
		mul[i] = a[i][0] * a[i][1];
	G = __gcd(mul[0], mul[1]);
	for(int i = 0; i < 2; i++)
		f2[i] = get(mul[i] / G, 2);
	d = f2[0] - f2[1];
	ans += abs(d);
	if(d > 0){
		while(d and a[0][0] % 2 == 0)
			a[0][0] /= 2, d--;
		while(d and a[0][1] % 2 == 0)
			a[0][1] /= 2, d--;
	}
	else{
		d = -d;
		while(d and a[1][0] % 2 == 0)
			a[1][0] /= 2, d--;
		while(d and a[1][1] % 2 == 0)
			a[1][1] /= 2, d--;
	}
	cout << ans << endl;
	cout << a[0][0] << ' ' << a[0][1] << endl
		<< a[1][0] << ' ' << a[1][1] << endl;
	return 0;
}