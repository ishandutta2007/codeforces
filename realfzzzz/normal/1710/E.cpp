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
const int maxn=2e5+5;
int n,m,a[maxn],b[maxn],c[maxn],d[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++) b[i]=read();
	int x=a[1],y=b[1];
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	x=lower_bound(a+1,a+n+1,x)-a;
	y=lower_bound(b+1,b+m+1,y)-b;
	int l=2,r=a[x]+b[y];
	while(l<r){
		int mid=(l+r+1)/2;
		c[0]=m;
		for(int i=1;i<=n;i++){
			c[i]=c[i-1];
			while(c[i]&&a[i]+b[c[i]]>=mid) c[i]--;
		}
		d[0]=n;
		for(int i=1;i<=m;i++){
			d[i]=d[i-1];
			while(d[i]&&b[i]+a[d[i]]>=mid) d[i]--;
		}
		ll s=0;
		for(int i=1;i<=n;i++) s+=m-c[i];
		int p=0;
		ll mx=s;
		for(int i=1;i<=n;i++){
			s+=c[i]+p-m;
			while(p<m&&d[p+1]+i>n){
				p++;
				s+=d[p]+i-n;
			}
			mx=max(mx,s);
		}
		s=-1;
		for(int i=1;i<=n;i++) s+=m-c[i];
		p=0;
		ll mx2=s;
		for(int i=1;i<=n;i++){
			s+=c[i]+p-m+(i==x&&p<y);
			while(p<m&&d[p+1]+i+(p+1==y&&i<x)>n){
				p++;
				s+=d[p]+i-n+(p==y&&i<x);
			}
			mx2=max(mx2,s);
		}
		if(mx==mx2) r=mid-1;
		else l=mid;
	}
	printf("%d\n",r);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}