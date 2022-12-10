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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int fi, se, th;
	if(n == 1){
		cin >> fi;
		return cout << (fi ? "BitLGM" : "BitAryo") << endl, 0;
	}
	if(n == 3){
		cin >> fi >> se >> th;
		if((fi ^ se ^ th) == 0)
			cout << "BitAryo" << endl;
		else
			cout << "BitLGM" << endl;
		return 0;
	}
	cin >> fi >> se;
	if(fi > se)
		swap(fi, se);
	bool dp[fi + 1][se + 1];
	memset(dp, false, sizeof dp);
	for(int i = 0; i <= fi; i++)
		for(int j = 0; j <= se; j++)
			if(!dp[i][j]){
				for(int x = 1; i + x <= fi; x++)
					dp[i + x][j] = true;
				for(int x = 1; j + x <= se; x++)
					dp[i][j + x] = true;
				for(int x = 1; i + x <= fi and j + x <= se; x++)
					dp[i + x][j + x] = true;
			}
	cout << (dp[fi][se] ? "BitLGM" : "BitAryo") << endl;
	return 0;
}