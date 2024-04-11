#include <bits/stdc++.h>
using namespace std;
  
#define rep(i,a,n) for (int i=(a);i<(n);i++)
#define per(i,a,n) for (int i=(a)-1;i>=(n);i--)
#define pb push_back
#define all(x) x.begin(),x.end()
#define SZ(x) (int)x.size()
#define mp make_pair
#define fi first
#define se second
#define inf 0x3f3f3f3f
#define bug(x) cerr<<#x<<'='<<x<<' '
#define debug(x) cerr<<#x<<'='<<x<<endl

typedef long long ll;
typedef pair<int,int> pii;
typedef double db;
typedef vector<int> vi;

const int N=1e5+5;
const int mod=998244353;

ll b;
int ct,cnt[100];

int main() {
	cin>>b;
	for (int i=2;1ll*i*i<=b;i++) {
		if (b%i) continue;
		ct++;
		while (b%i==0) cnt[ct]++,b/=i;
	}
	if (b!=1) cnt[++ct]=1;
	ll ans=1;
	rep(i,1,ct+1) ans=ans*(1+cnt[i]);
	printf("%lld\n",ans);
	return 0;	
}