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
#define smin(x, y) (x) = min((x), (y))
#define smax(x, y) (x) = max((x), (y))

vector<LL> all;

void build(int dig, LL val = 0, int pos = 0){
	if(pos == -1)
		return;
	if(pos != dig - 1)
		all.PB(val + (1LL << pos) - 1);
	build(dig, val + (1LL << pos), pos - 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL st, en;
	cin >> st >> en;
	for(int i = 2; i <= 63; i++)
		build(i, 0, i - 1);
	sort(all.begin(), all.end());
	cout << upper_bound(all.begin(), all.end(), en) - lower_bound(all.begin(), all.end(), st) << endl;
	return 0;
}