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

const int N=2005;
int n;
ll k;

struct node {
	int l,r,cnt;
	bool operator < (const node&_) const {
		return l<_.l;
	}
}g[N];

bool check(int now,ll nowk) {
	while (now<=n) {
		node e=g[now];
		ll res1=(e.r-e.l)*k;
		ll res2=(e.r-e.l-1)*k;
		if (res1+nowk<e.cnt) return 0;
		if (res2+nowk<e.cnt&&(now<n&&g[now].r==g[now+1].l)) now++,nowk=res1+nowk-e.cnt;
		else return 1;
	}
	return 1;
}

int main() {
	scanf("%d%lld",&n,&k);
	rep(i,1,n+1) scanf("%d%d%d",&g[i].l,&g[i].r,&g[i].cnt);
	sort(g+1,g+1+n);
	int now=1;
	ll nowk=k,used=0;
	while (now) {
		if (now==n+1) break;
		if (!check(now,k)) {puts("-1"); return 0;}
		if (check(now,nowk)) {
			used+=g[now].cnt;
			nowk=nowk-(g[now].cnt%k);
			if (nowk<0) nowk+=k;
		}else {
			used+=nowk+g[now].cnt;
			nowk=k-(g[now].cnt%k);
		}
		now++;
	}
	printf("%lld\n",used);
	return 0;	
}