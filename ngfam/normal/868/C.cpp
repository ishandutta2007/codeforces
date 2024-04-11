#include <bits/stdc++.h>

using namespace std;


const int N = 1e5 + 10;

int n, k;
int a[N];
int x[N];
int cnt[20];

void check(){
	int lost[5];
	memset(lost, 0, sizeof lost);

	int tot = 0;

	for(int i = 0; i < (1 << k); ++i){
		tot += x[i];

	//	cout << i << " : " << x[i] << " | ";

		for(int j = 0; j < 4; ++j){
			if(i & (1 << j)) lost[j] += x[i];
		}
	}



	if(tot == 0) return;

	for(int i = 0; i < 4; ++i){
		if(lost[i] > tot / 2) return;
	}

	cout << "yes";
	exit(0);
}

void backtrack(int i, int c){
	if(i == (1 << k)) check();
	else{
		for(int t = 0; t <= min(cnt[i], c); ++t){
			x[i] = t;
			backtrack(i + 1, c - t);
			x[i] = 0;
		}
	}	
}

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &k);




	for(int i = 1; i <= n; ++i){
		for(int j = 0; j < k; ++j){
			int x;
			scanf("%d", &x);
			if(x == 1) a[i] |= (1 << j);


		}
	//		cout << a[i] << endl;
			++cnt[a[i]];
	}


	backtrack(0, 6);

	cout << "no";

	return 0;
}