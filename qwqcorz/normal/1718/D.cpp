#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int inf=1e9+7;

int n,Q,p[N],a[N],st[N],rt,ls[N],rs[N],mn[N],mx[N];
void dfs(int now) {
	mx[now]=-inf;
	if (a[now]) {
		mn[now]=min(mn[now],a[now]);
		mx[now]=a[now];
	}
	if (ls[now]) {
		mn[ls[now]]=mn[now];
		dfs(ls[now]);
		mx[now]=max(mx[now],mx[ls[now]]);
	}
	if (rs[now]) {
		mn[rs[now]]=mn[now];
		dfs(rs[now]);
		mx[now]=max(mx[now],mx[rs[now]]);
	}
}
void build() {
	int top=0;
	for (int i=0;i<=n;i++) {
		ls[i]=rs[i]=0;
	}
	for (int i=1;i<=n;i++) {
		while (top&&p[st[top]]<p[i]) {
			ls[i]=st[top--];
		}
		rs[st[top]]=i;
		st[++top]=i;
	}
	rt=rs[0];
	mn[rt]=inf;
	dfs(rt);
//	for (int i=0;i<=n;i++) {
//		cerr<<i<<':'<<ls[i]<<' '<<rs[i]<<endl;
//	}
}
int s[N];
int get(int k,vector<pair<int,int>>b) {
	sort(b.begin(),b.end(),[&](pair<int,int>a,pair<int,int>b) {
		return a.second<b.second;
	});
	set<int>S;
	for (int i=1;i<k;i++) {
		S.insert(s[i]);
//		cerr<<s[i]<<endl;
	}
	int ret=0;
	for (auto [l,r]:b) {
		auto now=S.lower_bound(l);
		if (now!=S.end()&&*now<=r) {
			S.erase(now);
		} else {
			if (ret) {
				return -inf;
			}
			ret=r;
		}
	}
	return ret;
}
void work() {
	cin>>n>>Q;
	auto NO=[&]() {
		while (Q--) {
			int x;
			cin>>x;
			cout<<"NO\n";
		}
	};
	for (int i=1;i<=n;i++) {
		cin>>p[i];
	}
	int k=0;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		k+=!a[i];
	}
	build();
	for (int i=1;i<k;i++) {
		cin>>s[i];
	}
	vector<pair<int,int>>b;
	for (int i=1;i<=n;i++) {
		if (a[i]) {
			if (!(mx[i]<=a[i]&&a[i]<=mn[i])) {
				return NO();
			}
			continue;
		}
//		cerr<<mx[i]<<'.'<<mn[i]<<endl;
		if (mx[i]>mn[i]) {
			return NO();
		}
		b.emplace_back(mx[i],mn[i]);
	}
	int r=get(k,b);
	for (auto &[l,r]:b) {
		swap(l,r);
		l=-l,r=-r;
	}
	for (int i=1;i<k;i++) {
		s[i]=-s[i];
	}
	int l=-get(k,b);
//	cerr<<l<<' '<<r<<endl;
	while (Q--) {
		int d;
		cin>>d;
		if (l<=d&&d<=r) {
			cout<<"YES\n";
		} else {
			cout<<"NO\n";
		}
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