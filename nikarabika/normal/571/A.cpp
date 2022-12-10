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

LL a[3],
   L,
   sum;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 0; i < 3; i++)
		cin >> a[i], sum += a[i];
	cin >> L;
	LL ans = (L + 3) * (L + 2) / 2 * (L + 1) / 3;
	for(LL s = sum; s <= sum + L; s++){
		for(int i = 0; i < 3; i++){
			LL mn[3];
			for(int j = 0; j < 3; j++)
				if(i^j) mn[j] = a[j];
				else mn[j] = max(a[j], (s+1) / 2);
			LL ss = s - mn[0] - mn[1] - mn[2] + 3;
			if(ss >= 3)
				ans -= (ss - 1) * (ss - 2) / 2;
		}
	}
	cout << ans << '\n';
	return 0;
}