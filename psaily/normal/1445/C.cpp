#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define fi first
#define se second
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl
#define ll long long

const int N=1e5+5;
ll p,q;
ll pr[N],cnt[N],res[N];
int T;

int main() {
	scanf("%d",&T);
	while (T--) {
		cin>>p>>q;
		if (p<q||p%q) {printf("%lld\n",p); continue;}
		int t=0;
		for (int i=2;i*i<=q;i++) {
			if (q%i==0) {
				pr[++t]=i,cnt[t]=0;
				while (q%pr[t]==0) {
					cnt[t]++;
					q/=pr[t];
				}
			}
		}
		if (q>1) pr[++t]=q,cnt[t]=1;
		//rep(i,1,t+1) bug(pr[i]),debug(cnt[i]);
		ll x=p;
		int tmp=0;
		rep(i,1,t+1) {
			if (x%pr[i]==0) {
				int ct=0;
				while (x%pr[i]==0) x/=pr[i],ct++;
				ll zhi=1;
				//debug(ct);
				rep(j,0,ct-cnt[i]+1) zhi*=pr[i];
				//debug(zhi);
				res[++tmp]=zhi;
			}
		}
		sort(res+1,res+1+tmp);
		printf("%lld\n",p/res[1]);
	}
	return 0;	
}