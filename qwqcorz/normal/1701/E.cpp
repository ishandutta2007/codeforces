#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+5;

int n,m,lcp[N][N];
void work() {
	int ans=1e9+7;
	string a,b;
	cin>>n>>m>>a>>b;
	for (int i=n-1;i>=0;i--) {
		for (int j=m-1;j>=0;j--) {
			lcp[i][j]=a[i]==b[j]?lcp[i+1][j+1]+1:0;
		}
	}
	bool flag=0;
	for (int i=0,j=0;i<n;i++) {
		if (j<m&&a[i]==b[j]) {
			j++;
		}
		if (j==m) {
			flag=1;
		}
		for (int t=0;t<=j;t++) {
			ans=min(ans,n-lcp[i+1][t]+i+1-t+1);
		}
	}
	if (flag) {
		ans=min(ans,n-lcp[0][0]);
		cout<<ans<<"\n";
	} else {
		cout<<"-1\n";
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			lcp[i][j]=0;
		}
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