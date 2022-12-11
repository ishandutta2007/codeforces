#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
typedef double db;
typedef pair<int, int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

const int N = (int)5e5 + 9;

vector<int> ind[N];

int tot[N];
int fir[N];
int a[N];

int main(){
	fastIO;
	int n, c;
	cin >> n >> c;
	for(int i = 1 ; i <= n; i++ ){
		cin >> a[i];
		ind[a[i]].push_back(i);
		fir[i] = (fir[i - 1] + (a[i] == c));
	}
	for(int i = n; i > 0 ; i -- ){
		tot[i] = (tot[i + 1] + (a[i] == c));
	}
	int pref;
	int suf;
	int ans = 0;
	for(int i = 1; i < N; i ++ ){
		multiset<int> an;
		for(int j = 0 ; j < ind[i].size(); j ++ ){
			an.insert(j + 1 + tot[ind[i][j] + 1]);
		}
		for(int j = 0 ; j < ind[i].size(); j ++ ){
			pref = fir[ind[i][j] - 1];
			auto it = an.end();
			-- it;
			suf = *it;
			suf -= j;
			ans = max(ans, suf + pref);
			an.erase(an.find(j + 1 + tot[ind[i][j] + 1]));
		}
	}
	cout << ans << "\n";
	return 0;
}