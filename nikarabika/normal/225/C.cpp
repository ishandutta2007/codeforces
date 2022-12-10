//In the name of "God"
/*
	Koma (by Sadegh)
	khoda midooneh ke too delam chie
	midoone miparam az roo parchinesh
	midoonam migire dastamo ye roozo
	mikeshe pardeh az roo tasviresh
	lekh o lekh -e pat roye khesh o khesh -e barga
	fasl-e here kere raft o baz reside sarma
	hame chi khas too ye rooz-e addi
	ye root ehsas o ye rooye maddi
	
	--> Ye kami sabr kon
	--> man hanooz in ja kolli kar daram
	--> Ye kami sabr kon Ye kami sabr kon
	--> man soal nistam javab daram
	--> Ye kami sabr kon Ye kami sabr kon
	--> Ye khordeh vaysa Ye kami sabr kon
	;)
*/
#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e3 + 10;
char a[maxn][maxn];
int dp[2][maxn], s[2][maxn], n, m, x, y;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m >> x >> y;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> a[i][j];
	for(int j = 1; j <= m; j++){
		s[0][j] = s[0][j - 1];
		s[1][j] = s[1][j - 1];
		for(int i = 1; i <= n; i++){
			if(a[i][j] == '.')
				s[0][j]++;
			else
				s[1][j]++;
		}
	}
	for(int j = 1; j <= m; j++){
		int ty = 1;
		do{
			dp[ty][j] = 1e9;
			for(int p = x; p <= min(y, j); p++){
				dp[ty][j] = min(dp[ty][j], dp[(ty + 1) % 2][j - p] + s[ty][j] - s[ty][j - p]);
			}
			ty = (ty + 1) % 2;
		}while(ty != 1);
	}
	cout << min(dp[0][m], dp[1][m]) << endl;
	return 0;
}