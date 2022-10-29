#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
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

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef pair<long long,int> pli;
typedef double db;
// head

const int N=1e5+5;
int T,n,a[N];

int main() {
	cin>>T;
	while (T--) {
		scanf("%d",&n);
		rep(i,1,n+1) scanf("%d",&a[i]);
		int ans=0;
		rep(j,0,32) {
			bool f=1;
			rep(i,1,n+1) if (!((a[i]>>j)&1)) f=0;
			if (f) ans|=(1<<j);
		}
		printf("%d\n",ans);
	}
	return 0;	
}