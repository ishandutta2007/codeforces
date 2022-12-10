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

const int maxn = 2e5 + 85 - 69;
int a[maxn];
int n, s;
int ans;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s, s--;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int rem = 0,
		ans = 0;
	if(a[s] != 0)
		a[s] = 0, ans++;
	for(int i = 0; i < n; i++)
		if(a[i] == 0 and i != s)
			ans++, rem++;
	int rptr = n - 1;
	sort(a, a + n);
	for(int i = 1; i <= rptr; i++){
		int need = max(0, a[i] - a[i - 1] - 1);
		if(need == 0) continue;
		{
			int tmp = min(rem, need);
			rem -= tmp;
			need -= tmp;
		}
		for(int j = 0; j < need; j++){
			ans++;
			if(rptr == i){
				cout << ans << endl;
				return 0;
			}
			rptr--;
		}
	}
	cout << ans << endl;
	return 0;
}