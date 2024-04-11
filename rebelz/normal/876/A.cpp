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

int n,a,b,c;

int main(){
	n=readint(); a=readint(); b=readint(); c=readint();
	if(n==1) printf("0\n");
	else if(a<=b&&a<=c) printf("%d\n",(n-1)*a);
	else if(b<=c&&b<=a) printf("%d\n",(n-1)*b);
	else printf("%d\n",(n-2)*c+min(a,b));
	return 0;
}