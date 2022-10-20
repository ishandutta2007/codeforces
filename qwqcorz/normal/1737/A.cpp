#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,k;
void work() {
	cin>>n>>k;
	int t[26]={};
	string s;
	cin>>s;
	for (int i=0;i<n;i++) {
		t[s[i]-'a']++;
	}
	for (int i=1;i<=k;i++) {
		char ans=0;
		for (int j=0;j<=min(n/k,26);j++) {
			ans='a'+j;
			if (j==n/k) {
				break;
			}
			if (!t[j]) {
				break;
			} else {
				t[j]--;
			}
		}
		cout<<ans;
	}
	cout<<"\n";
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