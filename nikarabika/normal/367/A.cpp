//sobskdrbhvk
#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef long double LD;
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

const int maxn = 100 * 1000 + 85 - 69;
int sum[maxn][3];
string s;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> s;
	n = sz(s);
	for(int i = 0; i < n; i++)
		for(int j = 0; j < 3; j++)
			sum[i + 1][j] = sum[i][j] + (s[i] == ('x' + j));
	int q;
	cin >> q;
	while(q--){
		int fi, se;
		cin >> fi >> se, fi--;
		if(se - fi <= 2){
			cout << "YES\n";
			continue;
		}
		int val[3];
		for(int j = 0; j < 3; j++)
			val[j] = sum[se][j] - sum[fi][j];
		if(max(max(val[0], val[1]), val[2]) - min(min(val[0], val[1]), val[2]) <= 1)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}