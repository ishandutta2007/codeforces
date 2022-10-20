#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int dx[4]={0,0,1,-1};
const int dy[4]={1,-1,0,0};

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	vector<vector<int>>a(n,vector<int>(m)),b(a);
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin>>a[i][j];
		}
	}
	auto check=[&](int x,int y) {
		if (a[x][y]==1) {
			return 1;
		}
		for (int d=0;d<4;d++) {
			int nx=x+dx[d],ny=y+dy[d];
			if (nx<0||nx>=n||ny<0||ny>=m) {
				continue;
			}
			if (a[x][y]>a[nx][ny]) {
				return 1;
			}
		}
		return 0;
	};
	int tot=0,ans=0,x0=0,y0=0;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			tot+=b[i][j]=!check(i,j);
			if (b[i][j]) {
				x0=i,y0=j;
			}
		}
	}
	if (!tot) {
		cout<<"0\n";
		return 0;
	}
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			if (abs(i-x0)+abs(j-y0)>1) {
				continue;
			}
			for (int x=0;x<n;x++) {
				for (int y=0;y<m;y++) {
					if (abs(x-x0)+abs(y-y0)<=1&&make_pair(x,y)<make_pair(i,j)) {
						continue;
					}
					auto fix=[&](int x,int y) {
						int ret=0;
						ret-=b[x][y];
						ret+=b[x][y]=!check(x,y);
						for (int d=0;d<4;d++) {
							int nx=x+dx[d],ny=y+dy[d];
							if (nx<0||nx>=n||ny<0||ny>=m) {
								continue;
							}
							ret-=b[nx][ny];
							ret+=b[nx][ny]=!check(nx,ny);
						}
						return ret;
					};
					swap(a[i][j],a[x][y]);
					int A=fix(i,j),B=fix(x,y);
					if (tot+A+B==0) {
						ans++;
					}
					swap(a[i][j],a[x][y]);
					fix(i,j),fix(x,y);
				}
			}
		}
	}
	if (ans) {
		cout<<"1 "<<ans<<"\n";
	} else {
		cout<<"2\n";
	}
	
	return 0;
}