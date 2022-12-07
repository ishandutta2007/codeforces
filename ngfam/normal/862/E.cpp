#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int M = 320;

int n, m, q;
int cnt[N];
long long a[N];
long long b[N];
long long f[N];
long long Sum[N][2];


int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d%d", &n, &m, &q);

	long long sum = 0;

	for(int i = 1; i <= n; ++i){
		scanf("%lld", a + i);
		if(i % 2 == 1){
			sum += a[i];
		}
		else{
			sum -= a[i];
		}
	}


	for(int j = 1; j <= m; ++j){
		scanf("%lld", b + j);
		Sum[j][j % 2] -= b[j];
		Sum[j][1 - (j % 2)] += b[j];
	}

	for(int j = m; j >= 0; --j){
		Sum[j][0] += Sum[j + 1][0];
		Sum[j][1] += Sum[j + 1][1];
	}

	set < long long > lst;

	for(int i = 0; i <= m - n; ++i){
		int x = 1 + i;
		int mod;
		if(n % 2 == 0){
			mod = (x + n) % 2;
		}
		else{
			mod = 1 - (x + n) % 2;
		}
		f[i] = Sum[x][x % 2] - Sum[x + n][mod] + sum;
		lst.insert(f[i]);
	}

	long long Add = 0;

	for(int i = 0; i <= q; ++i){
		if(i > 0){
			int l, r, t;
			scanf("%d%d%d", &l, &r, &t);
			if((r - l + 1) % 2){
				if(l % 2 == 1) Add += t;
				else Add -= t;
			}
		}
		set < long long > :: iterator it = lst.upper_bound(-Add);
		long long ans = 1e18;
		if(it != lst.end()){
			ans = min(ans, abs(*it + Add));
		}
		if(it != lst.begin()){
			--it;
			ans = min(ans, abs(*it + Add));
		}
		printf("%lld\n", ans);
	}

	return 0;
}