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
char a[65][65];

int main(){
	int T=readint();
	while(T--){
		n=readint(); m=readint();
		for(int i=1;i<=n;i++) scanf("%s",a[i]+1);
		int ans=1<<30;
		for(int i=1;i<=n;i++){
			bool fl=1;
			for(int j=1;j<=m;j++) if(a[i][j]=='P') fl=0;
			if(fl){
				if(i==1||i==n) chkmin(ans,1);
				else chkmin(ans,2);
			}
		}
		for(int i=1;i<=m;i++){
			bool fl=1;
			for(int j=1;j<=n;j++) if(a[j][i]=='P') fl=0;
			if(fl){
				if(i==1||i==m) chkmin(ans,1);
				else chkmin(ans,2);
			}
		}
		if(a[1][1]=='A'||a[1][m]=='A'||a[n][1]=='A'||a[n][m]=='A') chkmin(ans,2);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i][j]=='A'&&(i==1||i==n||j==1||j==m)) chkmin(ans,3);
				if(a[i][j]=='A'&&i!=1&&i!=n&&j!=1&&j!=m) chkmin(ans,4);
			}
		}
		bool fl=1;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(a[i][j]=='P') fl=0;
		if(fl) chkmin(ans,0);
		if(ans==(1<<30)) printf("MORTAL\n");
		else printf("%d\n",ans);
	}
	return 0;
}