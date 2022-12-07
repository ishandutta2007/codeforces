#include <bits/stdc++.h>

using namespace std;

const int N = 333;

int a[N], n, cur, b[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	scanf("%d", &n);

	int cnt = 0;

	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		cnt += (a[i] > 0);
	}

	cur = 1; bool put = false;

	int now = 0;

	while(now < cnt){     

		if(put == false){
			if(b[cur] < a[cur]){
				++b[cur];
				printf("P");

				if(b[cur] == a[cur]){
					++now;
				}

				put = true;
				continue;
			}
		}
		put = false;

		if(b[cur - 1] == a[cur - 1] && cur < n){
			++cur;
			printf("R");
			continue;

		}

		if(b[cur - 1] < a[cur - 1] || cur == n){
			printf("L");
			--cur;
			continue;
		}

	}
}