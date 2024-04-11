#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

vector<ll> nums;

void gen(ll x=0) {
	if (x>1e18)
		return;
	if (x)
		nums.push_back(x);
	gen(10*x+4);
	gen(10*x+7);
}

const int mxN=1e5;
int n;
ll k, f[mxN], s[mxN], dp1[6*mxN], dp2[6*mxN], mn=2e18;

const ll INF=(ll)1e18+1;

ll add(ll a, ll b) {
	return min(a+b, INF);
}

ll mul(ll a, ll b) {
	if ((long double)a*b>2e18)
		return INF;
	return min(a*b, INF);
}

bool ok(int x) {
	if (!x)
		return 1;
	//cout << "CHECKING " << x << endl;
	for (int i=0, j=0; i+x-1<nums.size(); ++i) {
		dp1[i]=i?add(dp1[i-1], mul(j, nums[i+x-1]-nums[i+x-2])):0;
		//if (i>=200500)
		//	cout << i << endl;
		while(j<n&&s[j]<nums[i+x-1]) {
			dp1[i]=add(dp1[i], nums[i+x-1]-s[j]);
			++j;
		}
	}
	for (int i=nums.size()-x, j=n-1; ~i; --i) {
		dp2[i]=i<nums.size()-x?add(dp2[i+1], mul(n-j-1, nums[i+1]-nums[i])):0;
		//cout << i << endl;
		while(~j&&f[j]>nums[i]) {
			dp2[i]=add(dp2[i], f[j]-nums[i]);
			--j;
		}
	}
	//cout << "ALMOST DONE " << x << endl;
	for (int i=0; i+x-1<nums.size(); ++i) {
		if (nums[i+x-1]-nums[i]>mn)
			continue;
		if (add(dp1[i], dp2[i])<=k)
			return 1;
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	gen();
	sort(nums.begin(), nums.end());
	cin >> n >> k;
	for (int i=0; i<n; ++i) {
		cin >> f[i] >> s[i];
		mn=min(mn, s[i]-f[i]);
	}
	sort(f, f+n);
	sort(s, s+n);
	int lb=0, rb=nums.size();
	while(lb<rb) {
		int mid=(lb+rb+1)/2;
		if (ok(mid))
			lb=mid;
		else
			rb=mid-1;
	}
	cout << lb;
	return 0;
}