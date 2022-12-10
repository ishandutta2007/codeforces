#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define PB push_back
#define L first
#define R second

typedef long long int ll;
typedef pair<int, int> pie;

vector<pie> cnt;
vector<pie> a;
vector<int> b;
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i < n; i++){
		int fi, se;
		cin >> fi >> se;
		b.PB(fi);
		b.PB(se);
		a.PB(MP(fi, se));
	}
	sort(b.begin(), b.end());
	b.resize(unique(b.begin(), b.end()) - b.begin());
	cnt.resize(b.size());
	for(int i = 0; i < a.size(); i++){
		int idx = lower_bound(b.begin(), b.end(), a[i].L) - b.begin(),
			idy = lower_bound(b.begin(), b.end(), a[i].R) - b.begin();
		cnt[idx].L++;
		if(a[i].L != a[i].R)
			cnt[idy].R++;
	}
	int ans = 1e6;
	for(int i = 0; i < cnt.size(); i++) if(cnt[i].L + cnt[i].R >= (n+1) / 2){
		int x = (n + 1) / 2;
		if(cnt[i].L >= x){
			ans = 0;
			break;
		}
		x -= cnt[i].L;
		ans = min(ans, x);
	}
	if(ans == 1e6)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}