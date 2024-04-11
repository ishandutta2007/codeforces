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

const int N=1e6+5;
const int P=1e4;

int T,n;
int a[N],b[P+5];

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d",&n);
		int mi=0; db res=linf; pii ans;
		rep(i,1,n+1) scanf("%d",&a[i]),b[a[i]]=0;
		sort(a+1,a+1+n);
		rep(i,1,n+1) {
			int x=a[i];
			b[x]++;
			if (b[x]==4) {
				ans.fi=ans.se=x;
				break;
			}
			if (b[x]>=2) {
				if (mi&&mi!=x) {
					if (1.0*x/mi+1.0*mi/x<res) res=1.0*x/mi+1.0*mi/x,ans=mp(mi,a[i]);
				}
				mi=x;
			}
		}
		printf("%d %d %d %d\n",ans.fi,ans.fi,ans.se,ans.se);
	}
	
	
	return 0;
}