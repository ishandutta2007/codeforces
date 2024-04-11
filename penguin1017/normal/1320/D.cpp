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
const int N=2e5+9;
const ll mod=998244353;
const int p=2011;
const ll inv=511283781;
ll seg[N<<2],mul[N];
bool pre[N<<2],suf[N<<2];
int cnt[N<<2];
char s[N];
void pushup(int pos){
	if(suf[ls(pos)]&pre[rs(pos)]){
		seg[pos]=((seg[ls(pos)]-49)*inv%mod*mul[cnt[rs(pos)]-1]%mod+seg[rs(pos)]-49*mul[cnt[rs(pos)]-1]%mod+mod)%mod;
		cnt[pos]=cnt[ls(pos)]+cnt[rs(pos)]-2;
		pre[pos]=pre[ls(pos)];
		suf[pos]=suf[rs(pos)];
		if(cnt[ls(pos)]==1)pre[pos]=0;
		if(cnt[rs(pos)]==1)suf[pos]=0;
		return;
	}
	seg[pos]=(seg[ls(pos)]*mul[cnt[rs(pos)]]%mod+seg[rs(pos)])%mod;
	cnt[pos]=cnt[ls(pos)]+cnt[rs(pos)];
	pre[pos]=pre[ls(pos)];
	suf[pos]=suf[rs(pos)];
	if(!cnt[ls(pos)])pre[pos]=pre[rs(pos)];
	if(!cnt[rs(pos)])suf[pos]=suf[ls(pos)];
}
void build(int pos,int l,int r){
	if(l==r){
		//if(l==490)cout<<pos<<' '<<s[l]<<"?????????\n";
		seg[pos]=s[l];
		cnt[pos]=1;
		if(s[l]=='1'){
			pre[pos]=1;
			suf[pos]=1;
		} 
		return;
	}
	int mid=l+r>>1;
	build(ls(pos),l,mid);
	build(rs(pos),mid+1,r);
	pushup(pos);
}
pair<pair<ll,int>,pair<bool,bool>> get(int pos,int L,int R,int l,int r){
	while(L<=l&&r<=R){
		//cout<<seg[pos]<<' '<<cnt[pos]<<' '<<l<<' '<<r<<' '<<pos<<"pos\n";
		return {{seg[pos],cnt[pos]},{pre[pos],suf[pos]}};
	}
	int mid=l+r>>1;
	if(L<=mid&&R>mid){
		pair<pair<ll,int>,pii> u=get(ls(pos),L,R,l,mid),v=get(rs(pos),L,R,mid+1,r);
		ll lsum=u.fi.fi,rsum=v.fi.fi;
		int lc=u.fi.se,rc=v.fi.se;
		bool up=u.se.fi,us=u.se.se,vp=v.se.fi,vs=v.se.se;
		//cout<<suf[ls(pos)]<<' '<<pre[rs(pos)]<<' '<<(rs(pos))<<' '<<l<<' '<<r<<"suf\n";
		if(us&vp){
			ll res=((lsum-49)*inv%mod*mul[rc-1]%mod+rsum-49*mul[rc-1]%mod+mod)%mod;
			if(lc==1)up=0;
			if(rc==1)vs=0;
			return {{res,lc+rc-2},{up,vs}};
		}
		ll res=(lsum*mul[rc]+rsum)%mod;
		if(!lc)up=vp;
		if(!rc)vs=us;
		return {{res,lc+rc},{up,vs}}; 
	}
	if(L<=mid)return get(ls(pos),L,R,l,mid);
	return get(rs(pos),L,R,mid+1,r);
}
int main(){
	mul[0]=1;
	rep(i,1,N)mul[i]=mul[i-1]*p%mod;
	int n,q;
	scanf("%d",&n);
	scanf("%s",s+1);
	build(1,1,n);
//	pii u=get(1,3,5,1,n);
//	cout<<u.fi<<' '<<u.se<<"check\n";
//	system("pause"); 
	scanf("%d",&q);
	while(q--){
		int l,r,len;
		scanf("%d%d%d",&l,&r,&len);
		pair<pair<ll,int>,pii> u=get(1,l,l+len-1,1,n),v=get(1,r,r+len-1,1,n);
		//cout<<u.fi<<' '<<u.se<<' '<<v.fi<<' '<<v.se<<"check\n";
		if(u.fi==v.fi)printf("YES\n");
		else printf("NO\n"); 
	}
}
/*
500
10101010110101101010011101110000101100111110001010111001011110101011100011100000010101100011100001001101100101111101101010000000011110110111000101000000100101000110011101111000111001110100101101010110000011101100000100011010000010001011011110010010101111100101000101010010101001010111011101010100101101110001111010000010001101111101000000010101011100101011000110100000011100100000101010011000001000000010101101000010110001010111110011010001011100100101001110110000111101111110001101111100111011001110
1
488 254 3
*/