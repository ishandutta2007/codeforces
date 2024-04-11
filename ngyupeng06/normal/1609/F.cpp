#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define mp make_pair
#define pb push_back

ll n, k, t, a, b, c;
ll arr[1000005], bits[1000005];

ll solve(int l, int r){
	if (l==r) return 1;
	ll ans = 0, m = (l+r)/2;
	ans += solve(l,m) + solve(m+1,r);
	ll cmax = -2e18, mxbit = 0, cmax1 = 2e18, mxbit1 = 0;
	ll cmin = 2e18, mnbit = 0, cmax2 = 2e18, mxbit2 = 0;
	ll cur = m+1;
	ll curm = m+1;
	ll st[64], en[64];
	for (int i=0; i<64; i++) st[i] = en[i] = 0;
	for (int i=m; i>=l; i--){
		if (arr[i] > cmax){
			cmax = arr[i];
			mxbit = bits[i];
		}	
		if (arr[i] < cmin){
			cmin = arr[i];
			mnbit = bits[i];
		}
		while (cur <= r && arr[cur] <= cmax){
			if (cmax1 > arr[cur]){
				cmax1 = arr[cur];
				mxbit1 = bits[cur];
			}
			en[mxbit1]++;
			cur++;
		}
		while (curm <= r && arr[curm] >= cmin){
			if (cmax2 > arr[curm]){
				cmax2 = arr[curm];
				mxbit2 = bits[curm];
			}
			st[mxbit2]++;
			curm++;
		}
		if (cur > curm){
			ans += en[mxbit] - st[mxbit];
		}
		if (mxbit == mnbit) ans += min(curm,cur) - (m+1);
	}
	//cout << l << " " << r << " " << ans << "\n";
	cmax = -2e18, mxbit = 0, cmax1 = 2e18, mxbit1 = 0;
	cmin = 2e18, mnbit = 0, cmax2 = 2e18, mxbit2 = 0;
	cur = m;
	curm = m;
	for (int i=0; i<64; i++) st[i] = en[i] = 0;
	for (int i=m+1; i<=r; i++){
		if (arr[i] > cmax){
			cmax = arr[i];
			mxbit = bits[i];
		}	
		if (arr[i] < cmin){
			cmin = arr[i];
			mnbit = bits[i];
		}
		while (cur >= l && arr[cur] < cmax){
			if (cmax1 > arr[cur]){
				cmax1 = arr[cur];
				mxbit1 = bits[cur];
			}
			en[mxbit1]++;
			cur--;
		}
		while (curm >= l && arr[curm] > cmin){
			if (cmax2 > arr[curm]){
				cmax2 = arr[curm];
				mxbit2 = bits[curm];
			}
			st[mxbit2]++;
			curm--;
		}
		if (cur < curm){
			ans += en[mxbit] - st[mxbit];
		}
		if (mxbit == mnbit) ans += m - max(curm,cur);
	}
//	cout << l << " " << r << " " << ans << "\n";
	return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> arr[i];
		ll x = arr[i];
		while (x){
			if (x%2) bits[i]++;
			x/=2;
		}
	}
	cout << solve(0,n-1);
}