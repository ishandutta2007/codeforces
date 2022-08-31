#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m;
ll a[100005],b[100005],s[100005];

int main(){
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++) b[i]=a[i+1]-a[i];
	sort(b+1,b+n);
	for(int i=1;i<n;i++) s[i]=s[i-1]+b[i];
	m=readint();
	ll x,y;
	for(int i=1;i<=m;i++){
		x=readint(); y=readint();
		ll tmp=upper_bound(b+1,b+n,y-x+1)-b;
		tmp--;
		printf("%lld ",(y-x+1)*(n-tmp)+s[tmp]);
	}
	return 0;
}