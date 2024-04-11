// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[250005],lg2[250005],rmn[250005][20],rmx[250005][20],val[250005],mn[250005],mx[250005],d[250005];

void add(int x,int c){
	for(;x<=n;x+=(x&(-x))) chkmin(val[x],c);
}

int ask(int x){
	int ret=n+1;
	for(;x;x-=(x&(-x))) chkmin(ret,val[x]);
	return ret;
}

int getmax(int l,int r){
	int k=lg2[r-l+1];
	return a[rmx[l][k]]<a[rmx[r-(1<<k)+1][k]]?rmx[r-(1<<k)+1][k]:rmx[l][k];
}

int getmin(int l,int r){
	int k=lg2[r-l+1];
	return a[rmn[l][k]]>a[rmn[r-(1<<k)+1][k]]?rmn[r-(1<<k)+1][k]:rmn[l][k];
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=2;i<=n;i++) lg2[i]=lg2[i>>1]+1;
		for(int i=1;i<=n;i++) val[i]=n+1;
		for(int i=n;i>=1;i--){
			mn[i]=ask(a[i]);
			add(a[i],i);
		}
		for(int i=1;i<=n;i++) val[i]=n+1;
		for(int i=n;i>=1;i--){
			mx[i]=ask(n-a[i]+1);
			add(n-a[i]+1,i);
		}
		for(int i=1;i<=n;i++) rmn[i][0]=rmx[i][0]=i;
		for(int i=1;(1<<i)<=n;i++){
			for(int j=1;j+(1<<i)-1<=n;j++){
				rmn[j][i]=a[rmn[j][i-1]]<a[rmn[j+(1<<(i-1))][i-1]]?rmn[j][i-1]:rmn[j+(1<<(i-1))][i-1];
				rmx[j][i]=a[rmx[j][i-1]]>a[rmx[j+(1<<(i-1))][i-1]]?rmx[j][i-1]:rmx[j+(1<<(i-1))][i-1];
			}
		}
		for(int i=1;i<=n;i++) d[i]=0x3f3f3f3f;
		d[1]=0;
		for(int i=1;i<=n;i++){
			chkmin(d[getmax(i,mn[i]-1)],d[i]+1);
			chkmin(d[getmin(i,mx[i]-1)],d[i]+1);
		}
		printf("%d\n",d[n]);
	}
	return 0;
}