#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=105;

int n;
bool f[N][N][2];
void init(int n) {
	f[0][0][0]=1;
	for (int i=0;i<=n;i++) {
		for (int j=0;j<=n;j++) {
			if (!i&&!j) {
				continue;
			}
			int t=j&1;
			for (int k=0;k<=1;k++) {
				if (i&&!f[i-1][j][!k^t]) {
					f[i][j][k]=1;
				}
				if (j&&!f[i][j-1][k^!t]) {
					f[i][j][k]=1;
				}
			}
		}
	}
}
void work() {
	cin>>n;
	int t[2]={};
	for (int i=1;i<=n;i++) {
		int x;
		cin>>x;
		t[x&1]++;
	}
	if (f[t[0]][t[1]][0]) {
		cout<<"Alice\n";
	} else {
		cout<<"Bob\n";
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init(100);
	int T;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}