#include <stdio.h>
#include <vector>
#define MN 50
#define MM 100000
typedef long long ll;
const int mod = 998244353;

using std::vector;

int n,m,l[MN+5],r[MN+5];

vector<int> ps;
bool np[MM+5];
int miu[MM+5];

void init(int m){
	miu[1] = 1;
	for(int i=2;i<=m;i++){
		if(!np[i]){
			ps.push_back(i);
			miu[i] = -1;
		}
		for(int p:ps){
			if(i*p>m) break;
			np[i*p] = true;
			if(i%p==0){
				miu[i*p] = 0;
				break;
			}
			miu[i*p] = -miu[i];
		}
	}
}

int uppdiv(int x,int y){
	return (x+y-1)/y;
}

int f[MM+5],pf[MM+5];

int solve(int g){
	int cm = m/g;
	f[0] = 1;
	pf[0] = 1;
	for(int i=1;i<=cm;i++){
		f[i] = 0;
		pf[i] = 1;
	}
	for(int i=1;i<=n;i++){
		int cl = uppdiv(l[i],g);
		int cr = r[i]/g;
		if(cl>cr) return 0;
		for(int j=cm;j>=cl;j--){
			f[j] = pf[j-cl];
			if(j-cr-1>=0)
				f[j] = (f[j]-f[j-cr-1]+mod)%mod;
		}
		for(int j=cl-1;j>=0;j--){
			f[j] = 0;
		}
		pf[0] = f[0];
		for(int j=1;j<=cm;j++)
			pf[j] = (pf[j-1]+f[j])%mod;
	}
	return pf[cm];
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&l[i],&r[i]);
	init(m);
	ll ans = 0;
	for(int i=1;i<=m;i++){
		if(miu[i]==0) continue;
		ans = (ans+mod+miu[i]*solve(i))%mod;
	}
	printf("%lld\n",ans);
}