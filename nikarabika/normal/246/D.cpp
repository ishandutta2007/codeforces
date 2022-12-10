#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define PB push_back
#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 10;
int a[maxn], c[maxn], n, m, Min = 2e5;
vector<pie> e;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> c[i];
		Min = min(Min, c[i]);
	}
	while(m--){
		int fi, se;
		cin >> fi >> se;
		if(c[fi] != c[se])
			e.PB(MP(min(c[fi], c[se]), max(c[fi], c[se])));
	}
	sort(e.begin(), e.end());
	e.resize(unique(e.begin(), e.end()) - e.begin());
	for(int i = 0; i < e.size(); i++)
		a[e[i].L]++, a[e[i].R]++;
	int Max = -1, ans;
	for(int i = 1; i <= 1e5; i++)
		if(a[i] > Max)
			Max = a[i], ans = i;
	if(Max == 0)
		cout << Min << endl;
	else
		cout << ans << endl;
	return 0;
}