#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=3e5+5;
const int B=40;

struct bit {
	int n;
	ll t[N];
	void send(int _n) {
		n=_n,memset(t,0,sizeof(t));
	} 
	void add(int x,ll y) {
		for (;x<=n;x+=x&-x) {
			t[x]+=y;
		}
	}
	ll query(int x) {
		ll ret=0;
		for (;x;x&=x-1) {
			ret+=t[x];
		}
		return ret;
	}
	ll query(int l,int r) {
		return query(r)-query(l-1);
	}
}t[B];
mt19937 rnd(time(0));
int n,Q,a[N],c[N*2][B],cnt=0;
int newcol() {
	cnt++;
	for (int i=0;i<B;i++) {
		c[cnt][i]=rnd()%int(3e5)+1;
	}
	return cnt;
}
void work() {
	unordered_map<int,int>mp;
	cin>>n>>Q;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (!mp.count(a[i])) {
			mp[a[i]]=newcol();
		}
		a[i]=mp[a[i]];
	}
	for (int i=0;i<B;i++) {
		t[i].send(n);
		for (int j=1;j<=n;j++) {
			t[i].add(j,c[a[j]][i]);
		}
	}
	while (Q--) {
		int opt;
		cin>>opt;
		if (opt==1) {
			int x,y;
			cin>>x>>y;
			for (int i=0;i<B;i++) {
				t[i].add(x,-c[a[x]][i]);
			}
			if (!mp.count(y)) {
				mp[y]=newcol();
			}
			a[x]=y=mp[y];
			for (int i=0;i<B;i++) {
				t[i].add(x,c[a[x]][i]);
			}
		} else {
			int l,r,k;
			cin>>l>>r>>k;
			bool ok=(r-l+1)%k==0;
			for (int i=0;i<B;i++) {
				if (t[i].query(l,r)%k) {
					ok=0;
					break;
				}
			}
			if (ok) {
				cout<<"YES\n";
			} else {
				cout<<"NO\n";
			}
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
/*

2 1
1 1
2 1 2 2

*/