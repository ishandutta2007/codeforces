#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const int maxn=100000;
int n,m;
ll mh[maxn+10],sh[maxn+10],rg[maxn+10],tm[maxn+10],now;
ll value,inc,dmg,ans;
struct op{
	ll id,v,tm;
	bool operator<(const op &t)const{
		return tm<t.tm;
	}
}a[maxn+10];
struct opt{
	ll tm,val;
	bool operator<(const opt &t)const{
		return tm==t.tm?val<t.val:tm<t.tm;
	}
}b[maxn*10+10]; int bcnt;
int main(){
	scanf("%d%d%lld%lld%lld",&n,&m,&value,&inc,&dmg);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&mh[i],&sh[i],&rg[i]);
		if(sh[i]<=dmg) ++now;
	}
	for(int i=1;i<=m;++i) scanf("%lld%lld%lld",&a[i].tm,&a[i].id,&a[i].v);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;++i){
		int p=a[i].id; ll ed=min(sh[p]+(a[i].tm-tm[p]-1)*rg[p],mh[p]);
		if(sh[p]<=dmg&&ed>dmg){
			b[++bcnt].tm=(dmg-sh[p])/rg[p]+tm[p]+1; b[bcnt].val=-1;
		}
		if(ed<=dmg&&a[i].v>dmg){
			b[++bcnt].tm=a[i].tm; b[bcnt].val=-1;
		}else if(ed>dmg&&a[i].v<=dmg){
			b[++bcnt].tm=a[i].tm; b[bcnt].val=1;
		}
		sh[p]=a[i].v; tm[p]=a[i].tm;
	}
	for(int i=1;i<=n;++i)
		if(sh[i]<=dmg&&rg[i]>0&&mh[i]>dmg){
			b[++bcnt].tm=(dmg-sh[i])/rg[i]+tm[i]+1; b[bcnt].val=-1;
		}
	sort(b+1,b+bcnt+1);
	for(int i=1;i<=bcnt;++i){
		ans=max(ans,(value+inc*(b[i].tm-1))*now); now+=b[i].val;
	}
	if(now>0&&inc>0) printf("-1"); else printf("%lld",max(ans,now*value));
	return 0;
}