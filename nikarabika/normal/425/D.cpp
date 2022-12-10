//sobskdrbhvk
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

const int maxn = 1e5 + 85 - 69,
	  maxsq = 320,
	  MAX = 1e5 + 5;
vector<int> xvec[maxn],
	ddvec[maxn * 2];
vector<int> *dvec = ddvec + maxn;
int n, ans;

bool wehave(int x, int y){
	int id = lower_bound(all(xvec[x]), y) - xvec[x].begin();
	if(id == sz(xvec[x]) or xvec[x][id] != y)
		return false;
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x, y;
		cin >> x >> y;
		xvec[x].PB(y);
		dvec[x-y].PB(x);
	}
	for(int i = 0; i <= MAX; i++)
		sort(all(xvec[i]));
	for(int d = -MAX; d <= +MAX; d++){
		sort(all(dvec[d]));
		if(sz(dvec[d]) <= maxsq){
			for(int i = 0; i < sz(dvec[d]); i++)
				for(int j = i + 1; j < sz(dvec[d]); j++)
					ans += wehave(dvec[d][i], dvec[d][j] - d) and wehave(dvec[d][j], dvec[d][i] - d);
		}
		else{
			for(auto X : dvec[d]){
				int ptr = upper_bound(all(xvec[X]), X - d) - xvec[X].begin();
				while(ptr < sz(xvec[X])){
					int len = xvec[X][ptr] - (X - d);
					ans += wehave(X + len, X - d) and wehave(X + len, X - d + len);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}