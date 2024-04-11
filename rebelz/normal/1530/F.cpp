#include<bits/stdc++.h>

#define y1 dmytxdy
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

const int cys=31607;
int n;
int a[25][25],b[25][25],th[8400000],tmp[2100000],now[8400000],lg2[2100000];

int mod(int x){return x>=cys?x-cys:x;}

int qpow(int x,int p){
	int ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	n=readint();
	for(int i=0;i<n;i++) for(int j=0;j<n;j++) a[i][j]=readint()*qpow(10000,cys-2)%cys;
	for(int i=2;i<(1<<n);i++) lg2[i]=lg2[i>>1]+1;
	for(int i=0;i<(1<<(n+2));i++) now[i]=1;
	for(int i=0;i<n;i++){
		tmp[0]=1;
		for(int j=0;j<n;j++) tmp[0]=tmp[0]*mod(1+cys-a[i][j])%cys;
		for(int j=0;j<n;j++) b[i][j]=qpow(mod(1+cys-a[i][j]),cys-2)*a[i][j]%cys;
		for(int j=1;j<(1<<n);j++){
			int t=lg2[j&(-j)];
			tmp[j]=tmp[j^(1<<t)]*b[i][t]%cys;
		}
		for(int j=0;j<(1<<(n+2));j++) th[j]=0;
		for(int j=0;j<(1<<n)-1;j++) th[j^(((j>>i)&1)<<n)^(((j>>(n-i-1))&1)<<(n+1))]=tmp[j];
		for(int j=1;j<(1<<(n+2));j<<=1)
			for(int k=0;k<(1<<(n+2));k+=(j<<1))
				for(int l=k;l<k+j;l++)
					th[l]=mod(th[l]+th[l+j]);
		for(int j=0;j<(1<<(n+2));j++) now[j]=now[j]*th[j]%cys;
	}
	for(int j=0;j<n+2;j++)
		for(int k=0;k<(1<<(n+2));k++)
			if(!((k>>j)&1)) now[k]=mod(now[k]+cys-now[k^(1<<j)]);
	printf("%d\n",mod(1+cys-now[0]));
	return 0;
}