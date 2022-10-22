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
int n,m;
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
set<ii> s;
int l[100010],r[100010],x,y;
vector<ii> pt;
bool in(int a,int b) {
	if (s.find(mp(a,b))!=s.end()) return 1;
	if (a>=l[b] && a<=r[b]) return 1;
	return 0;
}
int dirx[]={-1,0,1,1,1,0,-1,-1};
int diry[]={1,1,1,0,-1,-1,-1,0};
bool can[8];
int main() {
	while(scanf("%d%d",&n,&m),n!=0) {
		p.clear();
		u.clear();
		d.clear();
		s.clear();
		pt.clear();
		for (int i=0;i<=n;i++) {
			l[i]=INF,r[i]=-2;
		}
		for (int i=0;i<m;i++) {
			scanf("%d%d",&x,&y);
			l[y]=min(l[y],x);
			r[y]=max(r[y],x);
			s.insert(mp(x,y));
			pt.pb(mp(x,y));
		}
		for (int i=0;i<sz(pt);i++) {
			x=pt[i].first,y=pt[i].second;
			for (int j=0;j<8;j++) {
				can[j]=in(x+dirx[j],y+diry[j]);
			}
			if (can[0]&&can[1]&&can[7]) {
				p.pb(mp(x,y+1));
			}
			if (can[1]&&can[2]&&can[3]) {
				p.pb(mp(x+1,y+1));
			}
			if (can[3]&&can[4]&&can[5]) {
				p.pb(mp(x+1,y));
			}
			if (can[5]&&can[6]&&can[7]) {
				p.pb(mp(x,y));
			}
		}
		sort(all(p),cmp);
		p.resize(distance(p.begin(),unique(all(p))));
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
		int rr=(min_element(all(u)))-u.begin();
		for (int i=0;i<s;i++) {
			printf("%d %d\n", u[(rr+i)%s].first-1,u[(rr+i)%s].second-1);
		}
	}
}