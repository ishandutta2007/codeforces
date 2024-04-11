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

int n,k; ll ans;
int b[3005];
ll a[3005][3005],now[3005];

void solve(int l,int r){
	if(l==r){
		for(int i=0;i<=b[l];i++) chkmax(ans,a[l][i]+now[k-i]);
		return;
	}
	int mid=(l+r)/2;
	ll tmp[3005];
	for(int i=0;i<=k;i++) tmp[i]=now[i];
	for(int i=l;i<=mid;i++)
		for(int j=k;j>=b[i];j--)
			chkmax(now[j],now[j-b[i]]+a[i][b[i]]);
	solve(mid+1,r);
	for(int i=0;i<=k;i++) now[i]=tmp[i];
	for(int i=mid+1;i<=r;i++)
		for(int j=k;j>=b[i];j--)
			chkmax(now[j],now[j-b[i]]+a[i][b[i]]);
	solve(l,mid);
}

int main(){
	n=readint(); k=readint();
	int x,y;
	for(int i=1;i<=n;i++){
		x=readint();
		while(x--){
			y=readint();
			if(b[i]<k) a[i][++b[i]]=y;
		}
		for(int j=1;j<=b[i];j++) a[i][j]+=a[i][j-1];
	}
	solve(1,n);
	printf("%lld\n",ans);
	return 0;
}