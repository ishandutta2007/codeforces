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

const int N=2e5+5;
int n,m,a[N],b[N],y;
map<int,int> m1,m2;

int main() {
	scanf("%d%d",&n,&y);
	rep(i,1,n+1) scanf("%d",&a[i]);
	scanf("%d%d",&m,&y);
	rep(i,1,m+1) scanf("%d",&b[i]);
	int pw=1,ans=(n>0)+(m>0);
	rep(i,1,32) {
		m1.clear(),m2.clear();
		int mod=2*pw;
		rep(j,1,n+1) m1[a[j]%mod]++;
		rep(j,1,m+1) m2[b[j]%mod]++;
		rep(j,1,n+1) ans=max(ans,m1[a[j]%mod]+m2[(a[j]+pw)%mod]);
		rep(j,1,m+1) ans=max(ans,m2[b[j]%mod]+m1[(b[j]+pw)%mod]);
		pw=mod;
	}
	printf("%d\n",ans);
	return 0;	
}