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
typedef vector<int> vi;
typedef long double db;
// head 

const int N=505;
int n;
vi a,tmp;
int pre;
vi ans;
vector<pii> ope;

bool solve() {
	int bs=a[0];
	int len=SZ(a),pos=-1;
	rep(i,1,len) if (a[i]==bs) {pos=i; break;}
	if (pos==-1) return false;
	int res=pos*2;
	ans.pb(res);
	int rpos=pos+pre;
	rep(i,1,pos) ope.pb(mp(rpos++,a[i]));
	tmp.clear();
	per(i,pos,1) tmp.pb(a[i]);
	rep(i,pos+1,len) tmp.pb(a[i]);
	a.clear();
	rep(i,0,SZ(tmp)) a.pb(tmp[i]);
	pre+=res;
	return true;
}

int main() {
	int _;
	for (cin>>_;_;_--) {
		ans.clear(),ope.clear();
		a.clear(),tmp.clear();
		pre=0;
		
		cin>>n;
		rep(i,1,n+1) {
			int k; scanf("%d",&k);
			a.pb(k);	
		}
		bool ok=1;
		while (SZ(a)) {
			if (!solve()) {ok=0; break;}
		}
		if (!ok) puts("-1");
		else {
			printf("%d\n",SZ(ope));
			rep(i,0,SZ(ope)) printf("%d %d\n",ope[i].fi+1,ope[i].se);
			printf("%d\n",SZ(ans));
			rep(i,0,SZ(ans)) printf("%d ",ans[i]);
			puts("");
		}
	}	
	
	return 0;	
}