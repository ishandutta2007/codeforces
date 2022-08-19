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

int n,q,x,y;
int a[2][100005];

int main(){
	n=readint(); q=readint();
	int now=0;
	for(int i=1;i<=q;i++){
		x=readint()-1; y=readint();
		now-=a[x][y]&a[x^1][y];
		now-=a[x][y]&a[x^1][y-1];
		now-=a[x][y]&a[x^1][y+1];
		a[x][y]^=1;
		now+=a[x][y]&a[x^1][y];
		now+=a[x][y]&a[x^1][y-1];
		now+=a[x][y]&a[x^1][y+1];
		if(now) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}