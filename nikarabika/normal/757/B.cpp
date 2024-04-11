//sobskdrbhvk
//remember the flying, the bird dies ):(
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
#define smax(x, y) ((x) = max((x), (y)))
#define smin(x, y) ((x) = min((x), (y)))
#define all(x) x.begin(),x.end()

const int maxn = 1e5 + 10;
int cnt[maxn];
int n;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		for(int j = 1; j * j <= x; j++) if(x % j == 0){
			if(j * j == x) cnt[j]++;
			else cnt[j]++, cnt[x / j]++;
		}
	}
	int ans = 1;
	for(int i = 2; i < maxn; i++)
		smax(ans, cnt[i]);
	cout << ans << endl;
	return 0;
}