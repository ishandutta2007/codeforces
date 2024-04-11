#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

int n,a[N],b[N],p[N];
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	for (int i=1;i<=n;i++) {
		cin>>b[i];
	}
	vector<int>A,B;
	for (int i=1;i<n;i++) {
		int x=a[i],y=a[i+1];
		if (x>y) {
			swap(x,y);
		}
		A.emplace_back(x*(n+1)+y);
		x=b[i],y=b[i+1];
		if (x>y) {
			swap(x,y);
		}
		B.emplace_back(x*(n+1)+y);
	}
	sort(A.begin(),A.end());
	sort(B.begin(),B.end());
	if (A!=B||a[1]!=b[1]||a[n]!=b[n]) {
		cout<<"NO\n";
		return;
	}
	vector<pair<int,int>>ans;
	auto rev=[&](int l,int r) {
		ans.emplace_back(l,r);
		for (int i=l;i<=(l+r)/2;i++) {
			swap(a[i],a[l+r-i]);
		}
	};
	for (int i=2;i<n;i++) {
		if (a[i]==b[i]) {
			continue;
		}
		for (int j=i+1;j<n;j++) {
			if (a[j]==b[i]&&a[j+1]==a[i-1]) {
				rev(i-1,j+1);
				break;
			}
		}
		if (a[i]==b[i]) {
			continue;
		}
		for (int j=i;j<n;j++) {
			if (a[j+1]==b[i]&&a[j]==a[i-1]) {
				for (int k=i;k<=j;k++) {
					p[a[k]]=k;
				}
				for (int k=j+1;k<=n;k++) {
					if (p[a[k]]) {
						int tmp=p[a[k]];
						for (int t=i;t<=j;t++) {
							p[a[t]]=0;
						}
						rev(tmp,k);
						break;
					}
				}
				break;
			}
		}
		for (int j=i+1;j<n;j++) {
			if (a[j]==b[i]&&a[j+1]==a[i-1]) {
				rev(i-1,j+1);
				break;
			}
		}
	}
	cout<<"YES\n"<<ans.size()<<"\n";
	for (auto [l,r]:ans) {
		cout<<l<<' '<<r<<"\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}