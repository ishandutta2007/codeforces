#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e3+5;
const int NN=2e3+1;

int n,m;
struct node {
	int a[2][2];
}a[N];
struct basis {
	bitset<NN>f[NN];
	bool insert(bitset<NN>x) {
		for (int i=NN-1;i>=1;i--) {
			if (x[i]) {
				if (f[i][i]) {
					x^=f[i];
				} else {
					f[i]=x;
					return 1;
				}
			}
		}
		if (x[0]) {
			return 0;
		}
		return 1;
	}
	bitset<NN>getans() {
		bitset<NN>ans;
		for (int i=1;i<NN;i++) {
			if (f[i][i]) {
				int tmp=f[i][0];
				for (int j=1;j<i;j++) {
					tmp^=f[i][j]&ans[j];
				}
				ans.set(i,tmp);
			}
		}
		return ans;
	}
}b;

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for (int i=1;i<=n;i++) {
		a[i].a[0][0]=1;
		a[i].a[1][1]=1;
	}
	for (int i=1;i<=m;i++) {
		string s;
		cin>>s;
		int len;
		cin>>len;
		if (s=="mix") {
			bitset<NN>A,B;
			for (int j=1;j<=len;j++) {
				int x;
				cin>>x;
				if (a[x].a[0][0]) {
					A.set(x*2-1);
				}
				if (a[x].a[0][1]) {
					A.set(x*2);
				}
				if (a[x].a[1][0]) {
					B.set(x*2-1);
				}
				if (a[x].a[1][1]) {
					B.set(x*2);
				}
			}
			char c;
			cin>>c;
			if (c=='Y'||c=='B') {
				A.set(0);
			}
			if (c=='R'||c=='B') {
				B.set(0);
			}
			if (!b.insert(A)) {
				cout<<"NO\n";
				return 0;
			}
			if (!b.insert(B)) {
				cout<<"NO\n";
				return 0;
			}
			/*
			for (int i=0;i<=n*2;i++) {
				cerr<<A[i];
			}
			cerr<<endl;
			for (int i=0;i<=n*2;i++) {
				cerr<<B[i];
			}
			cerr<<endl;
			*/
		}
		if (s=="RY") {
			for (int j=1;j<=len;j++) {
				int x;
				cin>>x;
				swap(a[x].a[0],a[x].a[1]);
			}
		}
		if (s=="RB") {
			for (int j=1;j<=len;j++) {
				int x;
				cin>>x;
				a[x].a[0][0]^=a[x].a[1][0];
				a[x].a[0][1]^=a[x].a[1][1];
			}
		}
		if (s=="YB") {
			for (int j=1;j<=len;j++) {
				int x;
				cin>>x;
				a[x].a[1][0]^=a[x].a[0][0];
				a[x].a[1][1]^=a[x].a[0][1];
			}
		}
	}
	cout<<"YES\n";
	auto ans=b.getans();
	for (int i=1;i<=n;i++) {
		int x=(ans[i*2-1])<<1|ans[i*2];
		cout<<".RYB"[x];
	}
	cout<<"\n";
	
	return 0;
}