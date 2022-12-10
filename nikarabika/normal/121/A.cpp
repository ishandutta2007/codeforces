#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;

#define PB push_back

vector<LL> all;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	LL st, en;
	cin >> st >> en;
	for(int dig = 1; dig <= 10; dig++){
		for(int mask = 0; mask < (1 << dig); mask++){
			LL num = 0;
			for(int i = dig - 1; i >= 0; i--)
				num = num * 10 + (((mask >> i) & 1) ? 7 : 4);
			all.PB(num);
		}
	}
	int id1 = lower_bound(all.begin(), all.end(), st) - all.begin();
	int id2 = lower_bound(all.begin(), all.end(), en) - all.begin();
	if(id1 == id2){
		cout << (en - st + 1) * all[id1] << endl;
		return 0;
	}
	LL ans = (all[id1] - st + 1) * all[id1] + (en - all[id2 - 1]) * all[id2];
	for(int i = id1 + 1; i < id2; i++)
		ans += all[i] * (all[i] - all[i - 1]);
	cout << ans << endl;
	return 0;
}