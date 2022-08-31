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

int n,m,pa,pb;
int a[200005],b[200005];
ll f[200005],g[200005];
int c[1005][1005];

bool check(int x){
//	cout<<"check "<<x<<' '<<a[pa]+b[pb]<<endl;
	if(a[pa]+b[pb]<=x) return true;
	int now=m;
	for(int i=1;i<=n;i++){
		while(now&&a[i]+b[now]<=x) now--;
		g[i]=g[i-1]+now;
	}
	now=n;
	for(int i=1;i<=m;i++){
		while(now&&a[now]+b[i]<=x) now--;
		f[i]=f[i-1]+now;
	}
	for(int i=1;i<=n;i++) g[i]-=1ll*i*m;
	for(int i=1;i<=m;i++) f[i]-=1ll*i*n;
//	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]=a[i]+b[j]>x;
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++) cout<<c[i][j]<<' ';
//		cout<<endl;
//	}
//	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]+=c[i][j-1];
//	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) c[i][j]+=c[i-1][j];
	ll maxa=0,pl=1;
	for(int i=1;i<=m;i++){
		while(pl<n&&i*pl+f[i]+g[pl]<i*(pl+1)+f[i]+g[pl+1]) pl++;
		chkmax(maxa,i*pl+f[i]+g[pl]);
	}
	if(!maxa) return true;
	pl=1;
	for(int i=1;i<pb;i++){
		while(pl<n&&i*pl+f[i]+g[pl]<i*(pl+1)+f[i]+g[pl+1]) pl++;
		if(maxa==i*pl+f[i]+g[pl]) return true;
	}
	pl=1;
	for(int i=1;i<pa;i++){
		while(pl<m&&i*pl+f[pl]+g[i]<i*(pl+1)+f[pl+1]+g[i]) pl++;
		if(maxa==i*pl+f[pl]+g[i]) return true;
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//			if(maxa==c[i][j]-(i*(m-j)-c[i][m]+c[i][j])-((n-i)*j-c[n][j]+c[i][j])-(i*j-c[i][j])&&!(pa<=i&&pb<=j)) return true;
	return false;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	int va=a[1],vb=b[1];
	sort(a+1,a+n+1);
	reverse(a+1,a+n+1);
	sort(b+1,b+m+1);
	reverse(b+1,b+m+1);
	for(int i=1;i<=n;i++) if(a[i]==va) pa=i;
	for(int i=1;i<=m;i++) if(b[i]==vb) pb=i;
	int l=1,r=1000000000,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	printf("%d\n",res);
	return 0;
}