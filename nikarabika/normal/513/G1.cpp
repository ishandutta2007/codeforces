#include <bits/stdc++.h>

using namespace std;

const int maxn = 10;
int n, m;
int a[maxn];
float x;

int C(){
	int ans = 0;
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				ans ++;
	return ans;
}

double F(int k){
	if(k == 0)
		return (double)C();
	double ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			reverse(a + i, a + j + 1);
			ans += 2.0 * F(k - 1) / x;
			reverse(a + i, a + j + 1);
		}
	}
	return ans;
}

int main(){
	cin >> n >> m;
	x = (double)n * (n + 1.0);
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout.precision(15);
	cout << fixed << F(m) << endl;
	return 0;
}