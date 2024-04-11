#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vector<int>>
#define vpii vector<pair<int, int>>
#define fi first
#define se second

using namespace std;

typedef long long ll;

int main(){
	int n;
	cin >> n;
	for(int Case = 0; Case < n; Case++){
		int c, m, x;
		cin >> c >> m >> x;
		int ans = min(min(c, m), x);
		c -= ans;
		m -= ans;
		x -= ans;
		if(c == 0 || m == 0){
			cout << ans << endl;
		}else{
			cout << ans + min((c + m) / 3, min(c, m)) << endl;
		}
	}
	return 0;
}