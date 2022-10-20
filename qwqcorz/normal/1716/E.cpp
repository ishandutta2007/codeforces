#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1<<18;

#define ls (w*2)
#define rs (w*2+1)
struct node {
	ll sum,lsum,rsum,ans;
	node(int x=0) {
		sum=x,lsum=rsum=ans=max(x,0);
	}
	friend node operator +(node a,node b) {
		node ret;
		ret.sum=a.sum+b.sum;
		ret.lsum=max(a.lsum,a.sum+b.lsum);
		ret.rsum=max(b.rsum,b.sum+a.rsum);
		ret.ans=max({a.ans,b.ans,a.rsum+b.lsum});
		return ret;
	}
}t[N*2];
ll ans[N];
int n,m,a[N],deep[N];

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	m=1<<n;
	for (int i=0;i<m;i++) {
		cin>>a[i];
		t[i+m]=node(a[i]);
	}
	for (int w=m-1;w>=1;w--) {
		t[w]=t[ls]+t[rs];
	}
	for (int i=2;i<m;i++) {
		deep[i]=deep[i/2]+1;
	}
	ans[0]=t[1].ans;
	for (int i=1;i<m;i++) {
		int x=i^(i-1),k=1;
		for (;x;x>>=1) {
			k*=2;
		}
		for (int w=k-1;w>=1;w--) {
			if (i>>deep[w]&1) {
				t[w]=t[rs]+t[ls];
			} else {
				t[w]=t[ls]+t[rs];
			}
		}
		ans[i]=t[1].ans;
	}
	int Q,S=0;
	cin>>Q;
	while (Q--) {
		int x;
		cin>>x;
		S^=1<<(n-1-x);
		cout<<ans[S]<<"\n";
	}
	
	return 0;
}