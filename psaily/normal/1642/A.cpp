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
typedef double db;
// head 
pii a[4];
int ans=0;

int main() {
	int _;
	for (cin>>_;_;_--) {
		rep(i,1,4) cin>>a[i].fi>>a[i].se;
		ans=0;
		rep(i,1,4) rep(j,i+1,4) {
			rep(k,1,4) if (k!=i&&k!=j) {
				if (a[i].se==a[j].se&&a[k].se<a[i].se) {ans=abs(a[i].fi-a[j].fi); break;}
			}
				
		}
		printf("%.10lf\n",(db)ans);
	}
	return 0;	
}