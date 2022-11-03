#include<bits/stdc++.h>
#define il inline
#define vd void
#define rg register
#define ll long long
#define mod 1000000007
using std::bitset;
il int gi(){
	rg int x=0,f=0;rg char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int pr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293};//62
int inv[62];
int MUL[1600010],a[400100],LZ[1600010];
bitset<62>b[400100],SUM[1600010],lz[1600010],upd;
il int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
#define mid ((l+r)>>1)
il vd build(int x,int l,int r){
	LZ[x]=1;
	if(l==r){SUM[x]=b[l],MUL[x]=a[l];return;}
	build(x<<1,l,mid),build(x<<1|1,mid+1,r);
	MUL[x]=1ll*MUL[x<<1]*MUL[x<<1|1]%mod;
	SUM[x]=SUM[x<<1]|SUM[x<<1|1];
}
il vd up(int x,int l,int r,const bitset<62>&d,const int&k){
	MUL[x]=1ll*MUL[x]*pow(k,r-l+1)%mod;LZ[x]=1ll*LZ[x]*k%mod;
	SUM[x]|=d;lz[x]|=d;
}
il vd down(int x,int l,int r){
	if(LZ[x]!=1)up(x<<1,l,mid,lz[x],LZ[x]),up(x<<1|1,mid+1,r,lz[x],LZ[x]),LZ[x]=1,lz[x]=0;
}
il vd update(int x,int l,int r,const int&L,const int&R,const bitset<62>&d,const int&k){
	if(L<=l&&r<=R)return up(x,l,r,d,k);
	down(x,l,r);
	if(L<=mid)update(x<<1,l,mid,L,R,d,k);
	if(mid<R)update(x<<1|1,mid+1,r,L,R,d,k);
	MUL[x]=1ll*MUL[x<<1]*MUL[x<<1|1]%mod;
	SUM[x]=SUM[x<<1]|SUM[x<<1|1];
}
il vd query(int x,int l,int r,const int&L,const int&R,int&ret_mul,bitset<62>&ret_sum){
	if(L<=l&&r<=R){ret_mul=1ll*ret_mul*MUL[x]%mod,ret_sum|=SUM[x];return;}
	down(x,l,r);
	if(L<=mid)query(x<<1,l,mid,L,R,ret_mul,ret_sum);
	if(mid<R)query(x<<1|1,mid+1,r,L,R,ret_mul,ret_sum);
}
#undef mid 
int main(){
	int n=gi(),q=gi();
	for(int i=0;i<62;++i)inv[i]=pow(pr[i],mod-2);
	for(int i=1;i<=n;++i){
		a[i]=gi();
		for(int j=0;j<62;++j)if(a[i]%pr[j]==0)b[i][j]=1;
	}
	build(1,1,n);
	char opt[10];
	int l,r,x;
	while(q--){
		scanf("%s",opt);
		if(opt[0]=='M'){
			l=gi(),r=gi(),x=gi();
			upd=0;
			for(int j=0;j<62;++j)if(x%pr[j]==0)upd[j]=1;
			update(1,1,n,l,r,upd,x);
		}else{
			l=gi(),r=gi();
			x=1,upd=0;
			query(1,1,n,l,r,x,upd);
			for(int i=0;i<62;++i)if(upd[i])x=1ll*x*inv[i]%mod*(pr[i]-1)%mod;
			printf("%d\n",x);
		}
	}
	return 0;
}