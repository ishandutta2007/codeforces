#include <bits/stdc++.h>

using namespace std;

const int N = 250;

int tail[N];
int head[N];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	string x, y;

	cin >> x;
	int n;
	cin >> n;

	for(int i = 1; i <= n; ++i){
		cin >> y;
		if(y == x){
			cout << "YES";
			return 0;
		}
		head[y[0]] = 1;
		tail[y[1]] = 1;
	}

	if(tail[x[0]] && head[x[1]]) cout << "YES";
	else cout << "NO";

	return 0;
}