#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const ll inf=1e18;

template<typename T>
void ckmn(T &x,T y) {
	if (x>y) {
		x=y;
	}
}
int n;
struct point {
	int x,y;
}a[N][2],b[N][2];
ll f[20][N][2][2];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<n;i++) {
		cin>>a[i][0].x>>a[i][0].y>>a[i][1].x>>a[i][1].y;
		b[i][0]=a[i][0],b[i][1]=a[i][1];
		b[i][0].x++,b[i][1].y++;
	}
	memset(f,0x3f,sizeof(f));
	for (int i=1;i<n;i++) {
		for (int u=0;u<=1;u++) {
			for (int v=0;v<=1;v++) {
				f[0][i][u][v]=abs(a[i][u].x-b[i][v].x)+abs(a[i][u].y-b[i][v].y);
			}
		}
	}
	for (int j=1;j<20;j++) {
		for (int i=1;i+(1<<j)<=n;i++) {
			for (int u=0;u<=1;u++) {
				for (int v=0;v<=1;v++) {
					for (int p=0;p<=1;p++) {
						for (int q=0;q<=1;q++) {
							int mid=i+(1<<(j-1));
							ckmn(f[j][i][u][v],
								f[j-1][i][u][p]+f[j-1][mid][q][v]+
								abs(b[mid-1][p].x-a[mid][q].x)+abs(b[mid-1][p].y-a[mid][q].y)
							);
						}
					}
				}
			}
		}
	}
	int Q;
	cin>>Q;
	while (Q--) {
		int x0,y0,x1,y1;
		cin>>x0>>y0>>x1>>y1;
		int w0=max(x0,y0),w1=max(x1,y1);
		if (w0>w1) {
			swap(x0,x1);
			swap(y0,y1);
			swap(w0,w1);
		}
		if (w0==w1) {
			cout<<abs(x0-x1)+abs(y0-y1)<<"\n";
			continue;
		}
		ll ans[2]={abs(x0-a[w0][0].x)+abs(y0-a[w0][0].y)+1,abs(x0-a[w0][1].x)+abs(y0-a[w0][1].y)+1};
		for (int now=w0+1,i=19;i>=0;i--) {
			if (now+(1<<i)<=w1) {
				ll nxt[2]={inf,inf};
				for (int u=0;u<=1;u++) {
					for (int v=0;v<=1;v++) {
						for (int w=0;w<=1;w++) {
							ckmn(nxt[v],
								ans[u]+f[i][now][w][v]+
								abs(b[now-1][u].x-a[now][w].x)+abs(b[now-1][u].y-a[now][w].y)
							);
						}
					}
				}
				swap(ans,nxt);
				now+=1<<i;
			}
		}
		ll res=inf;
		for (int i=0;i<=1;i++) {
			ckmn(res,ans[i]+abs(x1-b[w1-1][i].x)+abs(y1-b[w1-1][i].y));
		}
		cout<<res<<"\n";
	}
	
	return 0;
}