#include <bits/stdc++.h>

using namespace std;

const int maxn = 50 + 5;
bool dp[maxn][maxn][maxn][maxn];
bool por[maxn][maxn][maxn][maxn];

void DP(int a, int b, int c, int d){
	por[a][b][c][d] = true;
	if(a == 0){
		return;
	}
	for(int i = 1; i <= min(c, a); i++){
		if(!por[b][a - i][d][c])
			DP(b, a - i, d, c);
		if(!dp[b][a-i][d][c])
			dp[a][b][c][d] = true;
	}
}

int main(){
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	DP(a, b, c, d);
	if(dp[a][b][c][d])
		cout << "First" << endl;
	else
		cout << "Second" << endl;
	return 0;
}