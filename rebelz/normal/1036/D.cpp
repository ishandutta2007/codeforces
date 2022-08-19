#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m,nowa,nowb,suma,sumb,ans;
ll a[300005],b[300005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	m=readint();
	for(int i=1;i<=m;i++) b[i]=readint();
	for(int i=1;i<=n;i++) suma+=a[i];
	for(int i=1;i<=m;i++) sumb+=b[i];
	if(suma!=sumb) return printf("-1\n"),0;
	ll x=1;
	for(int i=1;i<=n;i++){
		nowa+=a[i];
		while(x<=m&&nowb<nowa) nowb+=b[x++];
		if(nowb==nowa) nowa=nowb=0,ans++;
	}
	cout<<ans<<endl;
	return 0;
}