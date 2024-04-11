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

int main(){
	n=readint(); m=readint();
	if(n==1){
		if(m==1) return printf("0\n"),0;
		for(int i=1;i<=m;i++) printf("%d ",i+1);
		printf("\n");
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) printf("%d ",j==1?i+1:(i+1)*(j+n));
		printf("\n");
	}
	return 0;
}