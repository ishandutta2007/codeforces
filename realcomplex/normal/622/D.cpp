#pragma optimize ("O3")
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ab(x) ((x) < 0 ? -(x) : (x))
#define all(x) ((x).begin(),(x).end())
#define len(x) ((int)(x).size())

int main(){
	fastIO;
	int n;
	cin >> n;
	int ans[n * 2];
	memset(ans, 0, sizeof ans);
	int k = (n + 1)/2;
	for(int i = 0 ; i < k; i ++ ){
		ans[i] = (i * 2) + 1;
		ans[n - i - 1] = (i * 2) + 1;
	}
	int p = n * 2 - 2;
	k --;
	int nx = n + n - 2;
	for(int j = 0;j < k; j ++ ){
		ans[n + j] = j * 2 + 2;
		ans[nx] = j * 2 + 2;
		-- nx;
	}
	for(int i = 0; i < 2 * n; i ++ ){
		if(ans[i] == 0)
			ans[i] = n;
		cout << ans[i] << " ";
	}
	return 0;
}