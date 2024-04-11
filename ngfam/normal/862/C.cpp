#include <bits/stdc++.h>

using namespace std;

const int N = 100101;

int n, x;
int a[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	scanf("%d%d", &n, &x);

	int curr = 0;

	if(n == 1){
		cout << "YES\n" << x;
		return 0;
	}

	if(n == 2){
		if(x != 0) cout << "YES\n" << x << " " << 0 << endl;
		else puts("NO");
		return 0;
	}

	for(int i = 1; i <= n - 2; ++i){
		a[i] = i;	
		curr ^= a[i];
	}

	int c = curr ^ x;
	if(c == 0){
		a[1] = (1 << 19);
		a[n] = (1 << 18);
		a[n - 1] = (1 << 19) + (1 << 18) + 1;
	}else if(c <= n - 2){
		a[c] = (1 << 19);
		a[n] = (1 << 18);
		a[n - 1] = (1 << 19) + (1 << 18);
	}
	else{
		a[n] = c;
		a[n - 1] = 0;
	}

	puts("YES");

	int lol = 0;

	for(int i = 1; i <= n; ++i){
		printf("%d ", a[i]);
	}


	return 0;
}