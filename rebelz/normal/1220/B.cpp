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

bool chkmin(int &x,int y){return x>y?x=y,1:0;}
bool chkmax(int &x,int y){return x<y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[3005][3005],ans[1005];

ll gcd(ll x,ll y){
	return y==0?x:gcd(y,x%y);
}

int main(){
	n=readint();
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) a[i][j]=readint();
	int g=0;
	for(int i=2;i<=n;i++) g=gcd(g,a[1][i]);
	ans[1]=g;
	for(int i=2;i<=n;i++) ans[i]=a[1][i]/g;
	ll t=a[2][3]/(ans[2]*ans[3]);
	t=sqrt(t);
	ans[1]/=t;
	for(int i=2;i<=n;i++) ans[i]*=t;
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
	printf("\n");
	return 0;
}