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

ll n;
ll a[100005],r[100005],s[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	if(n==1){
		printf("1 1\n%d\n",-a[1]);
		printf("1 1\n0\n");
		printf("1 1\n0\n");
		return 0;
	}
	ll tx=n-2,ty=n-1;
	for(int i=1;i<=n;i++){
		ll t1=tx*a[i],t2=ty*a[i],k=min(t1/(n-1),t2/n);
		t1-=k*(n-1),t2-=k*n;
		r[i]=t1*n,s[i]=t2*(n-1);
	}
	printf("1 %d\n",n);
	for(int i=1;i<=n;i++) printf("%lld ",r[i]);
	printf("\n");
	printf("1 %d\n",n-1);
	for(int i=1;i<=n-1;i++) printf("%lld ",-s[i]);
	printf("\n");
	printf("2 %d\n",n);
	for(int i=2;i<=n-1;i++) printf("0 ");
	printf("%lld \n",-s[n]);
	return 0;
}