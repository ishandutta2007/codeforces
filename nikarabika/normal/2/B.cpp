#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second
#define M1 MP(-1, -1)
#define rev(p) MP(p.R, p.L)

typedef pair<int, int> pie;

const int maxn = 1e3 + 10;
pie dp[maxn][maxn], pd[maxn][maxn], pardp[maxn][maxn], parpd[maxn][maxn];
int n, a[maxn][maxn];

pie pt(int x){
	if(x == 0)
		return MP(1, 1);
	int a = 0, b = 0;
	while(x % 2 == 0)
		x /= 2, a++;
	while(x % 5 == 0)
		x /= 5, b++;
	return MP(a, b);
}

void DP(int x, int y){
	const pie ftxy = pt(a[x][y]);
	if(x == n){
		if(dp[x][y + 1] == M1)
			DP(x, y + 1);
		dp[x][y] = pd[x][y] = MP(ftxy.L + dp[x][y + 1].L, ftxy.R + dp[x][y + 1].R);
		pardp[x][y] = parpd[x][y] = MP(x, y + 1);
		return;
	}
	if(y == n){
		if(dp[x + 1][y] == M1)
			DP(x + 1, y);
		dp[x][y] = pd[x][y] = MP(ftxy.L + dp[x + 1][y].L, ftxy.R + dp[x + 1][y]. R);
		pardp[x][y] = parpd[x][y] = MP(x + 1, y);
		return;
	}

	if(dp[x + 1][y] == M1)
		DP(x + 1, y);
	if(dp[x][y + 1] == M1)
		DP(x, y + 1);
	
	if(dp[x + 1][y] < dp[x][y + 1]){
		dp[x][y] = dp[x + 1][y];
		dp[x][y].L += ftxy.L;
		dp[x][y].R += ftxy.R;
		pardp[x][y] = MP(x + 1, y);
	}
	else{
		dp[x][y] = dp[x][y + 1];
		dp[x][y].L += ftxy.L;
		dp[x][y].R += ftxy.R;
		pardp[x][y] = MP(x, y + 1);
	}

	if(rev(pd[x + 1][y]) < rev(pd[x][y + 1])){
		pd[x][y] = pd[x + 1][y];
		pd[x][y].L += ftxy.L;
		pd[x][y].R += ftxy.R;
		parpd[x][y] = MP(x + 1, y);
	}
	else{
		pd[x][y] = pd[x][y + 1];
		pd[x][y].L += ftxy.L;
		pd[x][y].R += ftxy.R;
		parpd[x][y] = MP(x, y + 1);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	bool I_have_zero = false;
	pie zero;
	cin >> n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cin >> a[i][j];
			if(a[i][j] == 0)
				I_have_zero = true, zero = MP(i, j);
			dp[i][j] = M1, pd[i][j] = M1;
		}
	}
	dp[n][n] = pd[n][n] = pt(a[n][n]);
	DP(1, 1);
	int ans = min(min(dp[1][1].L, dp[1][1].R), min(pd[1][1].L, pd[1][1].R));
	if(I_have_zero and ans > 1){
		cout << 1 << endl;
		for(int i = 1; i < zero.L; i++)
			cout << 'D';
		for(int j = 1; j < zero.R; j++)
			cout << 'R';
		for(int i = zero.L; i < n; i++)
			cout << 'D';
		for(int j = zero.R; j < n; j++)
			cout << 'R';
		cout << endl;
		return 0;
	}
	cout << ans << endl;
	if(min(dp[1][1].L, dp[1][1].R) < min(pd[1][1].L, pd[1][1].R)){
		pie x = MP(1, 1);
		while(x != MP(n, n)){
			pie y = pardp[x.L][x.R];
			if(y.L == x.L)
				cout << 'R';
			else
				cout << 'D';
			x = y;
		}
	}
	else{
		pie x = MP(1, 1);
		while(x != MP(n, n)){
			pie y = parpd[x.L][x.R];
			if(y.L == x.L)
				cout << 'R';
			else
				cout << 'D';
			x = y;
		}
	}
	cout << endl;
	return 0;
}