#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;

vector<int>fac[N];
vector<pair<int,int>>a[N];
void init(int n) {
	for (int i=1;i<=n;i++) {
		for (int j=i+i;j<=n;j+=i) {
			fac[j].push_back(i);
		}
	}
	for (int i=3;i<=n;i++) {
		int pw=2;
		for (int j=i;j%2==0;j/=2) {
			pw*=2;
		}
		vector<int>A(fac[i]),B;
		for (int j:A) {
			if ((j&1)&&j*pw<i) {
				B.push_back(j*pw);
			}
		}
		int n1=A.size(),n2=B.size();
		for (int j=0;j<n1;j++) {
			int tot=n1-1-j;
			for (int k=0;k<n2;k++) {
				tot+=B[k]>=A[j]&&A[j]+B[k]>i;
			}
			a[i].emplace_back(A[j],tot);
		}
		for (int j=0;j<n2;j++) {
			int tot=0;
			for (int k=0;k<n1;k++) {
				tot+=B[j]<A[k]&&B[j]+A[k]>i;
			}
			for (int k=j+1;k<n2;k++) {
				tot+=B[j]+B[k]>i;
			}
			a[i].emplace_back(B[j],tot);
		}
	}
}
struct bit {
	int n,t[N];
	void send(int _n) {
		n=_n,memset(t,0,sizeof(t));
	}
	void add(int x,int y) {
		for (;x<=n;x+=x&-x) {
			t[x]+=y;
		}
	}
	int query(int x) {
		int ret=0;
		for (;x;x&=x-1) {
			ret+=t[x];
		}
		return ret;
	}
}t;
struct Query {
	int x,id,f;
	Query(int a=0,int b=0,int c=0) {
		x=a,id=b,f=c;
	}
};
vector<Query>q[N];
ll ans[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	init(2e5);
	int Q,m=0;
	cin>>Q;
	for (int i=1;i<=Q;i++) {
		int l,r;
		cin>>l>>r;
		q[r].emplace_back(r,i,1);
		q[r].emplace_back(l-1,i,-1);
		q[l-1].emplace_back(r,i,-1);
		q[l-1].emplace_back(l-1,i,1);
		m=max(m,r);
		auto C3=[&](int n) {
			return 1LL*n*(n-1)*(n-2)/2/3;
		};
		ans[i]=C3(r-l+1);
	}
	t.send(m);
	for (int i=1;i<=m;i++) {
		for (auto [x,y]:a[i]) {
			t.add(x,y);
		}
		for (auto [x,id,f]:q[i]) {
			ans[id]-=f*t.query(x);
		}
	}
	for (int i=1;i<=Q;i++) {
		cout<<ans[i]<<"\n";
	}
	
	return 0;
}