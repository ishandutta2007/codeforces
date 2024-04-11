#include <bits/stdc++.h>

using namespace std;

const int N = 1000100;

int n;
int a[N];
int cnt[N];
set < int > s;

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	cin >> n;
	for(int i = 1; i <= n; ++i){
		cin >> a[i];
		s.insert(a[i]);
		++cnt[a[i]];	
	}

	int xmin = a[1];
	for(int i = 2; i <= n; ++i){
		xmin = __gcd(xmin, a[i]);
	}

	if(s.count(xmin) == 0) {
		cout << -1;
		exit(0);
	}

	cout << n + n << endl;
	for(int i = 1; i <= n; ++i){
		cout << a[i] << " " << xmin << " ";
	}

	return 0;
}