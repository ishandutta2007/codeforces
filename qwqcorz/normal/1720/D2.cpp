#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int LOG=33;

void ckmx(int &x,int y) {
	if (x<y) {
		x=y;
	}
}
struct node {
	int mx[2],son[2];
}t[N*LOG];
int cntn=0;
int newnode() {
	t[++cntn]=node();
	return cntn;
}
int query(int x,int y) {
	int now=0,ret=0;
	for (int i=30;i>=0;i--) {
		ckmx(ret,t[t[now].son[~x>>i&1]].mx[y>>i&1]);
		now=t[now].son[x>>i&1];
		if (!now) {
			break;
		}
	}
	return ret;
}
void insert(int x,int y,int w) {
	int now=0;
	for (int i=30;i>=0;i--) {
		if (!t[now].son[x>>i&1]) {
			t[now].son[x>>i&1]=newnode();
		}
		now=t[now].son[x>>i&1];
		ckmx(t[now].mx[y>>i&1],w);
	}
}
int n,a[N];
void work() {
	cntn=0,t[0]=node();
	cin>>n;
	for (int i=0;i<n;i++) {
		cin>>a[i];
	}
	int ans=0;
	for (int i=0;i<n;i++) {
		int now=query(a[i]^i,i)+1;
		ans=max(ans,now);
		insert(a[i]^i,a[i],now);
	}
	cout<<ans<<"\n";
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