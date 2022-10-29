#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
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
 
const int mod=998244353;
const int N=3e5+5;

int n,m,k,T;
int X[N],Y[N];
pii a[N];
int cnt[N],pos[N];

bool cmp(pii a,pii b) {return a.se<b.se;}

int main() {
	// ios::sync_with_stdio(false);
	cin>>T;
	while (T--) {
		scanf("%d%d%d",&n,&m,&k);
		rep(i,1,n+1) scanf("%d",&X[i]);
		rep(i,1,m+1) scanf("%d",&Y[i]);
		rep(i,1,k+1) scanf("%d%d",&a[i].fi,&a[i].se);
		
		ll ans=0;
		
		sort(a+1,a+1+k);
		int cur=1;
		rep(i,1,n) {
			int L=X[i],R=X[i+1];
			
			while (a[cur].fi==L&&cur<=k) cur++;
			int las=cur,tot=0;
			while (a[cur].fi<R&&cur<=k) {
				pos[cur]=lower_bound(Y+1,Y+1+m,a[cur].se)-Y;
				ans+=(tot-cnt[pos[cur]]);
				tot++,cnt[pos[cur]]++;
				cur++;
			}
			rep(j,las,cur) cnt[pos[j]]=0;
		}
		
		sort(a+1,a+1+k,cmp);
		cur=1;
		rep(i,1,m) {
			int L=Y[i],R=Y[i+1];
			while (a[cur].se==L&&cur<=k) cur++;
			int las=cur,tot=0;
			while (a[cur].se<R&&cur<=k) {
				pos[cur]=lower_bound(X+1,X+1+n,a[cur].fi)-X;
				 // bug(tot),bug(pos[cur]),debug(cnt[pos[cur]]);
				ans+=(tot-cnt[pos[cur]]);
				tot++,cnt[pos[cur]]++;
				cur++;
			}
			rep(j,las,cur) cnt[pos[j]]=0;
		}
		
		printf("%lld\n",ans);
	}
	
	return 0;
}