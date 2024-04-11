#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[200005],b[200005];

int main(){
	n=readint();
	for(int i=1;i<=n/2;i++) b[i]=readint();
	ll fir=0,lst=1ll<<60;
	for(int i=1;i<=n/2;i++){
		if(b[i]-fir>lst) a[i]=b[i]-lst,a[n-i+1]=lst;
		else a[i]=fir,a[n-i+1]=b[i]-fir;
		fir=a[i],lst=a[n-i+1];
	}
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
	printf("\n");
	return 0;
}