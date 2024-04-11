#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

int n,k,a[N];
void work() {
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	if (k==1||k==n) {
		cout<<"YES\n";
		return;
	}
	if (a[k]<0) {
		cout<<"NO\n";
		return;
	}
	vector<pair<ll,ll>>A,B;
	ll sum=0,mn=0;
	for (int i=k-1;i>=1;i--) {
		sum+=a[i];
		mn=min(mn,sum);
		if (sum>=0) {
			A.emplace_back(mn,sum);
			mn=sum=0;
		}
	}
	ll l=mn;
	mn=sum=0;
	for (int i=k+1;i<=n;i++) {
		sum+=a[i];
		mn=min(mn,sum);
		if (sum>=0) {
			B.emplace_back(mn,sum);
			mn=sum=0;
		}
	}
	ll r=mn;
	mn=sum=0;
	ll now=a[k];
	int i=0,j=0;
	while (1) {
		bool flag=0;
		if (i<(int)A.size()) {
			auto [mn,sum]=A[i];
			if (now+mn>=0) {
				now+=sum,i++,flag=1;
			}
		}
		if (j<(int)B.size()) {
			auto [mn,sum]=B[j];
			if (now+mn>=0) {
				now+=sum,j++,flag=1;
			}
		}
		if (!flag) {
			break;
		}
	}
	if (i==(int)A.size()&&now+l>=0) {
		cout<<"YES\n";
		return;
	}
	if (j==(int)B.size()&&now+r>=0) {
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}