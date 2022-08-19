#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int a[100005],b[100005];

int main(){
	n=readint(); m=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	for(int i=1;i<=n-1;i++) b[i]=a[i+1]-a[i]-1;
	ll ans=a[n]-a[1]+1;
	sort(b+1,b+n);
	for(int i=n-1;i>=n-k+1;i--) ans-=b[i];
	cout<<ans<<endl;
	return 0;
}