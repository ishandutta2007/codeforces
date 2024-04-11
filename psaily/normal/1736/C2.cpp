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
typedef long double db;
typedef pair<int,int> PII;
typedef vector<int> VI;
const int inf=1<<30;
const int mod=1e9+7;
// head
const int N=1e6+5;
const db eps=1e-9;
int n,q,a[N];

int main() {
	scanf("%d",&n);
	rep(i,1,n+1) scanf("%d",&a[i]);

	ll ans=0;
	int cmx=0,mx=0;
	vector<ll> sum(n+1),csum(n+1);
	vector<int> v(n+1),L(n+1),cL(n+1);

	rep(i,1,n+1) {
		v[i]=max(0,i-a[i]);
		if (v[i]>mx) {
			cmx=mx,mx=v[i];
		} else if (v[i]>cmx) cmx=v[i];
		L[i]=max(L[i-1],v[i]);
		cL[i]=max(cL[i-1],cmx);
		sum[i]=sum[i-1]+L[i];
		csum[i]=csum[i-1]+cL[i];
		ans+=i-L[i];
	}

	scanf("%d",&q);
	rep(qq,0,q) {
		int x,t;
		scanf("%d%d",&x,&t);
		t=max(0,x-t);

		// p>=x
		if (t>=v[x]) {// t>=v[x]
			auto it=partition_point(L.begin()+x,L.begin()+n+1,[&](int x){ 
				return x<=t;
			});
			// L[p]<=t
			int p=it-L.begin()-1;
			// [x,p]
			ll res=ans;
			if (x<=p) {
				res+=(sum[p]-sum[x-1]);
				res-=(ll)(p-x+1)*t;
			}
			printf("%lld\n",res);
		} else {// t<a[x]
			int pr=v[x];
			auto it=partition_point(L.begin()+x,L.begin()+n+1,[&](int x){ 
				return x<=pr;
			});
			int p=it-L.begin()-1;
			ll res=ans;
			// L[p]==t
			if (p>=x) {
				auto it1=partition_point(cL.begin()+x,cL.begin()+p+1,[&](int x){ 
					return x<=t;
				});
				int rp=it1-cL.begin()-1;
				// [rp,x] i<=t
				if (rp>=x) {
					res-=t*(rp-x+1)-(sum[rp]-sum[x-1]);
				}
				// [rp+1,p]
				if (rp+1<=p) {
					res-=(csum[p]-csum[rp])-(sum[p]-sum[rp]);
				}
			}
			printf("%lld\n",res);
		}
	}

	return 0;
}