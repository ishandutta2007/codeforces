#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define make_unique(x) {sort(all(x)); x.resize(unique(all(x))-x.begin());} 
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
 
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef double db;
const int mod=1e9+7,inf=1<<30;
// head 
const int N=1e6+5;
int l,r,n,mul,ans,a[N];

bool check(int x) {
	int mx=0,mi=inf;
	rep(i,0,n) {
		mx=max(mx,a[i]^x);
		mi=min(mi,a[i]^x);
	}
	if (mx==r&&mi==l) {ans=x; return true;}
	return false;
}
void solve() {
	ans=0;
	scanf("%d%d",&l,&r); n=r-l+1;
	rep(i,0,n) scanf("%d",&a[i]);
	
	mul=1;
	set<int> st;
	while ((~l&1)&&(r&1)) l>>=1,r>>=1,mul<<=1,bug(l),debug(r);
	rep(i,0,n) a[i]/=mul,st.insert(a[i]);
	rep(i,0,n) {
		if (st.find(a[i]^1)==st.end()) {
			if (check(a[i]^l)) break;
			if (check(a[i]^r)) break;
		}
	}
	printf("%d\n",ans*mul);
}
int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
	return 0;
}