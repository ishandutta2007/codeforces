#include <bits/stdc++.h>
#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
// head

const int N=1e5+5;

int n,m;
int a[N],cnt[N];

bool check(int mid) {
	if (!mid) return 1;
	int mx=0;
	rep(i,1,101) mx+=cnt[i]/mid;
	return mx>=n;
}

int main() {
	scanf("%d%d",&n,&m);
	rep(i,1,m+1) {
		int x;
		scanf("%d",&x),cnt[x]++;
	}
	int l=0,r=101,res=0;
	while (l<=r) {
		int mid=(l+r)>>1;
		// bug(l),bug(r),debug(mid);
		if (check(mid)) res=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",res);
	return 0;	
}