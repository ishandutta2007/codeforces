#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=505;

int n,k,c[N][N];
vector<pair<int,int>>b[N*N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int siz=0;
	cin>>n>>k;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=n;j++) {
			int x;
			cin>>x;
			siz+=b[x].empty();
			b[x].emplace_back(i,j);
		}
	}
	if (siz<=k) {
		cout<<k-siz<<"\n";
		return 0;
	}
	vector<tuple<int,int,int,int>>a;
	for (int i=1;i<=n*n;i++) {
		if (b[i].empty()) {
			continue;
		}
		int x1=n,x2=0,y1=n,y2=0;
		for (auto [x,y]:b[i]) {
			x1=min(x1,x),x2=max(x2,x);
			y1=min(y1,y),y2=max(y2,y);
		}
		a.emplace_back(x1,y1,x2,y2);
	}
	for (int l=1;l<=n;l++) {
		memset(c,0,sizeof(c));
		for (auto [x1,y1,x2,y2]:a) {
//			cerr<<x1<<' '<<y1<<' '<<x2<<' '<<y2<<endl;
			int lx=max(x2-l+1,1),ly=max(y2-l+1,1);
			int rx=min(x1,n-l+1),ry=min(y1,n-l+1);
//			cerr<<lx<<','<<rx<<','<<ly<<','<<ry<<endl;
			if (lx>rx||ly>ry) {
				continue;
			}
			c[lx][ly]++;
			c[lx][ry+1]--;
			c[rx+1][ly]--;
			c[rx+1][ly+1]++;
		}
		/*
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				cerr<<c[i][j]<<" \n"[j==n];
			}
		}
		*/
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				c[i][j]+=c[i-1][j];
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				c[i][j]+=c[i][j-1];
				if (siz-c[i][j]==k||siz-c[i][j]+1==k) {
//					cerr<<i<<','<<j<<' '<<l<<":"<<c[i][j]<<endl;
					cout<<"1\n";
					return 0;
				}
			}
		}
	}
	cout<<"2\n";
	
	return 0;
}