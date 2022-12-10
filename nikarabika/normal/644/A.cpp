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

const int maxn = 100;
int ans[maxn][maxn];
vector<int> vec[2];
int n, a, b;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> a >> b;
	if(n > a * b){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i <= n; i++)
		vec[!(i & 1)].PB(i);
	for(int i = 0; i < a; i++)
		for(int j = 0; j < b; j++)
			if(sz(vec[(i + j) & 1])){
				ans[i][j] = vec[(i + j) & 1].back();
				vec[(i + j) & 1].pop_back();
			}
	for(int i = 0; i < a; i++, cout << endl)
		for(int j = 0; j < b; j++)
			cout << ans[i][j] << ' ';
	return 0;
}