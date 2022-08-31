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
int a[3005],d[3005][3005],now[3005],nxt[3005];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<=n;i++) now[i]=n+1;
		n=unique(a+1,a+n+1)-a-1;
		for(int i=1;i<=n+1;i++) d[i][i-1]=0;
		for(int i=1;i<=n;i++) d[i][i]=0;
		for(int i=n;i>=1;i--){
			nxt[i]=now[a[i]];
			now[a[i]]=i;
		}
		for(int i=2;i<=n;i++){
			for(int j=1;j+i-1<=n;j++){
				int l=j,r=j+i-1;
				if(a[l]!=a[r]){
					d[l][r]=min(d[l+1][r]+1,d[l][r-1]+1);
					for(int k=nxt[l];k<r;k=nxt[k]) chkmin(d[l][r],d[l][k]+d[k+1][r]+1);
				}
				else{
					if(l+1==r) d[l][r]=0;
					else d[l][r]=d[l+1][r-1]+1;
					for(int k=nxt[l];k<r;k=nxt[k]) chkmin(d[l][r],d[l][k]+d[k][r]);
				}
			}
		}
		printf("%d\n",d[1][n]);
	}
	return 0;
}