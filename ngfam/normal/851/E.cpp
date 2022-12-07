#include <bits/stdc++.h>

using namespace std;

int cnt[100];
int a[110];
int Solve[110];
int dp[110][110][2];

map < int, int > Add;
map < int, int > f;

int grundy(int x){
	if(f.count(x)){
		return f[x];
	}


	set < int > can;

	for(int h = 1; h <= 30; ++h){
		int mask = 0, least = 0;

		for(int i = 1; i <= 30; ++i){
			if(x & (1 << i)){
				if(i < h){
					mask |= 1 << i;
				}
				else if(i > h){
					mask |= 1 << (i - h);
				}
			}
		}

		if(mask != x) can.insert(grundy(mask));
	}
	int ans = 0;
	while(can.count(ans)){
		++ans;
	}
	return f[x] = ans;
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	int n, tot = 1;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);

		if(x != 1){
			tot = 0;
		}

	//	cout << x << " : " << endl;

		int old = x;
		for(int k = 2; k * k <= old; ++k){
			int val = 0;
			while(x % k == 0){
				++val;
				x /= k;
			}

		//	if(val > 0) cout << k << " " << val << endl;
			//++cnt[val];
			//cout << old << " " << val << endl;
			if(val > 0) Add[k] |= 1 << (val);
		}
		if(x > 1){

			Add[x] |= 2;
	//		cout << x << " " << 1 << endl;
		}
	}

	int ans = 0;

	for(map < int, int > :: iterator it = Add.begin(); it != Add.end(); ++it){
		ans ^= grundy(it -> second);
///		cout << it -> first << " " << it -> second << endl;
	}

	if(ans){
		cout << "Mojtaba";
	}
	else{
		cout << "Arpa";
	}

	return 0;
}