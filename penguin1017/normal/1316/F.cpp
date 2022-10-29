#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1 
using namespace std;
const int N=6e5+9;
const ll mod=1e9+7;
ll Lval[N<<2],Rval[N<<2],val[N<<2],inv2[N],pow2[N],Val[N];
int p[N],cnt[N<<2],ord[N],id[N];
pii a[N];
void pushup(int pos){
	val[pos]=(val[ls(pos)]+val[rs(pos)]+Lval[ls(pos)]*Rval[rs(pos)]%mod*inv2[cnt[ls(pos)]])%mod;
//	if(pos==1)cout<<Lval[ls(pos)]<<' '<<Rval[rs(pos)]<<"??\n";
	Lval[pos]=(Lval[ls(pos)]+Lval[rs(pos)]*pow2[cnt[ls(pos)]])%mod;
	Rval[pos]=(Rval[ls(pos)]+Rval[rs(pos)]*inv2[cnt[ls(pos)]])%mod;
	cnt[pos]=cnt[ls(pos)]+cnt[rs(pos)];
}
void Set(int pp,int pos,int l,int r,ll v){
	if(l==r){
		val[pos]=0;
		Lval[pos]=v;
		Rval[pos]=v*inv2[1]%mod;
	//	if(pp==4)cout<<l<<' '<<pos<<' '<<Rval[pos]<<"      look\n";
		cnt[pos]=1;
		return;
	}
	int mid=l+r>>1;
	//cout<<l<<' '<<r<<' '<<pp<<"       why\n";
	if(pp<=mid)Set(pp,ls(pos),l,mid,v);
	else Set(pp,rs(pos),mid+1,r,v);
	pushup(pos);
	//cout<<pp<<' '<<pos<<' '<<val[pos]<<"Pos\n";
}
void Del(int pp,int pos,int l,int r){
	if(l==r){
		val[pos]=0;
		Lval[pos]=0;
		Rval[pos]=0;
		cnt[pos]=0;
		return;
	}
	int mid=l+r>>1;
	if(pp<=mid)Del(pp,ls(pos),l,mid);
	else Del(pp,rs(pos),mid+1,r);
	pushup(pos);
}
int main(){
	int n,q;
	inv2[0]=1;
	pow2[0]=1;
	rep(i,1,N)inv2[i]=inv2[i-1]*500000004%mod,pow2[i]=pow2[i-1]*2%mod; 
	scanf("%d",&n);
	rep(i,1,n+1)scanf("%d",&a[i].fi),a[i].se=i,Val[i]=a[i].fi;
	scanf("%d",&q);
	rep(i,n+1,n+q+1)scanf("%d%d",&id[i],&a[i].fi),a[i].se=i,Val[i]=a[i].fi;
	sort(a+1,a+n+q+1);
	rep(i,1,n+q+1)p[a[i].se]=i;
	rep(i,1,n+1)Set(p[i],1,1,n+q,Val[i]),ord[i]=p[i];
	printf("%lld\n",val[1]);
	rep(i,n+1,n+q+1){
		Del(ord[id[i]],1,1,n+q);
		//cout<<ord[id[i]]<<' '<<p[i]<<' '<<Val[i]<<"check\n";
		ord[id[i]]=p[i];
		//cout<<ord[id[i]]<<' '<<val[1]<<"val\n";
		Set(p[i],1,1,n+q,Val[i]);
		printf("%lld\n",val[1]);
	}
}