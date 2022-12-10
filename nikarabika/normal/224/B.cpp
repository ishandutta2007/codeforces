#include <bits/stdc++.h>

using namespace std;

#define MP make_pair
#define L first
#define R second

const int maxn = 1e5 + 10;
int a[maxn], mark[maxn];
int n, k;
pair<int, int> ans = MP(1e9, 1e9);

int main(){
	ios_base::sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	int c = 0, p = 0;
	for(int i = 1; i <= n; i++){
		mark[a[i]]++;
		if(mark[a[i]] == 1)
			c++;
		while(c >= k){
			mark[a[p]]--;
			if(mark[a[p]] == 0)
				c--;
			if(c == k - 1){
				c++;
				mark[a[p]]++;
				break;
			}
			p++;
		}
		if(c == k and i - p + 1 < ans.L) ans = MP(i - p + 1, p);
	}
	if(ans.L != 1e9) cout << ans.R << ' ' << ans.R + ans.L - 1 << endl;
	else cout << "-1 -1" << endl;
	return 0;
}