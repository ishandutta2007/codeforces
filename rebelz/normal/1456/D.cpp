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

int n;
ll t[5005],x[5005],to[5005],d[5005][2],sum[5005];
int f[5005][5005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) t[i]=readint(),x[i]=readint();
	for(int i=0;i<n;i++) if(abs(x[i+1]-x[i])<=t[i+1]-t[i]) to[i]=1;
	sum[0]=to[0];
	for(int i=1;i<n;i++) sum[i]=sum[i-1]+to[i];
	for(int i=0;i<=n;i++)
		for(int j=i+2;j<=n;j++)
			if(abs(x[j]-x[i])+abs(x[j]-x[i+1])<=t[i+1]-t[i]) f[j][i]=1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			f[i][j]+=f[i][j-1];
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<=n;i++) d[i][1]=0;
	d[0][0]=0;
	for(int i=1;i<=n;i++){
		if(d[i-1][0]<=t[i-1]&&max(t[i-1],d[i-1][0]+abs(x[i]-x[i-1]))<=t[i]) chkmin(d[i][0],max(t[i-1],d[i-1][0]+abs(x[i]-x[i-1])));
		if(d[i-1][1]&&max(t[i-1],(i-1?t[i-2]:0)+abs(x[i]-(i-1?x[i-2]:0)))<=t[i]) chkmin(d[i][0],max(t[i-1],(i-1?t[i-2]:0)+abs(x[i]-(i-1?x[i-2]:0))));
		for(int k=0;k<i-1;k++){
			if(f[i][i-2]-f[i][k]>0&&abs((k?x[k-1]:0)-x[k+1])<=t[k+1]-(k?t[k-1]:0)&&sum[i-2]-sum[k]==i-k-2) d[i][1]|=d[k][1];
			if(max(t[k],(k?t[k-1]:0)+abs((k?x[k-1]:0)-x[i]))+abs(x[i]-x[k+1])<=t[k+1]&&sum[i-2]-sum[k]==i-k-2) d[i][1]|=d[k][1];
			if(f[i][i-2]-f[i][k]>0&&abs(x[k]-x[k+1])<=t[k+1]-d[k][0]&&d[k][0]<=t[k]&&sum[i-2]-sum[k]==i-k-2) d[i][1]=1;
			if(max(t[k],d[k][0]+abs(x[k]-x[i]))+abs(x[i]-x[k+1])<=t[k+1]&&d[k][0]<=t[k]&&sum[i-2]-sum[k]==i-k-2) d[i][1]=1;
			if(abs(x[k]-x[k+1])<=t[k+1]-d[k][0]&&d[k][0]<=t[k]&&t[i-1]+abs(x[i]-x[i-1])<=t[i]&&sum[i-2]-sum[k]==i-k-2) chkmin(d[i][0],t[i-1]+abs(x[i]-x[i-1]));
			if(abs((k?x[k-1]:0)-x[k+1])<=t[k+1]-(k?t[k-1]:0)&&t[i-1]+abs(x[i]-x[i-1])<=t[i]&&sum[i-2]-sum[k]==i-k-2&&d[k][1]) chkmin(d[i][0],t[i-1]+abs(x[i]-x[i-1]));
		}
//		cout<<"test "<<i<<' '<<d[i][0]<<' '<<d[i][1]<<endl;
	}
	bool fl=d[n][1]||d[n][0]<=t[n];
	for(int i=0;i<n;i++){
		if(d[i][0]<=t[i]&&abs(x[i+1]-x[i])<=t[i+1]-d[i][0]&&sum[n-1]-sum[i]==n-i-1) fl=1;
		if(d[i][1]&&abs(x[i+1]-x[i-1])<=t[i+1]-t[i-1]&&sum[n-1]-sum[i]==n-i-1) fl=1;
	}
	if(fl) printf("YES\n");
	else printf("NO\n");
	return 0;
}