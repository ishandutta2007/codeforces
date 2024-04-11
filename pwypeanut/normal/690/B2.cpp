#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mp make_pair
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define INF 1000000000
int g[510][510];
int n;
vector<ii> p,u,d;
int ccw(ii a,ii b,ii c) {
	int dx1=b.first-a.first,dy1=b.second-a.second;
	int dx2=c.first-b.first,dy2=c.second-b.second;
	return (dx1*dy2-dx2*dy1>=0);
}
bool cmp(ii a,ii b) {
	if (a.first==b.first) return a.second>b.second;
	return a.first<b.first;
}
int main() {
	while(scanf("%d",&n),n!=0) {
		p.clear();
		u.clear();
		d.clear();
		char c;
		for (int i=0;i<=n+1;i++) {
			for (int j=0;j<=n+1;j++) {
				g[i][j]=0;
			}
		}
		for (int i=1;i<=n;i++) {
			for (int j=1;j<=n;j++) {
				scanf(" %c",&c);
				g[i][j]=c-'0';
			}
		}
		n+=2;
		for (int i=0;i<n-1;i++) {
			for (int j=0;j<n-1;j++) {
				if (g[i][j] && g[i][j+1] && g[i+1][j] && g[i+1][j+1]) {
					int y=n-2-i,x=j;
					p.pb(mp(x,y));
					//printf("%d %d\n", x,y);
				}
			}
		}
		sort(all(p),cmp);
		u.pb(p[0]);
		for (int i=0;i<sz(p);i++) {
			while(sz(u)>1 && ccw(u[sz(u)-2],u[sz(u)-1],p[i])) {
				u.pop_back();
			}
			u.pb(p[i]);
		}
		d.pb(p[sz(p)-1]);
		for (int i=sz(p)-2;i>=0;i--) {
			while(sz(d)>1 && ccw(d[sz(d)-2],d[sz(d)-1],p[i])) {
				d.pop_back();
			}
			d.pb(p[i]);
		}
		for (int i=1;i<sz(d)-1;i++) {
			u.pb(d[i]);
		}
		int s=sz(u);
		printf("%d\n", s);
		int r=(min_element(all(u)))-u.begin();
		for (int i=0;i<s;i++) {
			printf("%d %d\n", u[(r+i)%s].first,u[(r+i)%s].second);
		}
	}
}