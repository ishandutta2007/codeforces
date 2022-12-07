#include <bits/stdc++.h>

using namespace std;

const int N = 2020;

int n;
int a[N];
int b[N];

set < int > x;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);
	for(int i = 1; i <= n; ++i){
		scanf("%d", a + i);
		x.insert(a[i]);
	}

	for(int i = 1; i <= n; ++i){
		scanf("%d", b + i);
		x.insert(b[i]);
	}

	int cnt = 0;



	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= n; ++j){
			if(x.count(a[i] ^ b[j])){
				++cnt;
			}
		}
	}

	if(cnt % 2 == 0) cout << "Karen";
	else cout << "Koyomi";

	return 0;
}