#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5;
int n,a[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=n-1;i>=0;i--) a[i]=read();
	for(int i=0;i<20;i++)
		for(int j=0;j<n;j++)
			if(j>>i&1) a[j]^=a[j^(1<<i)];
	reverse(a,a+n+1);
	for(int i=0;i<20;i++) if(n>>i&1)
		for(int j=n;j>(1<<i);j--) a[j]^=a[j-(1<<i)];
	for(int i=1;i<=n;i++) printf("%d ",a[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}