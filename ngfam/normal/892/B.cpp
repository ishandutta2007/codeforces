#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n;
int a[N];
int add[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);

		int x = max(1, i - a[i]);
		++add[x];
		--add[i];
	}

	int ans = 0;

	for(int i = 1; i <= n; ++i){
		add[i] += add[i - 1];
		ans += (add[i] == 0);
	}

	cout << ans;

	return 0;
}