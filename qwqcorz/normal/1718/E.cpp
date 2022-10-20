#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
using namespace std;
const int N=2e5+5;

int n,m,pa[N],pb[N];
ull val[N],h1[N],h2[N];
vector<pair<int,int>>A[N],B[N];
struct stack {
	int st[N],t=0;
	void push(int x) {
		st[++t]=x;
	}
	void pop() {
		t--;
	}
	int top() {
		return st[t];
	}
	bool empty() {
		return t==0;
	}
	void clear() {
		t=0;
	}
}st;
bool dfs(int x,int y) {
	if (pa[x]==y&&pb[y]==x) {
		return 1;
	}
	if (h1[x]!=h2[y]||pa[x]||pb[y]) {
		return 0;
	}
	pa[x]=y,pb[y]=x,st.push(x);
	for (int i=0;i<(int)A[x].size();i++) {
		if (!dfs(A[x][i].second,B[y][i].second)) {
			return 0;
		}
	}
	return 1;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	mt19937_64 rnd(time(0));
	for (int i=1;i<=2e5;i++) {
		val[i]=rnd();
	}
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int c;
			cin>>c;
			if (c) {
				A[i].emplace_back(c,j+n),h1[i]^=val[c];
				A[j+n].emplace_back(c,i),h1[j+n]^=val[c];
			}
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<=m;j++) {
			int c;
			cin>>c;
			if (c) {
				B[i].emplace_back(c,j+n),h2[i]^=val[c];
				B[j+n].emplace_back(c,i),h2[j+n]^=val[c];
			}
		}
	}
	for (int i=1;i<=n+m;i++) {
		sort(A[i].begin(),A[i].end());
		sort(B[i].begin(),B[i].end());
	}
	int l=1,r=n;
	if (n>m) {
		l=1+n,r=m+n;
	}
	for (int i=l;i<=r;i++) {
		if (!pa[i]) {
			bool flag=0;
			for (int j=l;j<=r;j++) {
				if (!pb[j]&&h1[i]==h2[j]) {
					if (dfs(i,j)) {
						st.clear();
						flag=1;
						break;
					} else {
						while (!st.empty()) {
							int x=st.top(); st.pop();
							pa[x]=pb[pa[x]]=0;
						}
					}
				}
			}
			if (!flag) {
				cout<<"-1\n";
				return 0;
			}
		}
	}
	for (int i=1,j=1;i<=n+m;i++) {
		if (!pa[i]) {
			while (pb[j]) {
				j++;
			}
			pa[i]=j;
			pb[j]=i;
		}
	}
	vector<tuple<int,int,int>>ans;
	for (int i=1;i<=n;i++) {
		while (pa[i]<i) {
			ans.emplace_back(1,i,pa[i]);
			swap(pa[i],pa[pa[i]]);
		}
	}
	for (int i=1+n;i<=m+n;i++) {
		while (pa[i]<i) {
			ans.emplace_back(2,i-n,pa[i]-n);
			swap(pa[i],pa[pa[i]]);
		}
	}
	cout<<ans.size()<<"\n";
	for (auto [opt,x,y]:ans) {
		cout<<opt<<' '<<x<<' '<<y<<"\n";
	}
	
	return 0;
}