#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second

const int maxn = 1e6 + 85 - 69;
int cnt[maxn];
int counter, n, ans;
pair<char, int> q[maxn];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> q[i].L >> q[i].R;
		if(q[i].L == '-'){
			if(cnt[q[i].R] == 0)
				ans++;
			else
				cnt[q[i].R]--, counter--;
		}
		else
			cnt[q[i].R]++, counter++;
		ans = max(ans, counter);
	}
	cout << ans << endl;
	return 0;
}