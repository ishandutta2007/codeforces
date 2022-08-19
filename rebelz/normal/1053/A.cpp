#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,k,x,g,gn,gm,ansx,ansy;

ll gcd(ll x,ll y){
	if(y==0) return x;
	return gcd(y,x%y);
}

int main(){
	n=readint(); m=readint(); k=readint();
	g=gcd(n*m,k); gn=gcd(n,k); gm=gcd(m,k/gn);
	x=n*m/g,k/=g;
	if(k>2) return printf("NO\n"),0;
	if(k==1) x*=2;
	printf("YES\n");
	ansx=n/gn,ansy=m/gm;
	if(k==2);
	else if(n/gn*2<=n) ansx*=2;
	else ansy*=2;
	cout<<0<<' '<<0<<endl<<ansx<<' '<<0<<endl<<0<<' '<<ansy<<endl;
	return 0;
}