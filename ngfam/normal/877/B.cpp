#include <bits/stdc++.h>

using namespace std;

const int N = 100001;

int f[N][5];

int main(){
	if(fopen("1.inp", "r")){
		freopen("1.inp", "r", stdin);
	}

	string x;
	cin >> x;

	f[0][1] = (x[0] == 'a');
	f[0][2] = (x[0] == 'b');
	f[0][3] = (x[0] == 'a');


	for(int i = 1; i < x.size(); ++i){
		f[i][1] = f[i - 1][1] + (x[i] == 'a');
		f[i][2] = max(f[i - 1][1], f[i - 1][2]) + (x[i] == 'b');
		f[i][3] = max(f[i - 1][2], f[i - 1][3]) + (x[i] == 'a');
	}


	cout << max(f[x.size() - 1][2], max(f[x.size() - 1][1], f[x.size() - 1][3]));

	return 0;
}