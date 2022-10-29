#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,n,a) for (int i=(n)-1;i>=(a);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) ((int)x.size())
#define make_unique(x) { sort(all(x)); x.resize(unique(all(x))-x.begin()); }
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
mt19937 mrand(time(0));
typedef long long ll;
typedef double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=998244353;
// head
const int N=1e6+5;
int n,d1[N],d2[N];
ll p[N];

bool work(int v) {// x = dis
	//debug(v);
	// abs(a[i]-b[i]) == v || a[i]+b[i] == v
	// a[i]>v a[i]-b[i] == v

	unordered_map<int,int> cnt;
	rep(i,1,n+1) cnt[d2[i]]++;
	per(i,n+1,1) {
		int x=d1[i];
		// y = x + v , x - v
		//1 y - x == v
		//2 x + y == v
		//3 x - y == v
		if (cnt[x+v]) {
			cnt[x+v]--;
		} else {
			if (!cnt[abs(v-x)]) return false;
			cnt[abs(v-x)]--;
		}

	}
	return true;
}

/*
YES
10 11 11 12 14 16 16 17 18 19 
0 18
*/

void gao(int dis) {
	//debug(dis);
	ll p1=1e9,p2=p1+dis;
	map<int,int> cnt;

	rep(i,1,n+1) cnt[d2[i]]++;
	per(i,n+1,1) {
		if (cnt[d1[i]+dis]) d2[i]=d1[i]+dis,cnt[d1[i]+dis]--;
		else {
			d2[i]=abs(d1[i]-dis),cnt[abs(d1[i]-dis)]--;
		}
	}

	rep(i,1,n+1) {
		if (abs(d1[i]-d2[i])==dis) {
			if (d1[i]>d2[i]) {
				p[i]=p2+d2[i];
			} else {
				p[i]=p1-d1[i];
			}
		} else if (d1[i]+d2[i]==dis) {
			p[i]=p1+d1[i];
		}
	}

	ll mn=1e10;
	rep(i,1,n+1) mn=min(mn,p[i]);
	mn=min(mn,p1);
	mn=min(mn,p2);

	p1-=mn,p2-=mn;
	rep(i,1,n+1) p[i]-=mn;

	ll mx=*max_element(p+1,p+1+n);

	if (mx>2e9 || max(p1,p2)>2e9) { puts("NO"); return; }
	puts("YES");
	rep(i,1,n+1) printf("%lld ",p[i]);
	puts("");
	printf("%lld %lld\n",p1,p2);
}

void solve() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&d1[i]);
	rep(i,1,n+1) scanf("%d",&d2[i]);
	sort(d1+1,d1+1+n);
	sort(d2+1,d2+1+n);

	rep(i,1,n+1) {
		if (work(d1[1]+d2[i])) {
			gao(d1[1]+d2[i]);
			return;
		}
		if (work(abs(d1[1]-d2[i]))) {
			gao(abs(d1[1]-d2[i]));
			return;
		}
	}
	puts("NO");

}

int main() {
	int tt;
	scanf("%d",&tt);
	while (tt--) {
		solve();
	}
	return 0;
}