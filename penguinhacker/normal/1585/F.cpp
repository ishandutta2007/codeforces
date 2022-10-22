#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int mxN=2e5, M=998244353;
int n, a[mxN];
vector<ar<int, 2>> d;

int norm(int x, int i) {
	if (i%2)
		x=(M-x)%M;
	return x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i];
	d.push_back({a[0]+1, M-1});
	ll sum=a[0]%M;
	for (int i=1; i<n; ++i) {
		if (a[i]==a[i-1]) {
			ll last=norm(d.back()[1], i);
			last=(sum-last+M)%M;
			d.back()[1]=norm(last, i+1);
			sum=sum*(a[i]-1)%M;
		} else if (a[i]>a[i-1]) {
			d.push_back({a[i]+1, norm(sum, i+1)});
			sum=sum*(a[i]-1)%M;
		} else {
			ll last=0; // value of last dp
			ll rem=sum; // remaining sum of dp[1]+dp[2]+...+dp[a[i]], just subtract dp[a[i]+1]...dp[a[i-1]]
			while(d.size()&&d.back()[0]>a[i]) {
				last=(last+norm(d.back()[1], i))%M;
				int pos=d.back()[0]-1;
				d.pop_back();
				int lhs=max(d.size()?d.back()[0]:1, a[i]+1);
				//assert(lhs<=pos);
				rem=(rem-(pos-lhs+1)*last%M+M)%M;
			}
			last=(sum-last+M)%M;
			d.push_back({a[i]+1, norm(last, i+1)});
			sum=(sum*a[i]-rem+M)%M;
		}
	}
	//for (auto x : d)
	//	cout << x[0] << " " << x[1] << endl;
	cout << sum;
	return 0;
}