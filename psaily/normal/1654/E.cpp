#include <bits/stdc++.h>
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

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=1e5+5;
int n,a[N];

#define S 200
int ans,ret=0;
void solve1() {//[-S,S] 
	static ll b[N];
	rep(k,-S,S+1) {
		rep(i,1,n+1) {
			b[i]=a[i]-k*i;
		}
		sort(b+1,b+1+n);
		int c=0; ll las=-1;
		rep(i,1,n+1) {
			if (b[i]==las) {
				c++;
				if (c>ret) ret=c;
			}else las=b[i],c=1;
		}
	}
}


void solve2() {// [N/S]
	static int cnt[2*N];
	rep(i,1,n+1) {
		rep(j,max(1,i-N/S-1),i) {
			if ((a[i]-a[j])%(i-j)==0) {
				int t=(a[i]-a[j])/(i-j);
				t+=N;
				++cnt[t];
				if (cnt[t]+1>ret) ret=cnt[t]+1;
			}
		}
		rep(j,max(1,i-N/S-1),i) {
			if ((a[i]-a[j])%(i-j)==0) {
				int t=(a[i]-a[j])/(i-j);
				t+=N;
				--cnt[t];
			}
		}
	}
	// debug(ret);
		
}

int main() {
	scanf("%d",&n); ans=n-1;
	rep(i,1,n+1) scanf("%d",&a[i]);
	solve1();
	solve2();
	ans=min(ans,n-ret);
	printf("%d\n",ans);
	return 0;	
}