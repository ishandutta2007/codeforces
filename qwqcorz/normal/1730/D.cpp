#include<bits/stdc++.h>
#define ll long long
using namespace std;

void work() {
	int n;
	string a,b;
	cin>>n>>a>>b;
	int cnt[26][26]={};
	for (int i=0;i<n;i++) {
		cnt[min(a[i],b[n-1-i])-'a'][max(a[i],b[n-1-i])-'a']++;
	}
	int tot=0;
	for (int i=0;i<26;i++) {
		for (int j=i;j<26;j++) {
			if (cnt[i][j]&1) {
				tot++;
				if (tot>1||i!=j) {
					cout<<"NO\n";
					return;
				}
			}
		}
	}
	cout<<"YES\n";
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