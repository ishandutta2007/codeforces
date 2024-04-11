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

int n,m,q;
ll c[605][605],d[605][605],maxa[605][605],l[605][605];

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) c[i][j]=1ll<<60;
	for(int i=1;i<=n;i++) c[i][i]=0;
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint(); z=readint();
		c[x][y]=c[y][x]=z;
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) d[i][j]=c[i][j];
	q=readint();
	for(int i=1;i<=q;i++){
		x=readint(); y=readint(); z=readint();
		l[x][y]=l[y][x]=z;
	}
	for(int k=1;k<=n;k++) for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) chkmin(d[i][j],d[i][k]+d[k][j]);
	for(int u=1;u<=n;u++){
		for(int b=1;b<=n;b++){
			maxa[u][b]=-(1ll<<60);
			for(int v=1;v<=n;v++) chkmax(maxa[u][b],l[u][v]-d[v][b]);
		}
	}
	int ans=0;
	for(int a=1;a<=n;a++){
		for(int b=a+1;b<=n;b++){
			bool fl=0;
			for(int u=1;u<=n;u++) if(d[u][a]+c[a][b]<=maxa[u][b]) fl=1;
			ans+=fl;
		}
	}
	printf("%d\n",ans);
	return 0;
}