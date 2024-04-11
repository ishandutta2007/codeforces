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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[100005],d[60][100005],f[60][100005],id[60][100005];
pll p[60][100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	for(int i=1;i<=n;i++) for(int j=0;j<60;j++) p[j][i]=mp(a[i]&((1ll<<(j+1))-1),i);
	int ans=0;
	for(int i=1;i<=n;i++) ans-=__builtin_popcountll(a[i]);
	for(int i=0;i<60;i++){
		sort(p[i]+1,p[i]+n+1);
		for(int j=1;j<=n;j++) id[i][p[i][j].se]=j;
	}
	memset(d,0x3f,sizeof(d));
	for(int i=0;i<60;i++){
		for(int j=0;j<=n;j++){
			ll tmp=(p[i][j].fi>>i)&1;
			for(int k=0;k<=1;k++){
				if(k<tmp) continue;
				if(k>tmp){
					if(i) chkmin(d[i][j],k*n+f[i-1][0]);
					else chkmin(d[i][j],1ll*k*n);
				}
				else if(k==tmp){
					if(i) chkmin(d[i][j],k*n+f[i-1][id[i-1][p[i][j].se]]);
					else chkmin(d[i][j],1ll*k*n);
				}
			}
			d[i][j]+=n-j;
		}
		for(int j=n;j>=0;j--){
			if(j==n) f[i][j]=d[i][j];
			else f[i][j]=min(f[i][j+1],d[i][j]);
		}
	}
	ans+=d[59][n];
	printf("%d\n",ans);
	return 0;
}