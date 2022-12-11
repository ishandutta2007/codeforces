#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;
typedef double db;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define all(x) ((x).begin(),(x).end())
#define len(x) ((ll)(x).size())

const int N = 2005;
char d[N][N];
int f[N][N];

bool ok[N][N];

int main(){
	fastIO;
	int n, k;
	cin >> n >> k;
	int mv = -1;
	for(int i = 2 ; i <= n; i ++ )
		f[i][0] = (int)1e9 + 9, f[0][i] = (int)1e9 +  9;
	for(int i = 1; i <= n; i ++ ){
		for(int j = 1; j <= n; j ++ ){
			cin >> d[i][j];
			f[i][j] = min(f[i - 1][j], f[i][j - 1]) + (d[i][j] != 'a');
			if(f[i][j] <= k){
				ok[i + 1][j] = true;
				ok[i][j + 1] = true;
				mv = max(mv, i + j - 2);
			}
		}
	}
	ok[1][1] = true;
	for(int z = 0; z <= mv;z ++ )
		cout << 'a';
	int l;
	char gud;
	int ci, cj;
	for(int dd = mv +  1; dd < n * 2 - 1; dd ++  ){
		l = dd;
		gud = 'z';
		for(int tl = 0 ; tl < n; tl ++ ){
			ci = tl + 1;
			cj = l - tl + 1;
			if(ci > 0 and cj > 0 and ci <= n and cj <= n and ok[ci][cj]){
				gud = min(gud, d[ci][cj]);
			}
		}
		for(int tl = 0 ; tl < n; tl ++ ){
			ci = tl + 1;
			cj = l - tl + 1;
			if(ci > 0 and cj > 0 and ci <= n and cj <= n and ok[ci][cj] and d[ci][cj] == gud){
				ok[ci + 1][cj] = true;
				ok[ci][cj + 1] = true;
			}
		}
		cout << gud;
	}
	return 0;
}