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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,q; ll k;
ll a[30][30],d[30][30];

int main(){
	n=readint();
	for(int i=2;i<=n+n;i++){
		for(int j=max(1,i-n),fl=0;j<=min(n,i-1);j++,fl^=1){
			if(!fl) a[j][i-j]=1ll<<(i-2),d[j][i-j-1]=1;
			else a[j][i-j]=1ll<<(i-3),d[j][i-j-1]=0;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++) printf("%lld ",a[i][j]);
		printf("\n");
		fflush(stdout);
	}
	q=readint();
	while(q--){
		k=readint();
		int tx=1,ty=1;
		for(int i=0;i<(n+n-1);i++){
			printf("%d %d\n",tx,ty);
			fflush(stdout);
			if(k&(1ll<<i)){
				if(d[tx][ty]) ty++;
				else tx++;
			}
			else{
				if(d[tx][ty]) tx++;
				else ty++;
			}
		}
	}
	return 0;
}