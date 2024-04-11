#include <bits/stdc++.h>

using namespace std;

const int N = 2222;

int n, a[N], cnt[N], total, m;

int main(){
	#ifndef ONLINE_JUDGE
		freopen("0.inp", "r", stdin);
		freopen("0.out", "w", stdout);	
	#endif

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		if(a[i] <= m) ++cnt[a[i]];
	}

	int val = n / m, cur = 1, ans = 0;

//	cout << val << endl;


	for(int i = 1; i <= n; ++i){
		while(cur <= m && cnt[cur] >= val) { ++cur; };			
		if(cur > m) break;

		int band = a[i];
		if(band > m || cnt[band] > val){
		 	++ans;
		 	a[i] = cur;
		 	if(band <= m) --cnt[band];
		 	++cnt[cur];
		}
	}


	cout << val << " " << ans << endl;
	for(int i = 1; i <= n; ++i){
		cout << a[i] << " ";
	}
}