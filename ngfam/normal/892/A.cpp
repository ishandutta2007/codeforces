#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N];
int b[N];
long long sum;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		sum += a[i];
	}

	for(int i = 1; i <= n; ++i){
		cin >> b[i];
	}

	sort(b + 1, b + n + 1);
	if(b[n] + b[n - 1] >= sum){
		cout << "YES";
	}
	else{
		cout << "NO";
	}

	return 0;
}