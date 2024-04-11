#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pie;

#define MP make_pair
#define L first
#define R second

const int maxn = 1000 * 100 + 85 - 69, maxd = 200 + 85 - 69;
int cnt[maxn], cnt2[maxd], s[maxn];
pie a[maxn];
int n;

int get(int id){
	int ret = 0;
	for(int i = 1; id; i++){
		ret += i * min(cnt2[i], id);
		id -= min(cnt2[i], id);
	}
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i].L;
		cnt[a[i].L]++;
	}
	for(int i = 0; i < n; i++)
		cin >> a[i].R;
	sort(a, a + n);
	for(int i = n; i >= 0; i--)
		s[i] = s[i + 1] + a[i].R;
	int ans = 1e9;
	for(int i = 0; i < n;){
		int cost = get(max(0, i - cnt[a[i].L] + 1));
		do{
			cnt2[a[i].R]++;
			i++;
		}while(i < n and a[i - 1].L == a[i].L);
		cost += s[i];
		ans = min(ans, cost);
	}
	cout << ans << endl;
	return 0;
}