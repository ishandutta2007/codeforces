#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

struct RMQ { //min range query (default)
	int** st; //sparse table
	int* log;
	int combine(int a, int b) {return max(a, b);} //change to max for range max query
	RMQ() {}
	RMQ(int n, int a[]) {build(n, a);}
	void build(int n, int a[]) {
		st=new int*[n];
		log=new int[n+1];
		log[1]=0;
		for (int i=2; i<=n; ++i) log[i]=log[i/2]+1;
		int k=log[n];
		for (int i=0; i<n; ++i) st[i]=new int[k+1];
		for (int i=0; i<n; ++i) st[i][0]=a[i];
		for (int j=1; j<=k; ++j) for (int i=0; i+(1<<j)-1<n; ++i)
			st[i][j]=combine(st[i][j-1], st[i+(1<<(j-1))][j-1]);
	}
	int qry(int l, int r) {
		int k=log[r-l+1];
		return combine(st[l][k], st[r-(1<<k)+1][k]);
	}
} rmq;

const int mxN=200000;
int n, a[mxN], pos[mxN+1];

ll solve(int l, int r) { //long long just in case
	if (r-l+1<3) return 0;
	int big=rmq.qry(l, r);
	int ind=pos[big];
	if (ind==l) return solve(l+1, r);
	if (ind==r) return solve(l, r-1);
	ll res=solve(l, ind-1)+solve(ind+1, r);
	int pl=ind-l, pr=r-ind;
	if (pl<=pr) {
		for (int i=l; i<ind; ++i) {
			int x=pos[big-a[i]];
			if (ind<x&&x<=r) ++res;
		}
	}
	else {
		for (int i=ind+1; i<=r; ++i) {
			int x=pos[big-a[i]];
			if (l<=x&&x<ind) ++res;
		}
	}
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i=0; i<n; ++i)
		cin >> a[i], pos[a[i]]=i;
	rmq.build(n, a);
	ll ans=solve(0, n-1);
	cout << ans;
	return 0;
}

/* stuff you should look for
	* int overflow, array bounds
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
*/