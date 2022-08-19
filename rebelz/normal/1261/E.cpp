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

int n,cnt;
int ans[1005][1005],tmp[1005];
pii a[1005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i].fi=readint(),a[i].se=i;
	sort(a+1,a+n+1); reverse(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=i+a[i].fi;j++) ans[j][i]=1;
		for(int j=i+1;j<=n;j++) if(a[j].fi==n-i+1) a[j].fi--,ans[i][j]=1;
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=n;j++) tmp[a[j].se]=ans[i][j];
		for(int j=1;j<=n;j++) ans[i][j]=tmp[j];
		bool fl=0;
		for(int j=1;j<=n;j++) if(ans[i][j]) fl=1;
		cnt+=fl;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=n+1;i++){
		bool fl=0;
		for(int j=1;j<=n;j++) if(ans[i][j]) fl=1;
		if(fl){
			for(int j=1;j<=n;j++) printf("%d",ans[i][j]);
			printf("\n");
		}
	}
	return 0;
}