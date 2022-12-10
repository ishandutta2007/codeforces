#include <bits/stdc++.h>

using namespace std;

int dp[25][8][8];
char s[8][8];

bool ist(int x, int y, int t){
	if(t > x)
		return true;
	return s[x - t][y] != 'S';
}

int DP(int t = 0, int x = 7, int y = 0){
	if(dp[t][x][y] != 2){
		//cout << dp[t][x][y] << ' ' << t << ' ' << x << ' ' << y << endl;
		return dp[t][x][y];
	}
	if(x == 0 and y == 7){
		dp[t][x][y] = 1;
		return 1;
	}
	if(t == 24)
		return 0;
	dp[t][x][y] = 0;
	for(int i = x - 1; i <= x + 1; i++)
		if(i >= 0 and i < 8)
			for(int j = y - 1; j <= y + 1; j++)
				if(j >= 0 and j < 8 and ist(i, j, t) and ist(i, j, t + 1))
					dp[t][x][y] = max(dp[t][x][y], DP(t + 1, i, j));
	return dp[t][x][y];
}

int main(){
	ios_base::sync_with_stdio(false);
	for(int t = 0; t < 25; t++)
		for(int i = 0; i < 8; i++)
			for(int j = 0; j < 8; j++)
				dp[t][i][j] = 2;
	/*
	int x, y, z;
	while(cin >> x >> y >> z)
		cout << dp[x][y][z] << endl;
	*/
	for(int i = 0; i < 8; i++)
		for(int j = 0; j < 8; j++)
			cin >> s[i][j];
	if(DP() == 1)
		cout << "WIN" << endl;
	else
		cout << "LOSE" << endl;
	return 0;
}