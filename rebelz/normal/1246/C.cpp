#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int cys=1000000007;
int n,m;
char a[2005][2005];
ll sx[2005][2005],sy[2005][2005],tx[4005][4005],ty[4005][4005],d[2005][2005][2],s[2005][2005][2];

ll mod(ll x){return x>=cys?x-cys:x;}

ll getans(ll x1,ll x2,ll y1,ll y2,ll k){
	return (cys+cys+s[x2][y2][k]-s[x2][y1-1][k]-s[x1-1][y2][k]+s[x1-1][y1-1][k])%cys;
}

int main(){
	n=readint(); m=readint();
	for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
	for(int i=1;i<=n;i++) for(int j=m;j>=1;j--) sx[i][j]=sx[i][j+1]+(a[i][j]=='.');
	for(int i=1;i<=m;i++) for(int j=n;j>=1;j--) sy[j][i]=sy[j+1][i]+(a[j][i]=='.');
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(tx[i][j+sx[i][j]-1+(a[i][j]=='R')]) continue;
			tx[i][j+sx[i][j]-1+(a[i][j]=='R')]=j;
		}
		tx[i][0]=1;
		for(int j=2*m;j>=1;j--) if(!tx[i][j]) tx[i][j]=tx[i][j+1];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(ty[i][j+sy[j][i]-1+(a[j][i]=='R')]) continue;
			ty[i][j+sy[j][i]-1+(a[j][i]=='R')]=j;
		}
		ty[i][0]=1;
		for(int j=2*n;j>=1;j--) if(!ty[i][j]) ty[i][j]=ty[i][j+1];
	}
	d[1][1][0]=d[1][1][1]=s[1][1][0]=s[1][1][1]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(i==1&&j==1) continue;
			if(j>1&&sy[i][j]) d[i][j][0]=getans(i,i,tx[i][j],j-1,1);
			if(i>1&&sx[i][j]) d[i][j][1]=getans(ty[j][i],i-1,j,j,0);
			s[i][j][0]=(s[i-1][j][0]+s[i][j-1][0]+cys-s[i-1][j-1][0]+d[i][j][0])%cys;
			s[i][j][1]=(s[i-1][j][1]+s[i][j-1][1]+cys-s[i-1][j-1][1]+d[i][j][1])%cys;
		}
	}
	if(n==1&&m==1) return printf("1\n"),0;
	printf("%lld\n",mod(d[n][m][0]+d[n][m][1]));
	return 0;
}