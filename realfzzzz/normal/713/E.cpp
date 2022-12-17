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
const int maxn=1e5+5;
int n,m,a[maxn],a2[maxn],f[maxn];
const int inf=2e9;
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	m=read();
	n=read();
	if(n==1){
		printf("%d\n",m-1);
		return 0;
	}
	for(int i=0;i<n;i++) a2[i]=read()-1;
	int mx=1;
	for(int i=2;i<n;i++)
		if(a2[i]-a2[i-1]>a2[mx]-a2[mx-1]) mx=i;
	if(a2[0]-a2[n-1]+m>a2[mx]-a2[mx-1]) mx=0;
	for(int i=mx;i<n;i++) a[i-mx]=a2[i]-a2[mx];
	for(int i=0;i<mx;i++) a[i+n-mx]=a2[i]-a2[mx]+m;
	int l=(m-a[n-1])/2,r=m-a[n-1]-1;
	while(l<r){
		int mid=l+(r-l)/2;
		auto dp=[mid](){
			for(int i=2;i<n;i++)
				if(f[i-1]>=a[i]-1) f[i]=a[i]+mid;
				else if(f[i-2]>=a[i]-mid-1)
					f[i]=max(a[i-1]+mid,a[i]);
				else if(f[i-1]>=a[i]-mid-1) f[i]=a[i];
				else f[i]=-inf;
		};
		f[0]=0;
		if(a[1]==1) f[1]=mid+1;
		else if(a[1]<=mid+1) f[1]=a[1];
		else f[1]=-inf;
		dp();
		bool flag=f[n-1]>=m-mid-1;
		f[0]=mid;
		f[1]=max(a[1],mid);
		dp();
		flag|=f[n-1]>=min(a[1]+m-mid,m)-1;
		if(flag) r=mid;
		else l=mid+1;
	}
	printf("%d\n",r);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}