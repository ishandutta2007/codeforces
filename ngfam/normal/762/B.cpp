#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 10;

pair < int, int > mouse[N];

bool done[N];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("1.inp", "r", stdin);
		freopen("1.out", "w", stdout);
	#endif

	int a, b, c, olda, oldb, oldc;
	scanf("%d%d%d", &a, &b, &c);

	olda = a; oldb = b; oldc = c;

	int n; scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		int price; scanf("%d", &price);
		char type[10]; scanf("%s", type);

		if(type[0] == 'P'){
			mouse[i].second = 1;
		}
		else{
			mouse[i].second = 2;
		}
		mouse[i].first = price;
	}

	long long ans = 0;

	sort(mouse + 1, mouse + n + 1);
	for(int i = 1; i <= n; ++i){
		if(mouse[i].second == 1){
			if(b > 0){
				ans += mouse[i].first;
				--b;
				done[i] = 1;		
			}
		}
		else{
			if(a > 0){
				ans += mouse[i].first;
				--a;
				done[i] = 1;
			}
		}
	}

	for(int i = 1; i <= n; ++i){
		if(done[i]) continue;
		if(c > 0){
			ans += mouse[i].first;
			--c;
		}
	}

	cout << olda + oldb + oldc - a - b - c << " " << ans;

	return 0;
}