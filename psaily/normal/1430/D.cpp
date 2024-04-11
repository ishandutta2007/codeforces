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
#define inf 0x3f3f3f3f

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef vector<int> vi;

const int N=2e5+5;
char str[N];
int n,T,cnt,a[N],res[N];
pii pr[N];

int main() {
	scanf("%d",&T);
	while (T--) {
		scanf("%d%s",&n,str+1);
		rep(i,1,n+1) a[i]=str[i]-'0';
		cnt=0;
		int l=1,r=1;
		while (r<=n) {
			if (r==n) {
				pr[++cnt]=mp(l,r);
				res[cnt]=r-l+1;
				break;
			}
			if (a[r+1]!=a[r]) {
				pr[++cnt]=mp(l,r);
				res[cnt]=r-l+1;
				l=r+1;
			}
			r++;
		}
		int now=1,lb=1,ans=0;
		while (lb<=cnt) {
			while (res[now]<=1&&now<=cnt) now++;
			if (now>cnt) {
				ans+=(cnt-lb+1+1)/2;
				break;
			}
			res[now]--;
			res[lb++]=0;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}