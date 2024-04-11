#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

const int MOD=1e9+7;
int binPow(ll b, int p=MOD-2) {
	ll res=1;
	while(p>0) {
		if (p&1) res=res*b%MOD;
		b=b*b%MOD;
		p>>=1;
	}
	return res;
}

vector<ll> f={1}, iF={1};
ll C(int a, int b) {
	if (a<0||b<0||b>a) return 0;
	assert(a<=(int)5e6);
	while(f.size()<=a) {
		int x=f.size();
		f.push_back(f.back()*x%MOD);
		iF.push_back(iF.back()*binPow(x)%MOD);
	}
	return f[a]*iF[b]%MOD*iF[a-b]%MOD;
}

const int mxN=51;
int n, k, cnt1, cnt2;
int dis[mxN][mxN][2];
ll dp[mxN][mxN][3*mxN];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k, k/=50;
	for (int i=0; i<n; ++i) {
		int a; cin >> a;
		if (a==50) {
			++cnt1;
		}
		else {
			++cnt2;
		}
	}
	for (int i=0; i<=cnt1; ++i) {
		for (int j=0; j<=cnt2; ++j) {
			dis[i][j][0]=dis[i][j][1]=-1;
		}
	}
	//cout << cnt1 << " " << cnt2 << " " << k << "\n";
	dis[cnt1][cnt2][0]=0;
	dp[cnt1][cnt2][0]=1;
	queue<ar<int, 3>> q;
	q.push({cnt1, cnt2, 0});
	while(!q.empty()) {
		auto& x=q.front(); q.pop();
		int a=x[0], b=x[1];
		if (x[2]==0) {
			for (int i=0; i<=a; ++i) {
				for (int j=0; j<=b; ++j) {
					int take1=a-i, take2=b-j;
					int cost=take1+2*take2;
					if (cost==0||cost>k) {
						continue;
					}
					if (dis[i][j][1]==-1) {
						dis[i][j][1]=dis[a][b][0]+1;
						q.push({i, j, 1});
					}
					if (dis[i][j][1]==dis[a][b][0]+1) {
						dp[i][j][1]=(dp[i][j][1]+dp[a][b][0]*C(a, take1)%MOD*C(b, take2))%MOD;
					}
				}
			}
		}
		else {
			assert(x[2]==1);
			for (int i=a; i<=cnt1; ++i) {
				for (int j=b; j<=cnt2; ++j) {
					int take1=i-a, take2=j-b;
					int cost=take1+2*take2;
					if (cost==0||cost>k) {
						continue;
					}
					if (dis[i][j][0]==-1) {
						dis[i][j][0]=dis[a][b][1]+1;
						q.push({i, j, 0});
					}
					if (dis[i][j][0]==dis[a][b][1]+1) {
						dp[i][j][0]=(dp[i][j][0]+dp[a][b][1]*C(cnt1-a, take1)%MOD*C(cnt2-b, take2))%MOD;
					}
				}
			}
		}
	}
	if (dis[0][0][1]==-1) {
		cout << "-1\n0";
	}
	else {
		cout << dis[0][0][1] << "\n" << dp[0][0][1];
	}
	return 0;
}