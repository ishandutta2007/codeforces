//sobskdrbhvk
//remember the flying, the bird dies ):(
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;

#define PB push_back
#define MP make_pair
#define L first
#define R second
#define sz(x) ((int)(x).size())
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 30 + 2,
	  maxlen = 155,
	  maxl = 320,
	  D = 160;
bool has[maxn][maxl][maxl][8];
int dx[8] = {+0, +1, +1, +1, +0, -1, -1, -1},
	dy[8] = {+1, +1, +0, -1, -1, -1, +0, +1};
int sum[8][maxl][maxl],
	t[maxn],
	n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> t[i], t[i] += bool(i);
	has[0][D][D][0] = true;
	for(int i = 0; i < n; i++)
		for(int r = -maxlen + 1; r < maxlen; r++)
			for(int c = -maxlen + 1; c < maxlen; c++)
				for(int id = 0; id < 8; id++)
					if(has[i][r + D][c + D][id])
						if(has[i][r + D][c + D][id]){
							sum[id][r + D][c + D]++;
							sum[id][r + dx[id] * t[i] + D][c + dy[id] * t[i] + D]--;
							has[i+1][r + dx[id] * (t[i] - 1) + D][c + dy[id] * (t[i] - 1) + D][(id + 7)&7] = true;
							has[i+1][r + dx[id] * (t[i] - 1) + D][c + dy[id] * (t[i] - 1) + D][(id + 1)&7] = true;
						}
	/*{
		const int i = n - 1;
		for(int r = -maxlen + 1; r < maxlen; r++)
			for(int c = -maxlen + 1; c < maxlen; c++)
				for(int id = 0; id < 8; id++)
					if(has[i][r + D][c + D][id])
						if(has[i][r + D][c + D][id]){
							sum[id][r + D][c + D]++;
							sum[id][r + dx[id] * t[i] + D][c + dy[id] * t[i] + D]--;
						}
	}*/
	//cout << "#" << sum[0][160][163] << endl;
	for(int r = maxlen - 1; r > -maxlen; r--){
		for(int c = maxlen - 1; c > -maxlen; c--){
			sum[6][r + D][c + D] += sum[6][r - dx[6] + D][c - dy[6] + D];
			sum[5][r + D][c + D] += sum[5][r - dx[5] + D][c - dy[5] + D];
			sum[4][r + D][c + D] += sum[4][r - dx[4] + D][c - dy[4] + D];
		}
		for(int c = -maxlen + 1; c < maxlen; c++)
			sum[7][r + D][c + D] += sum[7][r - dx[7] + D][c - dy[7] + D];
	}
	/*cout << "HI" << endl;
	for(int c = -maxlen + 1; c < maxlen; c++)
		cout << sum[0][160][c + D] << ' ';
	cout << endl;*/
	for(int r = -maxlen + 1; r < maxlen; r++){
		for(int c = maxlen - 1; c > -maxlen; c--)
			for(int id = 2; id < 4; id++)
				sum[id][r + D][c + D] += sum[id][r - dx[id] + D][c - dy[id] + D];
		for(int c = -maxlen + 1; c < maxlen; c++)
			for(int id = 0; id < 2; id++)
				sum[id][r + D][c + D] += sum[id][r - dx[id] + D][c - dy[id] + D];
	}
	int ans = 0;
	for(int r = -maxlen + 1; r < maxlen; r++)
		for(int c = -maxlen + 1; c < maxlen; c++){
			bool su = 0;
			for(int id = 0; id < 8; id++)
				su |= bool(sum[id][r + D][c + D]);
			ans += su;
		}
	cout << ans << endl;
	return 0;
}