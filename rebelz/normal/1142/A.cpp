#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,k,a,b,mina=1ll<<60
,maxa;

ll gcd(ll x,ll y){return y==0?x:gcd(y,x%y);}

int main(){
	n=readint(); k=readint(); a=readint(); b=readint();
	for(int i=1;i<=n;i++){
		for(int i1=0;i1<=1;i1++){
			for(int i2=0;i2<=1;i2++){
				ll x=i*k+(i1==0?-1:1)*a+(i2==0?-1:1)*b;
				if(x<=0) continue;
				ll g=gcd(x,k*n);
				mina=min(mina,n*k/g); maxa=max(maxa,n*k/g);
			}
		}
	}
	cout<<mina<<' '<<maxa<<endl;
	return 0;
}