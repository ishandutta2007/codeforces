#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef double ld;

#define fi first
#define se second
#define mp make_pair
#define fastIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define TEST freopen("in.txt","r",stdin);
#define ab(a) (((a) < 0) ? (-(a)) : (a))

const int S = 10005;
ll cnt[S];

int main(){
	int n,k;
	cin >> n >> k;
	ll ans = 0;
	ll v;
	for(int i = 0;i<n;i++){
		cin >> v;
		cnt[v]++;
	}
	for(int i = 0;i<S;i++){
		for(int j = 0;j<=i;j++){
			if(__builtin_popcount(i^j) == k){
				ans += (i == j ? ((cnt[i] * cnt[i]) - cnt[i]) / 2: cnt[i] * cnt[j]);
			}
		}
	}
	cout << ans << "\n";
	return 0;
}