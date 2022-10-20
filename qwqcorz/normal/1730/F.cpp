#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e3+15;

void ckmn(int &x,int y) {
	if (x>y) {
		x=y;
	}
}
struct bit {
	int n,t[N];
	void send(int _n) {
		n=_n,memset(t,0,sizeof(t));
	}
	void add(int x) {
		for (;x;x&=x-1) {
			t[x]++;
		}
	}
	int query(int x) {
		int ret=0;
		for (;x<=n;x+=x&-x) {
			ret+=t[x];
		}
		return ret;
	}
}t;
int n,k,p[N],np[N],dp[N][1<<8];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		cin>>p[i];
		np[p[i]]=i;
	}
	t.send(n);
	memset(dp,0x3f,sizeof(dp));
	dp[1][0]=0;
	const int inf=dp[0][0];
	for (int i=1;i<=n;i++) {
		int tot[k+1];
		memset(tot,0x3f,sizeof(tot));
		for (int j=0;i+j<=n&&j<=k;j++) {
			tot[j]=t.query(np[i+j]);
		}
		for (int S=0;S<(1<<k);S++) {
			if (dp[i][S]==inf) {
				continue;
			}
			for (int j=0;j<k;j++) {
				if (S>>j&1) {
					continue;
				}
				int now=dp[i][S]+tot[j+1];
				for (int t=0;t<k;t++) {
					if (S>>t&1) {
						now+=np[i+1+t]>np[i+1+j];
					}
				}
				ckmn(dp[i][S|1<<j],now);
			}
			int now=dp[i][S]+tot[0],T=S,j=i+1;
			for (int t=0;t<k;t++) {
				if (S>>t&1) {
					now+=np[i+1+t]>np[i];
				}
			}
			for (;T&1;T>>=1) {
				j++;
			}
			ckmn(dp[j][T>>1],now);
		}
		t.add(np[i]);
	}
	cout<<dp[n+1][0]<<"\n";
	
	return 0;
}