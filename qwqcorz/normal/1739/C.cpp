#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=65;
const int mod=998244353;

int f[N],C[N][N],n;
void work() {
	cin>>n;
	cout<<f[n/2]<<' '<<(C[n][n/2]-f[n/2]-1+mod)%mod<<" 1\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	for (int i=C[0][0]=1;i<=60;i++) {
		for (int j=C[i][0]=1;j<=i;j++) {
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
		}
	}
	for (int i=1;i<=30;i++) {
		f[i]=(1LL*C[(i-1)*2][i-1]-f[i-1]-1+C[i*2-1][i-1]+mod)%mod;
	}
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}