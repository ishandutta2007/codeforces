#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define linf 0x3f3f3f3f3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

// typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
// typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int N=32;
int l,r,ll,rr;
int mx;

#define f(x) (x>=mid?x-mid:x)
void solve(int l,int r,int l1,int r1,int l2,int r2) {
	if (l1>r1||l2>r2) return;
	if (r1-l1+1<=mx||r2-l2+1<=mx) return;
	bug(l),bug(r),bug(l1),bug(r1),bug(l2),bug(r2),debug(mx);
	if (l1<=l2&&r2<=r1) {mx=max(mx,r2-l2+1); return;}
	if (l2<=l1&&r1<=r2) {mx=max(mx,r1-l1+1); return;}
	mx=max(mx,min(r1,r2)-max(l1,l2)+1);
	if (l==r) return;
	int mid=(l+r)>>1;
	// [l,mid-1],[mid+1,r]  
	int c1=0,c2=0;
	pii a[2],b[2];
	// [l,r] mid
	if (l1<=mid&&mid<=r1) a[c1++]=mp(l1,mid-1),a[c1++]=mp(1,r1-mid);
	else a[c1++]=mp(f(l1),f(r1));
	if (l2<=mid&&mid<=r2) b[c2++]=mp(l2,mid-1),b[c2++]=mp(1,r2-mid);
	else b[c2++]=mp(f(l2),f(r2));
	rep(i,0,c1) rep(j,0,c2) solve(l,mid-1,a[i].fi,a[i].se,b[j].fi,b[j].se);
}                                       

int main() {
	cin>>l>>r>>ll>>rr;
	solve(1,(1<<30)-1,l,r,ll,rr);
	printf("%d\n",mx);
	return 0;	
}