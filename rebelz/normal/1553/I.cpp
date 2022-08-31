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

const int cys=998244353;
int n,m;
int a[100005],b[100005],d[2][100005];

int mod(int x){return x>=cys?x-cys:x;}
void add(int &x,int y){x=mod(x+y);}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	bool fl=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=i+a[i]-1;j++) if(a[j]!=a[i]) fl=1;
		i+=a[i]-1;
		b[++m]=a[i]>1;
	}
	if(fl) return printf("0\n"),0;
	d[b[1]][0]=1;
	for(int i=1;i<m;i++){
		if(b[i+1]){
			for(int j=i-1;j>=0;j--){
				add(d[1][j+1],mod(d[1][j]<<1));
				add(d[1][j+1],d[0][j]);
				add(d[1][j],d[0][j]);
				d[0][j]=0;
			}
		}
		else{
			for(int j=i-1;j>=0;j--){
				add(d[0][j+1],mod(d[1][j]<<1));
				add(d[0][j+1],d[0][j]);
				add(d[1][j],d[0][j]);
				d[0][j]=0;
			}
		}
	}
	ll ans=0,now=1;
	for(int i=1;i<=m;i++){
		now=now*i%cys;
		ll tmp=(d[0][i-1]+2ll*d[1][i-1])%cys*now%cys;
		if((m-i)&1) ans=mod(ans+cys-tmp);
		else ans=mod(ans+tmp);
	}
	printf("%lld\n",ans);
	return 0;
}