#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
const int L=17;

int a[N],Log[N];
struct segment {
	int l,r;
	segment operator +(segment a) {
		return (segment){
			min(l,a.l),max(r,a.r)
		};
	}
}st[17][34][N];
segment f(int k,segment a) {
	if (a.l==a.r) {
		return a;
	}
	int p=Log[a.r-a.l];
	return st[p][k][a.l]+st[p][k][a.r-(1<<p)];
}
void init(int n) {
	for (int i=1;i<n;i++) {
		st[0][0][i]=(segment){
			min(a[i],a[i+1]),max(a[i],a[i+1])
		};
	}
	for (int j=1;j<17;j++) {
		for (int i=1;i+(1<<j)-1<n;i++) {
			st[j][0][i]=st[j-1][0][i]+st[j-1][0][i+(1<<(j-1))];
		}
	}
	for (int k=1;k<34;k++) {
		for (int i=1;i<n;i++) {
			st[0][k][i]=f(k-1,f(k-1,(segment){i,i+1}));
		}
		for (int j=1;j<17;j++) {
			for (int i=1;i+(1<<j)-1<n;i++) {
				st[j][k][i]=st[j-1][k][i]+st[j-1][k][i+(1<<(j-1))];
			}
		}
	}
}
void work() {
	int n,Q;
	cin>>n>>Q;
	for (int i=2;i<=n;i++) {
		Log[i]=Log[i/2]+1;
	}
	for (int i=1;i<=n;i++) {
		cin>>a[i];
	}
	init(n);
	for (int i=1;i<=Q;i++) {
		ll ans=0;
		segment q;
		cin>>q.l>>q.r;
		if (q.l==1&&q.r==n) {
			cout<<"0\n";
			continue;
		}
		for (int k=33;k>=0;k--) {
			auto nxt=f(k,q);
			if (nxt.l==1&&nxt.r==n) {
				continue;
			}
			q=nxt;
			ans|=1LL<<k;
		}
		auto nxt=f(0,q);
		if (nxt.l==1&&nxt.r==n) {
			cout<<ans+1<<"\n";
		} else {
			cout<<"-1\n";
		}
	}
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int T=1;
//	cin>>T;
	while (T--) {
		work();
	}
	
	return 0;
}