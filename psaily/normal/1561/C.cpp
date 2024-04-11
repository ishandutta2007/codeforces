#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define inf 0x3f3f3f3f
 
typedef unsigned long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head
 
const int mod=998244353;
const int N=2e5+5;

int T,n;
pii a[N];

bool check(int mid) {
	int cur=mid;
	rep(i,1,n+1) {
		if (cur>a[i].fi) cur+=a[i].se;
		else return 0;	
	}
	return 1;
}

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		rep(i,1,n+1) a[i]=mp(0,0);
		rep(i,1,n+1) {
			scanf("%d",&a[i].se);
			rep(j,0,a[i].se) {
				int x; scanf("%d",&x); x-=j;
				a[i].fi=max(a[i].fi,x);
			}
		}
		sort(a+1,a+1+n);
		int L=0,R=1e9+1,res=0;
		while (L<=R) {
			int mid=(L+R)>>1;
			if (check(mid)) res=mid,R=mid-1;
			else L=mid+1;
		}
		printf("%d\n",res);
	}
	return 0;	
}