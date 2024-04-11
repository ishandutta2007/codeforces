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

typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef unsigned long long ull;
// head

const int N=2e5+5;
int n,h;
pii a[N];
ll sum[N],len[N];
set<pll> st;

int main() {
	scanf("%d%d",&n,&h);
	rep(i,1,n+1) scanf("%d%d",&a[i].fi,&a[i].se);
	sort(a+1,a+1+n);
	ll ans=0;
	st.insert(mp(0,1));
	if (h==1) {
		ll mx=0;
		rep(i,1,n+1) mx=max(mx,(ll)a[i].se-a[i].fi);
		printf("%lld\n",mx+h);
		return 0;
	}
	rep(i,1,n+1) {
		int res=a[i].fi-a[i-1].se;
		sum[i]=sum[i-1]+res;
		len[i]=len[i-1]+a[i].se-a[i].fi;
		// sum[i]-sum[k]<h	,sum[k]>sum[i]-h
		// [i-k]
		set<pll>::iterator it=st.upper_bound(mp(sum[i]-h,inf));
		if (it!=st.end()) {
			ll k=(*it).se;
			// ll res=len[i]-len[k-1]+h;
			// bug(i),bug(k),debug(res);/
			ans=max(len[i]-len[k-1]+h,ans);
		}
		st.insert(mp(sum[i],i));
	}
	printf("%lld\n",ans);
	return 0;	
}