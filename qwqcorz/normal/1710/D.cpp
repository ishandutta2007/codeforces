#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e3+5;

struct dsu {
	int fa[N];
	void send(int n) {
		for (int i=1;i<=n;i++) {
			fa[i]=i;
		}
	}
	int find(int x) {
		return fa[x]==x?x:fa[x]=find(fa[x]);
	}
	void merge(int x,int y) {
		fa[find(x)]=find(y);
	}
}d;
bool a[N][N];
void work() {
	int n;
	cin>>n;
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			char c;
			cin>>c;
			a[i][j]=c=='1';
		}
	}
	d.send(n);
	vector<pair<int,int>>ans;
	auto link=[&](int x,int y) {
		ans.emplace_back(x,y);
		d.merge(x,y);
	};
	for (int i=1;i<=n;i++) {
		for (int j=1;j+i-1<=n;j++) {
			int l=j,r=j+i-1;
			if (!a[l][r]) {
				continue;
			}
			int L=d.find(l),R=d.find(r);
			if (L==R) {
				continue;
			}
			vector<int>a;
			for (int i=l+1;i<r;i++) {
				int x=d.find(i);
				if (x!=L&&x!=R&&x!=d.find(i-1)) {
					a.push_back(i);
				}
			}
			link(l,r);
			for (int i=1;i<(int)a.size();i+=2) {
				link(l,a[i]);
				l=a[i];
			}
			for (int i=0;i<(int)a.size();i+=2) {
				link(r,a[i]);
				r=a[i];
			}
		}
	}
	for (auto [x,y]:ans) {
		cout<<x<<' '<<y<<'\n'; 
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}