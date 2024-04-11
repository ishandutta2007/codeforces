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

int n,m;
int f[200005],val[200005],x[200005],y[200005],z[200005];

int getf(int x){
	if(x==f[x]) return x;
	int t=getf(f[x]);
	val[x]=val[x]^val[f[x]];
	f[x]=t;
	return t;
}

bool merge(int x,int y,int z){
	int fx=getf(x),fy=getf(y);
	if(fx==fy){
		if((val[x]^val[y])!=z) return false;
		return true;
	}
	f[fx]=fy;
	val[fx]=val[x]^val[y]^z;
	return true;
}

int getv(int x){
	getf(x);
	return val[x];
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) f[i]=i,val[i]=0;
		bool fl=0;
		for(int i=1;i<n;i++){
			x[i]=readint(); y[i]=readint(); z[i]=readint();
			if(z[i]>=0&&!merge(x[i],y[i],__builtin_popcount(z[i])&1)) fl=1;
		}
		int a,b;
		for(int i=1;i<=m;i++){
			a=readint(); b=readint();
			if(!merge(a,b,readint())) fl=1;
		}
		if(fl) printf("NO\n");
		else{
			printf("YES\n");
			for(int i=1;i<n;i++){
				if(z[i]>=0) printf("%d %d %d\n",x[i],y[i],z[i]);
				else printf("%d %d %d\n",x[i],y[i],getv(x[i])^getv(y[i]));
			}
		}
	}
	return 0;
}