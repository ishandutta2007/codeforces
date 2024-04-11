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

int n,m,cys,cnt[2];
int f[20005],lb[20005];
ll c[2][505][505];
char a[105][105];

int id(int x,int y){return (x-1)*(m+1)+y;}
int getf(int x){return x==f[x]?x:f[x]=getf(f[x]);}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

bool merge(int x,int y){
	int fx=getf(x),fy=getf(y);
	return fx==fy?0:f[fx]=fy,1;
}

ll gauss(int tp){
	cnt[tp]--;
	ll ret=1;
	for(int i=1;i<=cnt[tp];i++){
		int p=0;
		for(int j=cnt[tp];j>=i;j--) if(c[tp][j][i]) p=j;
		if(!p) return 0;
		if(p!=i) ret=cys-ret;
		for(int j=i;j<=cnt[tp];j++) swap(c[tp][p][j],c[tp][i][j]);
		for(int j=i+1;j<=cnt[tp];j++){
			ll tmp=cys-c[tp][j][i]*qpow(c[tp][i][i],cys-2)%cys;
			for(int k=cnt[tp];k>=i;k--) c[tp][j][k]=(c[tp][j][k]+tmp*c[tp][i][k])%cys;
		}
		ret=ret*c[tp][i][i]%cys;
	}
	return ret;
}

int main(){
	n=readint(); m=readint(); cys=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) f[id(i,j)]=id(i,j);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='/'&&!merge(id(i,j+1),id(i+1,j))) return printf("0\n"),0;
			else if(a[i][j]=='\\'&&!merge(id(i,j),id(i+1,j+1))) return printf("0\n"),0;
		}
	}
	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) if(getf(id(i,j))==id(i,j)) lb[id(i,j)]=++cnt[(i+j)&1];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i][j]=='*'){
				if(getf(id(i,j+1))!=getf(id(i+1,j))){
					int fx=getf(id(i,j+1)),fy=getf(id(i+1,j));
					c[(i+j+1)&1][lb[fx]][lb[fx]]++,c[(i+j+1)&1][lb[fy]][lb[fy]]++,c[(i+j+1)&1][lb[fx]][lb[fy]]--,c[(i+j+1)&1][lb[fy]][lb[fx]]--;
				}
				if(getf(id(i,j))!=getf(id(i+1,j+1))){
					int fx=getf(id(i,j)),fy=getf(id(i+1,j+1));
					c[(i+j)&1][lb[fx]][lb[fx]]++,c[(i+j)&1][lb[fy]][lb[fy]]++,c[(i+j)&1][lb[fx]][lb[fy]]--,c[(i+j)&1][lb[fy]][lb[fx]]--;
				}
			}
		}
	}
	for(int i=0;i<=1;i++) for(int j=1;j<=cnt[i];j++) for(int k=1;k<=cnt[i];k++) c[i][j][k]=(c[i][j][k]%cys+cys)%cys;
	printf("%lld\n",((gauss(0)+gauss(1))%cys+cys)%cys);
	return 0;
}