#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;

int n,a[N],Log[N];
void solve2(int l,int r) {
	if (l==r) {
		return;
	}
	int mid=(l+r)/2;
	for (int i=l,j=mid+1;i<=mid;i++,j++) {
		a[i]^=a[j];
	}
	solve2(l,mid);
	solve2(mid+1,r);
}
void solve1(int l,int r) {
	if (l==r) {
		return;
	}
	int k=1<<Log[r-l];
	for (int i=l;i+k<=r;i++) {
		a[i+k]^=a[i];
	}
	solve2(l,l+k-1);
	solve1(l+k,r);
	for (int i=1;i<=r-l+1-k;i++) {
		a[l+k-i]^=a[r-i+1];
	}
	rotate(a+l,a+l+k,a+r+1);
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n;
	for (int i=1;i<=n;i++) {
		cin>>a[i];
		if (i>1) {
			Log[i]=Log[i/2]+1;
		}
	}
	solve1(1,n);
	for (int i=1;i<=n;i++) {
		cout<<a[i]<<" \n"[i==n];
	}
	
	return 0;
}