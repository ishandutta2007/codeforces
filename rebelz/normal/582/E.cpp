#include<bits/stdc++.h>

#define y1 dmytxdy
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

const int cys=1000000007;
int n,m,ntot;
int f[505][70000],a[20],b[20],c[20],d[20],e[20];
char s[505];

int mod(int x){return x>=cys?x-cys:x;}

void fwtand(int id,int op){
	for(int i=1;i<(1<<16);i<<=1)
		for(int j=0;j<(1<<16);j+=(i<<1))
			for(int k=j;k<j+i;k++)
				if(op>0) f[id][k]=mod(f[id][k]+f[id][k+i]);
				else f[id][k]=mod(f[id][k]+cys-f[id][k+i]);
}

void fwtor(int id,int op){
	for(int i=1;i<(1<<16);i<<=1)
		for(int j=0;j<(1<<16);j+=(i<<1))
			for(int k=j;k<j+i;k++)
				if(op>0) f[id][k+i]=mod(f[id][k+i]+f[id][k]);
				else f[id][k+i]=mod(f[id][k+i]+cys-f[id][k]);
}

int solve(int l,int r){
	int rt=++ntot;
	if(l==r){
		if(s[l]=='?'){
			for(int i=0;i<4;i++){
				int t=0;
				for(int j=0;j<16;j++) if((j>>i)&1) t|=(1<<j);
				f[rt][t]++,f[rt][t^((1<<16)-1)]++;
			}
		}
		else{
			if(s[l]>='a'&&s[l]<='z'){
				int t=0;
				for(int j=0;j<16;j++) if(!((j>>(s[l]-'a'))&1)) t|=(1<<j);
				f[rt][t]++;
			}
			else{
				int t=0;
				for(int j=0;j<16;j++) if((j>>(s[l]-'A'))&1) t|=(1<<j);
				f[rt][t]++;
			}
		}
		return rt;
	}
	int pos=0,now=0;
	for(int i=l;i<=r;i++){
		if(s[i]=='(') now++;
		if(s[i]==')') now--;
		if(now==0){
			pos=i+1;
			break;
		}
	}
	int lson=solve(l+1,pos-2),rson=solve(pos+2,r-1);
	if(s[pos]!='|'){
		fwtand(lson,1),fwtand(rson,1);
		for(int i=0;i<(1<<16);i++) f[rt][i]=mod(f[rt][i]+1ll*f[lson][i]*f[rson][i]%cys);
		if(s[pos]=='?') fwtand(lson,-1),fwtand(rson,-1);
		fwtand(rt,-1);
	}
	if(s[pos]!='&'){
		fwtor(lson,1),fwtor(rson,1);
		if(s[pos]=='?') fwtor(rt,1);
		for(int i=0;i<(1<<16);i++) f[rt][i]=mod(f[rt][i]+1ll*f[lson][i]*f[rson][i]%cys);
		fwtor(rt,-1);
	}
	return rt;
}

int main(){
	scanf("%s",s+1); m=strlen(s+1);
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint(),b[i]=readint(),c[i]=readint(),d[i]=readint(),e[i]=readint();
	int rt=solve(1,m); ll ans=0;
	for(int i=0;i<(1<<16);i++){
		bool fl=1;
		for(int j=1;j<=n;j++) if(((i>>(a[j]+2*b[j]+4*c[j]+8*d[j]))&1)!=e[j]) fl=0;
		if(!fl) continue;
		ans=mod(ans+f[rt][i]);
	}
	printf("%lld\n",ans);
	return 0;
}