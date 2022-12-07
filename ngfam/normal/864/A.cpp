#include <bits/stdc++.h>

using namespace std;

const int N = 101;

int n;
int a[N];
int f[N][N];
int pr[N][N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d", &n);

	for(int i = 1; i <= n; ++i){
		int x;
		scanf("%d", &x);
		++a[x];
	}

	for(int i = 1; i <= 100; ++i){
		for(int j = i + 1; j <= 100; ++j){
			if(a[i] == a[j] && a[i] + a[j] == n){
				cout << "YES" << endl << i << " " << j;
				exit(0);
			}
		}
	}

	cout << "NO";
	return 0;
}