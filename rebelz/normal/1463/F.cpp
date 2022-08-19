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

int n,x,y;
int d[4200000],f[4200000];

int main(){
	n=readint(); x=readint(); y=readint();
	if(x>y) swap(x,y);
	int r=n%(x+y);
	for(int i=1;i<=x+y;i++){
		int val=0;
		if(i<=r) val=n/(x+y)+1;
		else val=n/(x+y);
		for(int j=0;j<(1<<y);j++){
			if(!((j>>(x-1))&1)&&!((j>>(y-1))&1)) chkmax(f[((j<<1)^1)&((1<<y)-1)],d[j]+val);
			chkmax(f[(j<<1)&((1<<y)-1)],d[j]);
		}
		for(int j=0;j<(1<<y);j++) d[j]=f[j],f[j]=0;
	}
	int ans=0;
	for(int i=0;i<(1<<y);i++) chkmax(ans,d[i]);
	printf("%d\n",ans);
	return 0;
}