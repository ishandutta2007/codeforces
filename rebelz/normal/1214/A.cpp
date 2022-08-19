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

int n,a,b;
int d[1000005];

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

int main(){
	n=readint(); a=readint(); b=readint()*5;
	d[0]=1;
	for(int i=1;i<=a*b;i++){
		if(i-a>=0) d[i]|=d[i-a];
		if(i-b>=0) d[i]|=d[i-b];
	}
	int g=gcd(a,b);
	if(n>a*b) cout<<n%g<<endl;
	else{
		for(int i=n;i>=0;i--) if(d[i]) return printf("%d\n",n-i),0;
	}
	return 0;
}