#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n;
void work() {
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=i;j++) {
			cout<<(j==1||j==i)<<" \n"[j==i];
		}
	}
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