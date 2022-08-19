// xtqqwq
#include<bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef long double ld;

template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ld eps=1e-9,pi=acos(-1);
int n,R;
pll a[3005];
bool fl[3005],can[3005];
ld lf[3005],rg[3005];

ll dist(pll x,pll y){return (x.fi-y.fi)*(x.fi-y.fi)+(x.se-y.se)*(x.se-y.se);}

int main(){
	n=readint(); R=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=readint();
	for(int i=1;i<=n;i++){
		ld l=-1e9,r=-1e9;
		for(int j=1;j<=n;j++){
			ll d=dist(a[i],a[j]);
			if(d<=1ll*R*R) continue;
			ld a1=atan2(a[j].se-a[i].se,a[j].fi-a[i].fi);
			ld a2=asin((ld)R/sqrt(d));
			ld L=a1-a2,R=a1+a2;
			while(L<-pi) L+=2*pi;
			while(R>pi) R-=2*pi;
			if(r<-2*pi) l=L,r=R;
			else{
				ld tl=l,tr=r;
				if(tl>tr) tr+=2*pi;
				if(L>R) R+=2*pi;
				if(max(L,tl)<=min(R,tr)+eps) chkmax(tl,L),chkmin(tr,R);
				else if(max(L,tl-2*pi)<=min(R,tr-2*pi)+eps) tl=max(L,tl-2*pi),tr=min(R,tr-2*pi);
				else if(max(L-2*pi,tl)<=min(R-2*pi,tr)+eps) chkmax(tl,L-2*pi),chkmin(tr,R-2*pi);
				else{
					fl[i]=1;
					break;
				}
				l=tl,r=tr;
				while(l<-pi) l+=2*pi;
				while(r<-pi) r+=2*pi;
				while(l>pi) l-=2*pi;
				while(r>pi) r-=2*pi;
			}
		}
		if(fl[i]) continue;
		if(l>r) r+=2*pi;
		if(r<-2*pi) can[i]=1;
		else lf[i]=l,rg[i]=r;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(fl[i]||fl[j]) continue;
			if(!can[i]){
				ld a1=atan2(a[j].se-a[i].se,a[j].fi-a[i].fi);
				if((a1<lf[i]-eps||a1>rg[i]+eps)&&(a1<lf[i]-2*pi-eps||a1>rg[i]-2*pi+eps)&&(a1<lf[i]+2*pi-eps||a1>rg[i]-2*pi+eps)) continue;
			}
			if(!can[j]){
				ld a1=atan2(a[i].se-a[j].se,a[i].fi-a[j].fi);
				if((a1<lf[j]-eps||a1>rg[j]+eps)&&(a1<lf[j]-2*pi-eps||a1>rg[j]-2*pi+eps)&&(a1<lf[j]+2*pi-eps||a1>rg[j]-2*pi+eps)) continue;
			}
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}