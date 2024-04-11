#include <bits/stdc++.h>

using namespace std;

const int N = 1550;

int n, m;
int a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int ans = 0;

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		for(int j = i - 1; j >= 1; --j){
			if(a[j] > a[i]) ans = 1 - ans;
		}
	}

	scanf("%d", &m);


	while(m--){
		int l, r;
		scanf("%d%d", &l, &r);

		int len = r - l + 1;


		long long cnt = 1LL * len * (len - 1) / 2;


		if(cnt % 2) ans = 1 - ans;

		if(ans) puts("odd");
		else puts("even"); 
	}

	return 0;
}