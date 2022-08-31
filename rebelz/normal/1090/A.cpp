#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,s;
int d[200005],maxa[200005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++){
		d[i]=readint();
		for(int j=1;j<=d[i];j++) maxa[i]=max(maxa[i],readint());
		s=max(s,maxa[i]);
	}
	ll ans=0;
	for(int i=1;i<=n;i++) ans+=1ll*d[i]*(s-maxa[i]);
	printf("%lld\n",ans);
	return 0;
}