#include <bits/stdc++.h>

using namespace std;
               
const int N = 1e7 + 1;

int n, x, y;

long long a[N], s[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif
	
	scanf("%d%d%d", &x, &y, &n);
	
	a[1] = s[1] = x;
	for(int i = 2; i < N; ++i){
		a[i] = a[i - 1] + y;
		s[i] = a[i] + s[i - 1];	
	}

	while(n--){
		int l, t, m;
		scanf("%d%d%d", &l, &t, &m);
		int low = l, high = t + 1, ans = -1;
		while(low <= high){
			int val = (low + high) >> 1;
			if(s[val] - s[l - 1] > 1LL * t * m || a[val] > t){
				high = val - 1;	
			}
			else{
		  	low = val + 1;
		  	ans = val;
			}
		}
		printf("%d\n", ans);
//		cerr << s[ans] - s[l - 1] << " " << (a[ans] + a[l]) * (ans - l + 1) / 2 << " " << t * m << endl;
	}

	return 0;
}