#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 1;
long long int F[maxn], m;
int n;

int main(){
	F[1] = 1;
	for(int i = 2; i <= 50; i++)
		F[i] = 2 * F[i - 1];
	cin >> n >> m;
	int ans[n];
	int t = n;
	int a = 1, p = 0, q = n - 1;
	while(m > 1){
		if(m > F[n - 1]){
			ans[q--] = a;
			a ++;
			m -= F[n - 1];
		}
		else{
			ans[p ++] = a;
			a ++;
		}
		n--;
	}
	while(p <= q){
		ans[p++] = a;
		a++;
	}
	for(int i = 0; i < t; i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}