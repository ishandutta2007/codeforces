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

int n,m;
int a[100005],l[200005],r[200005];

int main(){
	n=readint(); m=readint();
	if(n==1&&m>0) return printf("0\n"),0;
	for(int i=1;i<=m;i++) a[i]=readint();
	int pl=0,pr=m+1;
	for(int i=1;i<=n;i++) l[i+pl]=r[i+pr]=i;
	for(int i=m;i>=0;i--){
		pl++;
		l[n+pl]=l[n+pl-1],l[pl]=0;
		if(a[i]) l[a[i]+pl]=l[a[i]+pl-1];
		pr--;
		r[pr+1]=r[pr+2],r[n+pr+1]=0;
		if(a[i]) r[a[i]+pr]=r[a[i]+pr+1];
	}
	ll res=0;
	for(int i=1;i<=n;i++) res+=l[i+pl]-r[i+pr]+1;
	printf("%lld\n",res);
	return 0;
}