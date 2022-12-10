#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 85 - 75;
vector<pie> E;
int d[maxn];
vector<int> dd[maxn];
LL n, k;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
		dd[d[i]].PB(i);
	}
	if(dd[0].size() != 1){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++){
		if(dd[i].size() and !dd[i - 1].size()){
			cout << -1 << endl;
			return 0;
		}
		if(dd[i].size() * 1LL > 1LL * dd[i - 1].size() * (k - 1LL + LL(i == 1))){
			cout << -1 << endl;
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		int p = 0, c = 0;
		for(int j = 0; j < dd[i].size(); j++){
			if(c >= k - 1 + (i == 1))
				p++, c = 0;
			c++;
			E.PB(MP(dd[i - 1][p], dd[i][j]));
		}
	}
	cout << E.size() << endl;
	for(int i = 0; i < E.size(); i++)
		cout << E[i].L << ' ' << E[i].R << '\n';
	return 0;
}